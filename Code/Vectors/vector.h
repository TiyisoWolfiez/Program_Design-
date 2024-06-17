#include <iostream>
#include "arithmetic.h"
#include <fstream>

using namespace std;

class Vector : public Arithmetic
{
  friend Vector operator* (const double&, const Vector&);
 public:
  Vector(unsigned s);
  Vector(const Vector& rhs);
  ~Vector();

void print();
void readFile(istream &infile);

// Insert overloaded = operator signature
const Vector& operator=(const Vector& rhs);
