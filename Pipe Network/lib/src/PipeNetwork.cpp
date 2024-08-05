#include "PipeNetwork.hpp"

using namespace cie::pipenetwork;

PipeNetwork::PipeNetwork(const string& FileName)
 {
    ifstream infile(FileName);

    infile >> numberOfNodes;
    infile >> numberOfTubes;

    nodelist.reserve(numberOfNodes);
    tubelist.reserve(numberOfTubes);

   
    for (int i = 0; i < numberOfNodes; ++i)
     {
        double x, y, flow;
        infile >> x >> y >> flow;
        nodelist.emplace_back(x, y, flow, i);
    }

   
    for (int i = 0; i < numberOfTubes; ++i) 
    {
        int node1Id, node2Id;
        double diameter;
        infile >> node1Id >> node2Id >> diameter;
        tubelist.emplace_back(&nodelist[node1Id], &nodelist[node2Id], diameter);
    }
 }

PipeNetwork :: ~PipeNetwork()
{

}


vector<double> PipeNetwork :: computeFluxes() const
{


cie ::linalg ::Matrix B (numberOfNodes,numberOfNodes);


for (int i = 0;i < numberOfTubes; i++)
{
    int id1 = tubelist[i].node1()->id();
    int id2 = tubelist[i].node2()->id();

    double B_i = tubelist[i].permeability();

    B(id1,id1) += B_i;
    B(id2,id2) += B_i;
    B(id1,id2) -= B_i;
    B(id2,id1) -= B_i;
}


vector<double> loadVector_Q;
for (int i = 0;i < numberOfNodes; i++)
{

loadVector_Q.push_back(-nodelist[i].flow());


}

for (int i = 1; i < numberOfNodes;i++)
{

 B(i,0) = 0;
 B(0,i) = 0;

}

B(0,0) = 1;
loadVector_Q[0] = 0;


auto head_vector = cie :: linalg :: solve(B,loadVector_Q);

vector<double> fluxes_q(numberOfTubes);

for (int i = 0;i < numberOfTubes; i++)
{
   
    int id1 = tubelist[i].node1()->id();
    int id2 = tubelist[i].node2()->id();

   double h1 = head_vector[id1];
   double h2 = head_vector[id2];

   double B_i = tubelist[i].permeability();

   fluxes_q[i] = B_i * (h1-h2);
}


return fluxes_q;


}


 void PipeNetwork::printFluxes() const
{

for (int i = 0; i < numberOfTubes;i++)
{
    cout<<"Tube "<< i+1 << " Flux: " << computeFluxes()[i]<<endl;
}

}


void PipeNetwork::printFluxestoFile(const string& FileName) const
{

    ofstream outFile(FileName);

    if(!outFile.is_open())
    {
        cout << "Error! Unable to open File"<<endl;
        return;
    }

      for (int i = 0; i < numberOfTubes; i++)
    {
        outFile << "Tube " << i + 1 << " Flux: " << computeFluxes()[i] << endl;
    }


    outFile.close();

}