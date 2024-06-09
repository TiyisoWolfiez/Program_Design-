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
template<class T>
std::string SortList<T>::print(){
    std::string temp_string("");
    for(SortNode<T>* temp_node = this->head; temp_node != NULL; ){
        temp_string += temp_node->print() + ",";
        temp_node = temp_node->next;
    }
    return temp_string.substr(0, temp_string.length()-1);
}
template<class T>
SortNode<T>* SortList<T>::getHead(){
    return this->head;
}
template<class T>
SortNode<T>* SortList<T>::remove(T val){
    SortNode<T>* temp_node = this->head;
    for( ; temp_node != NULL && temp_node->getValue() != val ; ){
        temp_node = temp_node->next;
    }
    if(temp_node != NULL){
        if(temp_node == this->head || temp_node == this->tail){
            if(temp_node == this->head && temp_node == this->tail){
                this->head = this->head->next;
                this->tail = this->tail->next;
            }
            else if(temp_node == this->tail){
                this->tail = this->tail->prev;
                this->tail->next = temp_node->prev = NULL;
            }
            else{
                this->head = this->head->next;
                this->head->prev = temp_node->next = NULL;
            }
        }
        else if(temp_node != this->head && temp_node != this->tail){
            temp_node->prev->next = temp_node->next;
            temp_node->next->prev = temp_node->prev;
            temp_node->prev = temp_node->next = NULL;
        }
    }
    return temp_node;
}
