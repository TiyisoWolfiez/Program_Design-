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

// Insert overloaded = operator signature
  const Matrix& operator=(const Matrix& rhs);

  // Matrix mathematical operations
  Matrix operator+(const Matrix& rhs);
  Matrix& operator+=(const Matrix& rhs);
  Matrix operator-(const Matrix& rhs);
  Matrix& operator-=(const Matrix& rhs);
  Matrix operator*(const Matrix& rhs);
  Matrix& operator*=(const Matrix& rhs);
  Matrix operator^(int pow);
  Matrix& operator^=(int pow);
  Matrix operator~(); // transpose

 // Matrix/scalar operations
  Matrix operator*(const double& rhs);
  Matrix& operator*=(const double& rhs);
  Matrix operator/(const double& rhs);
