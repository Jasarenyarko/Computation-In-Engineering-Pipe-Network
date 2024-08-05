#include "Tube.hpp"

using namespace cie::pipenetwork;

Tube::Tube(Node* node1, Node *node2, double diameter)
{
    node1_ = node1;
    node2_ = node2;
    diameter_ = diameter;
}




const Node* Tube::node1() const
{
    return node1_;
}


const Node* Tube::node2() const 
{
    return  node2_;
}

double Tube ::diameter() const
{
    return diameter_;
}



double Tube:: length() const 
{
    double node1x = node1_->x();
    double node1y = node1_->y();
    double node2x = node2_->x();
    double node2y = node2_->y();

    double nodeX_diff = node1x - node2x;
    double nodeY_diff = node1y - node2y;
    
    return sqrt(pow(nodeX_diff,2)+ pow(nodeY_diff,2));
}

double Tube::permeability() const
{   
    const double pi = M_PI;
    const double gravity  = 9.81;
    const double viscosity = 1e-6;
    return ( pi * gravity * pow( diameter(), 4 ) / ( 128 * viscosity * length() ) );
}
