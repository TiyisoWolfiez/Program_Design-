#ifndef ASSIGNMENT2TEST_MATRIX_H
#define ASSIGNMENT2TEST_MATRIX_H

#include "arithmetic.h"
#include "vector.h"
#include <fstream>

using namespace std;

class Matrix : public Arithmetic
{
  friend Matrix operator* (const double&, const Matrix&);
  
 public:
  Matrix(unsigned r, unsigned c);
  Matrix(const Matrix& rhs);
  ~Matrix();

  void print();
  void readFile(istream &infile);
