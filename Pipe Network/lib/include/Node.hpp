#pragma once
#include "iostream"
#include "linalg.hpp"

using namespace std; 


namespace cie
{
namespace pipenetwork
{

using namespace cie :: pipenetwork;

class Node
{

    private:
    double x_;
    double y_;
    double flow_;
    int id_;

    public:
    Node(double x, double y, double flow, int id );
    double x() const;
    double y() const ;
    double flow()const ;
    int id()const;

   

};

}
}