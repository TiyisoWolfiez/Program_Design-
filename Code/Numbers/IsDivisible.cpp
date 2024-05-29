#include "IsDivisible.h"
int IsDivisible::numAliveObjects = 0;
IsDivisible::IsDivisible(int Value): ValueDependantTester(Value){
    this->numAliveObjects+=1;
}
IsDivisible::~IsDivisible(){
    this->numAliveObjects-=1;
}
