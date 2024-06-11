#include "SortNode.h"
#include <sstream>
#include <string>
using namespace std;

template<class T>
SortNode<T>::SortNode(T val){
    this->value = val;
    this->next = this->prev = NULL;
}
