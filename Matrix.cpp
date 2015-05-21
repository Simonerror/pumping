#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <string>

using namespace std;
Matrix::Matrix()
{
	s = new Complex[1];
	det = Complex(1,0);
	n = 1;
	m = 1;
};
Matrix::Matrix(int n, int m)
{	
	this->n = n;
	this->m = m;
	s = new Complex[n*m];
	for (int i = 0; i < n; i++)
	{
		for (int j=0; j < m; j++)
		{
			if (i == j)
			{
				s[(j)*m + i] = Complex(1,0);
			}
			else
			{
				s[(j)*m + i] = Complex(0, 0);
			}
		}
	}
	det = Complex(1,0);
};
Matrix::Matrix(const Matrix& x)
{
	s = new Complex[(x.m)*(x.n)];
	m = x.m;
	n = x.n;
	for (int i = 0; i < n; i++)
	{
		for (int j=0; j < m; j++)
		{
			if (i == j)
			{
				s[(j)*m + i] = x.s[(j)*m + i];
			}
			else
			{
				s[(j)*m + i] = x.s[(j)*m + i];
			}
		}
	}
	det = x.det;
};
Matrix::~Matrix()
{

		delete [] s ;

};

ifstream& operator >> (ifstream& in, Matrix& m)
{
	in >> m.m >> m.n;
	 
	m.s = new Complex[m.n * m.m];
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++)
		{
			in >> m.s[(j)*m.m + i];
		}

	}
	return in;
}
ofstream& operator<<(ofstream& out, Matrix& m)
{
	out << m.m << " " << m.n << endl;
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++)
		{
			out << m.s[(j)*m.m + i] << " ";
		}
	}
	return out;
}

ostream& operator <<(ostream&c, Matrix x)
{
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.m; j++)
		{
			c << x.s[(j )*x.m+i]<<" ";
		}
		c<<endl;
	}
	return c;
}
istream& operator >>(istream&c, Matrix&x)
{
	cout << "Enter size n" << endl;
	c >> x.n; cout << endl;
	cout << "Enter size m" << endl;
	c >> x.m; cout << endl;

	cout << "Enter Matrix" << endl;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.m; j++)
		{
			c >> x.s[(j)*x.m + i];
		}

	} cout << endl;
	cout << endl;
	return c;
}

Matrix Matrix::operator + (Matrix x)
{
	Matrix p(x.n,x.m);
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.m; j++)
		{
			p.s[(j)*p.m + i] = s[(j)*m + i] + x.s[(j)*x.m + i];
		}
	}
	return p;
}
Matrix Matrix::operator * (Matrix C)
{
	if (m == C.n)
	{
		Matrix RES(n, C.m);
		for (int i = 0; i < RES.n; i++)
		{
			for (int j = 0; j < RES.m; j++)
			{
				RES.s[j*RES.m + i] = Complex(0,0);
				for (int k = 0; k < m; k++)
				{
					RES.s[j*RES.m + i] = RES.s[j*RES.m + i]+(s[k*m + i] * C.s[j*C.m + k]);
				}
			}
		}
		return RES;
	}
	else
	{
		Matrix RES;
		cout << "No way! You cannot multiply these matrices." <<endl;
		return RES;
	}
}
Matrix& Matrix::operator =(const Matrix&x)
{	
	this->m = x.m;
	this->n = x.n;
	this->det = x.det;

	this->s = new Complex[n*m];

	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.m; j++)
		{
			this->s[(j)*x.m + i] = x.s[(j)*x.m + i];
		}
	}
		return *this;
}

Matrix Matrix::Inverse()
{
	Matrix P(m,m);
	Matrix E(m,m);			
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < P.m; j++)
		{
			P.s[(j )*m + i] = s[(j)*m + i];
		}
	}
	Complex p1,p2;

	Complex D (1,0);
	for (int i = 0; i < m; i++)
	{
		p1 = P.s[(i)*m + i];
		D = D*p1;
		for (int k = 0; k < m; k++)
			{
				P.s[(k)*m + i] = P.s[(k)*m + i] / p1;
				E.s[(k)*m + i] = E.s[(k)*m + i] / p1;
			}
		for (int l = i+1; l < m; l++)
			{	
				p2 = P.s[(i)*m +l];
				for (int t = 0; t < m; t++)
				{
					P.s[(t)*m +l] = P.s[(t)*m +l] - P.s[(t)*m +i] * p2;
					E.s[(t)*m +l] = E.s[(t)*m +l] - E.s[(t)*m +i] * p2;
				}
			}
	}
	
	p1 = Complex(0,0);
	for (int i = m-1; i > 0; i--)
	{
		for (int l = i-1; l >= 0; l--)
		{
			p1 = P.s[(i)*m +l];
			for (int t = m-1; t >=0; t--)
			{
				P.s[(t)*m +l] = P.s[(t)*m +l] - P.s[(t)*m +i] * p1;
				E.s[(t)*m +l] = E.s[(t)*m +l] - E.s[(t)*m +i] * p1;
			}
		}
	}
	det = D;
	return E;
}
Matrix Matrix::Transp()
{
	Matrix P(m,n);
	Complex temp;
	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				P.s[(j)*m +i] = s[(j)*m +i];
			}
		}
	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < P.n; j++)
			{
				if (i >= j)
				{
					temp = P.s[(j)*m +i];
					P.s[(j)*m +i] = P.s[(i)*m +j];
					P.s[(i)*m +j] = temp;
				}
			}
		}
	return P;
}
