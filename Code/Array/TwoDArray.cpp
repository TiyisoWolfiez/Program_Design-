#include "TwoDArray.h"

TwoDArray::TwoDArray(int** array, int* sizes, int baseSize){
    this->baseSize = baseSize;
    const int size = this->getBaseSize();
    this->sizes = new int[size];
    for(int i = 0;i<size;i++){
        this->sizes[i] = sizes[i];
    }
    this->array = new int*[size];
    for(int i = 0;i<size;i++){
        const int size = this->getSizes()[i];
        this->array[i] = new int[size];
        for(int j = 0;j<size;j++){
            this->array[i][j] = array[i][j];
        }
    }
}
TwoDArray::~TwoDArray(){
    const int size = this->getBaseSize();
    for(int i = 0;i<size;i++){
        delete this->array[i];
    }
    for(int i = 0;i<size;i++){
        this->array[i] = NULL;
    }
    delete this->array;
    delete this->sizes;
    this->array = NULL;
    this->sizes = NULL;
}
TwoDArray::operator int(){
    return this->getBaseSize();
}
