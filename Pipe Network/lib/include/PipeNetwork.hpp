#pragma once
#include "vector"
#include "Tube.hpp"
#include "Node.hpp"
#include "memory"
#include "linalg.hpp"
#include "string"
#include "fstream"

using namespace std;

namespace cie
{
namespace pipenetwork
{

using namespace cie::pipenetwork;

class PipeNetwork
{
    private:
    vector <Tube> tubelist;
    vector <Node> nodelist;
    int numberOfNodes;
    int numberOfTubes;

    public:
    PipeNetwork(const string& FileName);
    ~PipeNetwork();
    vector<double> computeFluxes() const;
    void printFluxes() const;
    void printFluxestoFile(const string& FileName) const;     
};

}
}