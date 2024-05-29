#include "TesterInterface.h"
#include <iostream>
TesterInterface::TesterInterface(int maxNumTests)
{
    this->maxNumTesters = this->currNumTesters = 0;
    this->testers = new NumberTester*[0];
    if(maxNumTests>=1)
    {
        this->maxNumTesters = maxNumTests;
        this->testers = new NumberTester*[maxNumTests];
        for(int i=0; i<maxNumTests; i+=1)
        {
            this->testers[i] = NULL;
        }
    }
}
