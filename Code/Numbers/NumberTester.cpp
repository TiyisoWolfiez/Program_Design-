#include "NumberTester.h"
int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester(){
    this->numAliveObjects+=1;
}
NumberTester::~NumberTester(){
    this->numAliveObjects-=1;
}
bool NumberTester::evaluate(int val){
    // This is a pure virtual function.
    return true;
}
NumberTester* NumberTester::clone(){
    // This is a pure virtual function.
    return NULL;
}
int NumberTester::getNumAliveObjects(){
    return numAliveObjects;
}
