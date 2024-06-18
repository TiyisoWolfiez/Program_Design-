#include "matrix.h"
#include <iomanip>

Vector operator*(const double& multipler, const Vector& rhs)
{
	Vector obj(rhs.getSize());
	for(int c=0;c<rhs.getSize();c++)
	{
		obj.vector[c]=multipler*rhs.vector[c];
	}
	return obj;
}
Vector::Vector(unsigned s)
{
	this->size = s;
	this->vector = new double[this->getSize()];
	for(int c=0;c<this->getSize();c++)
	{
		this->vector[c] = 0;
	}
}
Vector::Vector(const Vector& rhs)
{
	this->size = rhs.getSize();
	this->vector = new double[this->getSize()];
	for(int c=0;c<this->getSize();c++)
	{
		this->vector[c] = rhs.vector[c];
	}
}
Vector::~Vector()
{
	delete [] this->vector;
	this->vector = NULL;
}
void Vector::print()
{
	for(int G=0;G<this->getSize();G++)
	{	
		std::cout<<setw(10);
		std::cout<<this->vector[G]<<setprecision(3);
	}
	std::cout<<"\n";
}
