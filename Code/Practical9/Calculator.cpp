#include "Calculator.h"
#include <cstddef>


template <typename T>
Calculator<T>::Calculator(){
    this->valueStack = new Stack<T>();
    this->operatorStack = new Stack<Operator<T>*>();
}

template <typename T>
Calculator<T>::~Calculator(){
    if(!this->operatorStack->isEmpty()){
        delete this->operatorStack;
    }
    if(!this->valueStack->isEmpty()){
        delete this->valueStack;
    }
}

template <typename T>
void Calculator<T>::addValue(T val){
    this->valueStack->push(val);
}

template <typename T>
void Calculator<T>::addOperator(Operator<T>* op){
    this->operatorStack->push(op->clone());
}
