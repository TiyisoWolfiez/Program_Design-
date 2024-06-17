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
