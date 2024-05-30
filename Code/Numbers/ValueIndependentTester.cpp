#include "ValueIndependantTester.h"
int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester(){
    this->numAliveObjects+=1;
}
ValueIndependantTester::~ValueIndependantTester(){
    this->numAliveObjects-=1;
}
bool ValueIndependantTester::evaluate(int val){
    // This is a pure virtual function.
    return true;
}
