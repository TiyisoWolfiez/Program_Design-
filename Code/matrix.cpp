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
