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
