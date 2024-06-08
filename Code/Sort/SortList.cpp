#include "SortList.h"
#include <iostream>
using namespace std;

template<class T>
SortList<T>::SortList(bool val){
    this->ascending = val;
    this->tail = this->head = NULL;
}
template<class T>
void SortList<T>::add(SortNode<T>* val){
    if(this->tail != NULL){
        val->prev = this->tail;
        this->tail->next = val;
        this->tail = val;
    }
    else{
        this->tail = val;
        this->head = val;
    }
}
