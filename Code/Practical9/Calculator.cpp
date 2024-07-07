#include "Calculator.h"
#include <cstddef>


template <typename T>
Calculator<T>::Calculator(){
    this->valueStack = new Stack<T>();
    this->operatorStack = new Stack<Operator<T>*>();
}
