#include "Complex.h"
class Matrix
{
public:
	Matrix();
	Matrix(const Matrix& x);
	Matrix(int n,int m);
	
	Matrix& operator =(const Matrix &p);
	Matrix operator * (Matrix p);
	Matrix operator + (Matrix p);

	Matrix Inverse();
	Matrix Transp();
	
	friend Complex;
	
	friend std::ostream& operator << (std::ostream&c, Matrix p);
	friend std::istream& operator >> (std::istream&c, Matrix &p);
	
	friend std::ifstream& operator>>(std::ifstream& enter, Matrix& m);
	friend std::ofstream& operator<<(std::ofstream& out, Matrix& m);
	
	~Matrix();
	
protected:
	Complex*s;
	int m;
	int n;
	Complex det;
};
