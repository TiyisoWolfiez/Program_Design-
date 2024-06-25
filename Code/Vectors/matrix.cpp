#include "matrix.h"
#include <iomanip>
using namespace std;

Matrix operator*(const double& multipler, const Matrix& rhs)
{
	Matrix obj(rhs.getRows(),rhs.getCols());
    for(int r =0;r<rhs.getRows();r++)
    {
        for(int c=0;c<rhs.getCols();c++)
        {
            obj.matrix[r][c]=multipler*rhs.matrix[r][c];
        }
    }
    return obj;
}
Matrix::Matrix(unsigned r, unsigned c)
{
	this->rows = r;
	this->cols = c;
	this->matrix=new double*[rows];
	for(int F=0;F<this->rows;F++)
	{
		this->matrix[F]=new double [this->cols];
	}
	for(int P=0;P<this->rows;P++)
	{
		int D=0;
		for(int x=0;x<rows;x++)
		{
			this->matrix[P][x]=0;
		}
	}
}
Matrix::Matrix(const Matrix& rhs)
{
	this->rows=rhs.rows;
	this->cols=rhs.cols;
	this->matrix=new double*[rows];
	for(int F=0;F<this->rows;F++)
	{
		this->matrix[F]=new double [this->cols];
	}
	for(int B=0;B<this->rows;B++)
	{
		for(int v=0;v<this->cols;v++)
		{
			this->matrix[B][v]=rhs.matrix[B][v];
		}
	}
}
Matrix::~Matrix()
{
	if(this->matrix!=NULL)
	{
		for(int V=0;V<getRows();V++)
		{
			delete [] this->matrix[V];
			this->matrix[V] = NULL;
		}
		delete [] this->matrix;
		this->matrix = NULL;
	}
}
void Matrix::print()
{
	for(int U=0;U<this->getRows();U++)
	{	for(int G=0;G<this->getCols();G++)
		{	std::cout<<setw(10);
			std::cout<<this->matrix[U][G]<<setprecision(3);
		}
		std::cout<<"\n";
	}
}
void Matrix::readFile(istream &infile)
{
	for(int U=0;U<this->getRows();U++)
	{	for(int G=0;G<this->getCols();G++)
		{
			infile>>this->matrix[U][G];
		}
	}
}

// Insert overloaded = operator signature
const Matrix& Matrix::operator=(const Matrix& rhs)
{
	if(this == &rhs) return *this;
	this->rows=rhs.rows;
	this->cols=rhs.cols;
	this->matrix=new double*[rows];
	for(int F=0;F<this->rows;F++)
	{
		this->matrix[F]=new double [cols];
	}
	for(int B=0;B<this->rows;B++)
	{
		for(int v=0;v<this->cols;v++)
		{
			this->matrix[B][v]=rhs.matrix[B][v];
		}
	}
	return *this;
}

// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix& rhs)
{
	if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else
	{
		Matrix Mat_Array( rhs.getRows(), rhs.getCols());
		for(int counter=0;counter<rhs.getRows();counter++)
		{
			for(int Index=0; Index<rhs.getCols(); Index++)
			{
				Mat_Array.matrix[counter][ Index]=this->matrix[counter][ Index]+rhs.matrix[counter][ Index];
			}
		}
		return Mat_Array;
	}
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
	if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
	{
		throw "Error: adding matrices of different dimensionality";
	}
	else
	{
		for(int counter=0;counter<rhs.getRows();counter++)
		{
			for(int Index=0; Index<rhs.getCols(); Index++)
			{
				this->matrix[counter][ Index]=this->matrix[counter][ Index]+rhs.matrix[counter][ Index];
			}
		}
		return *this;
	}
}

Matrix Matrix::operator-(const Matrix& rhs)
{
	if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else
	{
		Matrix Mat_Array( rhs.getRows(), rhs.getCols());
		for(int counter=0;counter<rhs.getRows();counter++)
		{
			for(int Index=0; Index<rhs.getCols(); Index++)
			{
				Mat_Array.matrix[counter][ Index]=this->matrix[counter][ Index]-rhs.matrix[counter][ Index];
			}
		}
		return Mat_Array;
	}
}
Matrix& Matrix::operator-=(const Matrix& rhs)
{
	if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else
	{
		for(int counter=0;counter<rhs.getRows();counter++)
		{
			for(int Index=0; Index<rhs.getCols(); Index++)
			{
				this->matrix[counter][ Index]=this->matrix[counter][ Index]-rhs.matrix[counter][ Index];
			}
		}
		return *this;
	}
}
Matrix Matrix::operator*(const Matrix& rhs)
{
	if(this->cols!=rhs.getRows())
	{
		throw "Error: invalid matrix multiplication";
	}
	else
	{
		Matrix Temp(rhs.getRows(),this->cols);
		for(int counter=0;counter<this->getRows();counter++)
		{
			for(int Index=0; Index<rhs.getCols(); Index++)
			{
				double Temp2 = 0;
				for(int Index2=0; Index2<rhs.getRows(); Index2++)
				{
					Temp2=this->matrix[counter][ Index2]*rhs.matrix[Index2][ Index];
				}
				Temp.matrix[counter][Index] = Temp2;
			}
		}
		return Temp;
	}
}
Matrix& Matrix::operator*=(const Matrix& rhs)
{
	if(this->cols!=rhs.getRows())
	{
		throw "Error: invalid matrix multiplication";
	}
	else
	{
		Matrix Temp(rhs.getRows(),this->cols);
		for(int counter=0;counter<this->getRows();counter++)
		{
			for(int Index=0; Index<rhs.getCols(); Index++)
			{
				double Temp2 = 0;
				for(int Index2=0; Index2<rhs.getRows(); Index2++)
				{
					Temp2=this->matrix[counter][ Index2]*rhs.matrix[Index2][ Index];
				}
				Temp.matrix[counter][Index] = Temp2;
			}
		}
		delete this->matrix;
		this->cols = Temp.getCols();
		this->rows = Temp.getRows();
		this->matrix = new double*[this->rows];
		for(int F=0;F<this->rows;F++)
		{
			matrix[F]=new double [this->cols];
		}
		for(int B=0;B<this->rows;B++)
		{
			for(int v=0;v<this->cols;v++)
			{
				matrix[B][v]=Temp.matrix[B][v];
			}
		}
	}
	return *this;
}
Matrix Matrix::operator^(int pow)
{
	Matrix Mat_Array2(*this);
	if(this->getRows()!=this->getCols())
	{
		throw "Error: non-square matrix provided";
    }
	else if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow==0)
		{
			Matrix Mat_Array(this->getRows(),this->getCols());
			for(int counter=0; counter<this->getRows(); counter++)
			{
				for(int Index=0;Index<this->getCols();Index++)
				{
					if(counter==Index)
					{
						Mat_Array.matrix[counter][Index]=1;
					}
					else
					{
						Mat_Array.matrix[counter][Index]=0;
					}
				}
			}
			return Mat_Array;
		}
		else if(pow==1)
		{
			return Mat_Array2;
		}
		else if(pow>1)
		{
			Matrix Mat_Array(this->getRows(),this->getCols());
			for(int counter=0; counter<this->getRows(); counter++)
			{
				for(int Index=0;Index<this->getCols();Index++)
				{
					Mat_Array.matrix[counter][Index]=this->matrix[counter][Index];
				}
			}
			Matrix Mat_Two=Mat_Array;
			for(int Index=0;Index<(pow-1);Index++)
			{
				Mat_Array=Mat_Array*Mat_Two;
			}
			return Mat_Array;
		}
	}
	return Mat_Array2;
}
Matrix& Matrix::operator^=(int pow)
{
	if(this->getRows() != this->getCols())
	{
		throw "Error: non-square matrix provided";
    }
	else if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow==0)
		{
			for(int counter=0; counter<this->getRows(); counter++)
			{
				for(int Index=0;Index<this->getCols();Index++)
				{
					if(counter==Index)
					{
						this->matrix[counter][Index]=1;
					}
					else
					{
						this->matrix[counter][Index]=0;
					}
				}
			}
			return *this;
		}
		else if(pow==1)
		{
			return *this;
		}
		else if(pow>1)
		{
			Matrix Mat_Array( this->getRows(), this->getCols() );
			for(int counter=0; counter<this->getRows(); counter++)
			{
				for(int Index=0;Index<this->getCols();Index++)
				{
					Mat_Array.matrix[counter][Index]=this->matrix[counter][Index];
				}
			}
			Matrix Mat_Two=Mat_Array;
			for(int Index=0;Index<(pow-1);Index++)
			{
				Mat_Array=Mat_Array*Mat_Two;
			}
			for(int counter=0; counter<this->getRows(); counter++)
			{
				for(int Index=0;Index<this->getCols();Index++)
				{
					this->matrix[counter][Index]=Mat_Array.matrix[counter][Index];
				}
			}			
		}
	}
	return *this;
}
// Matrix/scalar operations
Matrix Matrix::operator*(const double& rhs)
{
	Matrix Mat_Array( this->getRows(), this->getCols() );
	for(int counter=0; counter<this->getRows(); counter++)
	{
		for(int Index=0;Index<this->getCols();Index++)
		{
			Mat_Array.matrix[ counter][Index]=this->matrix[ counter][Index]*rhs;
		}
	}
	return Mat_Array;
}
Matrix& Matrix::operator*=(const double& rhs)
{
	for(int counter=0; counter<this->getRows(); counter++)
	{
		for(int Index=0;Index<this->getCols();Index++)
		{
			this->matrix[ counter][Index]=this->matrix[ counter][Index]*rhs;
		}
    }
	return *this;
}
Matrix Matrix::operator/(const double& rhs)
{
	if(rhs==0)
	{
		throw "Error: division by zero";
	}
	else
	{
		Matrix Mat_Array( this->getRows(), this->getCols() );
		for(int Dj=0;Dj<this->getRows();Dj++)
		{
			for(int Counter=0;Counter<this->getCols();Counter++)
			{
				Mat_Array.matrix[Dj][Counter]=this->matrix[Dj][Counter]/rhs;
			}
		}
		return Mat_Array;
	}
}
// Access the individual elements
double& Matrix::operator()(const unsigned r, const unsigned c)
{
	if(r<0 || r>=this->rows)
	{
		throw "Error: invalid row index";
	}
	else if(c<0 || c>=this->cols)
	{
		throw "Error: invalid column index";
	}
	return matrix[r][c];
}
