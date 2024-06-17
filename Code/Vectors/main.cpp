#include <iostream>
#include "matrix.h"
#include "vector.h"
#include <fstream>
#include <string>

using namespace std;

static void print(Arithmetic *mat) {
    mat->print();
    cout << endl;
}

static void readFile(istream &infile, Arithmetic *mat) {
    mat->readFile(infile);
}

//
static void task1() {
    ifstream infile("example_input.txt");
    // The test code below assumes that you have implemented all Task 1 functionality

    // 1. Test constructor:
    cout << "Constructors: " << endl;

    Matrix *m1 = new Matrix(3, 4);
    print(m1);

    Vector *v1 = new Vector(7);
    v1->print();
    print(v1);


    // read file.
    readFile(infile, v1);
    v1->print();

    cout << "vector  Test" << endl;
    Vector v2(3);

    cout << v2[0] << endl;

    readFile(infile, m1);
    m1->print();

    // Test assignment operator:
    Matrix *m2 = new Matrix(1, 4);
    print(m2);
    m2 = m1; // assignment
    print(m2);

    // Test getters
    cout << "Getters: " << endl;
    cout << m1->getRows() << endl;
    cout << m2->getCols() << endl;
    cout << v1->getSize() << endl;

//    // Test [][]
    cout << "Test [][]: " << endl;
    try {
        Matrix m4(3, 3);
        m4.readFile(infile);
        cout << m4[0][2] << endl;
        m4(0,2) = 5;
        cout << m4[0][2] << endl;
        m4(5,2) = 5;
    } catch (const char *error) {
        cout << error << endl;
    }

    infile.close();
}
