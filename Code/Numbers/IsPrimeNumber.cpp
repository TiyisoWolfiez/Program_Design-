#include "IsPrimeNumber.h"
int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber(){
    this->numAliveObjects+=1;
}
