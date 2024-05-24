#include <iostream>

#include "matrix.h"
using namespace std;

//Do not change the displayMatrix() function
void Matrix::Matrix::displayMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            cout << *matrix[i][j];

            if (j != columns - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }
}
Matrix::Matrix(int in_rows, int in_columns){
    if(in_rows<1 || in_columns<1){
        this->columns = 3;
        this->rows = 3;
        int **arrTemp = new int*[this->rows];
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            arrTemp[k_iterator] = new int[this->columns];
        }
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
                arrTemp[k_iterator][t_iterator] = 1;
            }
        }
        this->matrix = new int**[this->rows];
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
        }
        int index = 0;
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = &arrTemp[k_iterator][t_iterator];
            }
        }
    }
    else{
        int temp2 = 0;
        this->columns = in_columns;
        this->rows = in_rows;
        int **arrTemp = new int*[this->rows];
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            arrTemp[k_iterator] = new int[this->columns];
        }
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
                arrTemp[k_iterator][t_iterator] = 0;
            }
        }
        this->matrix = new int**[this->rows];
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
        }
        int index = 0;
        for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
            for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = &arrTemp[k_iterator][t_iterator];
            }
        }
    }
}
Matrix::~Matrix(){
    for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
        // for(int t_iterator = 0;t_iterator<this->rows;t_iterator++){
        //     delete [] this->matrix[k_iterator][t_iterator];
        // }
        delete [] this->matrix[k_iterator];
    }
    delete [] this->matrix;
    this->matrix = NULL;
    this->columns = 0;
    this->rows = 0;
}
