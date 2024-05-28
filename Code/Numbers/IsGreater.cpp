#include "IsGreater.h"
int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int Value): ValueDependantTester(Value){
    this->numAliveObjects+=1;
}
