#include "IsSmaller.h"
int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int Value): ValueDependantTester(Value){
    this->numAliveObjects+=1;
}
