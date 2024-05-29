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
TesterInterface::TesterInterface(TesterInterface& other)
{
    this->maxNumTesters = other.maxNumTesters;
    this->currNumTesters = other.currNumTesters;
    this->testers = new NumberTester*[other.maxNumTesters];
    int i=0;
    for(; i<this->maxNumTesters; i+=1)
    {
        if(other.testers[i]!=NULL){
            this->testers[i] = other.testers[i]->clone();
        }
        else{
            this->testers[i] = NULL;
        }
    }
}
TesterInterface::TesterInterface(TesterInterface* other)
{
    if(other)
    {
        this->maxNumTesters = other->maxNumTesters;
        this->currNumTesters = other->currNumTesters;
        this->testers = new NumberTester*[other->maxNumTesters];
        int i=0;
        for(; i<this->maxNumTesters; i+=1)
        {
            if(other->testers[i]!=NULL){
                this->testers[i] = other->testers[i]->clone();
            }
            else{
                this->testers[i] = NULL;
            }
        }
    }
    else
    {
        this->maxNumTesters = this->currNumTesters = 0;
        this->testers = new NumberTester*[this->maxNumTesters];
    }
}
int TesterInterface::getCurrNumTesters() const
{
    return this->currNumTesters;
}
int TesterInterface::getMaxNumTesters() const
{
    return this->maxNumTesters;
}
TesterInterface::~TesterInterface()
{
    int i=0;
    for(; i<this->maxNumTesters; i+=1)
    {
        if(this->testers[i]!=NULL){
            delete this->testers[i];
            this->testers[i] = NULL;
        }
    }
    if(testers!=NULL){
        delete [] testers;
        testers = NULL;
    }
    this->currNumTesters = this->maxNumTesters = 0;
}
