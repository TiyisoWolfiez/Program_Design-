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
template<class T>
void SortList<T>::setAsc(bool val){
    this->ascending = val;
    this->sort();
}
template<class T>
std::string SortList<T>::debug(){
    std::string temp_string("");
    for(SortNode<T>* temp_node = this->tail; temp_node != NULL; ){
        temp_string += temp_node->print() + ",";
        temp_node = temp_node->prev;
    }
    return temp_string.substr(0, temp_string.length()-1);
}
