#include "ValueIndependantTester.h"
int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester(){
    this->numAliveObjects+=1;
}
