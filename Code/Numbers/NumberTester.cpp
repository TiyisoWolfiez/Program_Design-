#include "NumberTester.h"
int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester(){
    this->numAliveObjects+=1;
}
