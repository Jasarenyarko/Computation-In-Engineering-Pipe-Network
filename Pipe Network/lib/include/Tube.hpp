#pragma once
#include "Node.hpp"
#include "math.h"
#include "memory"

namespace cie
{
namespace pipenetwork
{

using namespace cie::pipenetwork;

class Tube
{


private:
    Node* node1_;
    Node* node2_; 
    double diameter_;
    

public:
Tube (Node* node1, Node* node2, double diameter);
const Node* node1() const;
const Node* node2() const;
double length() const ;
double permeability() const;
double diameter() const;


};

}
}