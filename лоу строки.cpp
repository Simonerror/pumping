#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString();
	~CMyString();
	friend istream& operator>>(istream& in, CMyString& string);
	CMyString& operator=(char buf[]);
	CMyString& operator=(CMyString& buf);
	int operator>(CMyString& string);
	const int StrLenght();
	friend ostream& operator<<(ostream& out, const CMyString& string);
private:
	char* pData;
};
#include <iostream>
#include "string.h"
using namespace std;

CMyString::CMyString()
{
	pData = new char[20];
}

CMyString::~CMyString()
{
	delete[] pData;
}

const int CMyString::StrLenght()
{
	int i = 0;
	while (pData[i] != 0)
	{
		i++;
	}
	return(i);
}

CMyString& /*возвращаемое значение*/ CMyString/*класс*/::operator=/*кназвание*/(char buf[])
{
	delete[] pData;
	int i = 0;
	while (buf[i] != 0)
	{
		i++;
	}
	pData = new char[i + 1];
	for (int j = 0; j <= i; j++)
		pData[j] = buf[j];
	return *this;
}

CMyString& CMyString::operator=(CMyString& buf)
{
	delete[] pData;
	int l = buf.StrLenght();
	pData = new char[l + 1];
	for (int j = 0; j <= l; j++)
		pData[j] = buf.pData[j];
	return *this;
}

istream& operator>>(istream& in, CMyString& string)
{
	char buf[256];
	in >> buf;
	string = buf;

	return in;
}

int CMyString::operator>(CMyString& string)
{
	int lenght1 = string.StrLenght();
	int lenght2 = StrLenght();
	int min = lenght1;
	if (lenght1 > lenght2)
		min = lenght2;
	for (int i = 0; i < min; i++)
	{
		if (pData[i]>string.pData[i])
			return(1);/*true*/
		if (pData[i]<string.pData[i])
			return(0);/*false*/
	}
	if (lenght1>lenght2)
		return(1);
	else return(0);
}

ostream& operator<<(ostream& out, const CMyString& string)
{	
	out << string.pData;
	return out;
}
#include <iostream>
#include "string.h"
using namespace std;

void Sort(CMyString mas[], int lenght)
{
	for (int i = 0; i < lenght-1; i++)
	{
		for (int j = 0; j < lenght-1; j++)
		{
			if (mas[j]>mas[j + 1])
			{
				CMyString s;
					s = mas[j + 1];
				mas[j + 1] = mas[j];
				mas[j] = s;
			}
		}
	}
}

int main()
{
	const int N = 10;
	CMyString mas[N];

	cout << "write 10 words" << endl;

	for (int i = 0; i < N; i++)
		cin >> mas[i];

	Sort(mas, N); // Отсортируйте массив по алфавиту

	for (int i = 0; i < N; i++)
		cout << mas[i] << endl;

	return 0;
}
