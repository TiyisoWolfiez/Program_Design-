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
