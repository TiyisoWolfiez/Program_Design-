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
void Vector::readFile(istream &infile)
{
	for(int G=0;G<this->getSize();G++)
	{ 	
		infile>>this->vector[G];
	}
}

// Insert overloaded = operator signature
const Vector& Vector::operator=(const Vector& rhs)
{
	if(this == &rhs) return *this;
	this->size = rhs.getSize();
	this->vector = new double[this->getSize()];
	for(int c=0;c<this->getSize();c++)
	{
		this->vector[c] = rhs.vector[c];
	}
	return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector& rhs)
{
	Vector Mat_Array(rhs.getSize());
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: adding vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			Mat_Array.vector[ Index]=this->vector[ Index]+rhs.vector[ Index];
		}
	}
	return Mat_Array;
}
Vector& Vector::operator+=(const Vector& rhs)
{
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: adding vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			this->vector[ Index]=this->vector[ Index]+rhs.vector[ Index];
		}
	}
	return *this;
}
Vector Vector::operator-(const Vector& rhs)
{
	Vector Mat_Array(rhs.getSize());
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: subtracting vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			Mat_Array.vector[ Index]=this->vector[ Index]-rhs.vector[ Index];
		}
	}
}
