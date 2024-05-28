#include "IsGreater.h"
int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int Value): ValueDependantTester(Value){
    this->numAliveObjects+=1;
}
IsGreater::~IsGreater(){
    this->numAliveObjects-=1;
}
bool IsGreater::evaluate(int val){
    bool Temp = (val>this->value);
    return Temp;
}
