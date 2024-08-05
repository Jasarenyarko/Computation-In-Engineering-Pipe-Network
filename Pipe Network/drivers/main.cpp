#include "linalg.hpp"
#include "Node.hpp"
#include "PipeNetwork.hpp"
#include "Tube.hpp"

using namespace std;
using namespace cie::pipenetwork;


int main()
{

string inputName;
string outputName;
bool answer;

cout << "Input path of file to read: ";
cin >> inputName;

PipeNetwork network = {inputName};
vector<double> fluxes = network.computeFluxes();
network.printFluxes();

cout << "\nDo you want to save results to a File: "<< endl;
cout <<"0. No"<< endl;
cout <<"1. Yes" << endl;
cout << "Select: ";

cin >> answer;

if (answer)
{   
    cout << "Input name of output filename: " << endl;
    cin >> outputName;
    network.printFluxestoFile(outputName);
    cout << "File Saved!\n"<<endl;
}


cout << endl<<"Program closed";


}