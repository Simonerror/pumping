#include <iostream>
#include <fstream>
#include "math.h"
#include "Complex.h"
using namespace std;
Complex::Complex()
{
	Im = 0;
	Re = 0;
}

Complex::Complex(float Re2 , float Im2)
{
	Im = Im2;
	Re = Re2;
}

Complex Complex::operator +(Complex p1)
{
	float Im2;
	float Re2;
	Im2 = p1.Im + Im;
	Re2 = p1.Re + Re;
	Complex q(Re2,Im2);
	return q;
}
Complex Complex::operator -(Complex p1)
{
	float Im2;
	float Re2;
	Im2 = Im - p1.Im;
	Re2 = Re - p1.Re;
	Complex q(Re2, Im2);
	return q;
}
Complex Complex::operator *(Complex p1)
{
	float Im2;
	float Re2;
	Re2 = p1.Re*Re-p1.Im*Im;
	Im2 = p1.Re*Im + p1.Im*Re;
	Complex q(Re2, Im2);
	return q;
}

Complex Complex::conj()
{
	float Im2 = -Im;
	float Re2 = Re;
	return Complex(Re2,Im2);
}
Complex Complex::operator /(Complex p1)
{
	Complex cur = Complex(Im, Re);
	Complex q = p1.conj();
	float z = p1.abs();
	Complex c = q*cur;
	float Im2 = c.Imagine() / pow(z, 2);
	float Re2 = c.Real() / pow(z,2);
	return Complex(Re2, Im2);
}

float Complex::Imagine()
{
	return Im;
}

float Complex::Real()
{
	return Re;
}

float Complex::abs()
{
	float s;
	s = sqrt(Im*Im + Re*Re);
	return s;
}

ostream& operator <<(ostream&c, Complex x)
{
	c << x.Re<<" +" <<x.Im<<"i";
	return c;
}
istream& operator >>(istream&c, Complex&x)
{
	cout << "Real: ";
	c >> x.Re; 
	cout << "Imagine: ";
	c >> x.Im;
	cout << endl;
	return c;
}

ifstream& operator>>(ifstream& in, Complex&x)
{
	in >> x.Re;
	in >> x.Im;
	return in;
}
ofstream& operator<<(ofstream& out, Complex&x)
{
	out << x.Re; 
	out << " ";
	out<< x.Im;
	return out;
}

