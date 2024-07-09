#include "Node.h"

template <typename T>
Node<T>::Node(T data){
    this->data = data;
    this->next = NULL;
}
template <typename T>
T Node<T>::getData(){
    return this->data;
}
