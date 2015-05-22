#include <iostream>
class Complex
{	
	public:
		Complex();
		Complex(float Re, float Im);

		Complex operator +(Complex p1);
		Complex operator -(Complex p1);
		Complex operator /(Complex p1);
		Complex operator *(Complex p1);

		Complex conj();

		float abs();
		float Real();
		float Imagine();

		friend std::ostream& operator << (std::ostream&c, Complex p);
		friend std::istream& operator >> (std::istream&c, Complex &p);
		
		friend std::ofstream& operator<<(std::ofstream& out, Complex&x);
		friend std::ifstream& operator>>(std::ifstream& in, Complex&x);

	private:
		float Im;
		float Re;

};
