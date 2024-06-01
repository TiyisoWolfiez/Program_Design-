//The Cargo implementation file
#include "Cargo.h"
using namespace std;

Cargo::Cargo(double weight, double value){
    Cargo::value = value * weight;
    Cargo::weight = weight;
}
double Cargo::getWeight() const{
    return Cargo::weight;
}
