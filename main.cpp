#pragma once
#include <fstream>
#include <iostream>
#include "Matrix.h"
using namespace std;
void main()
{
	Matrix p2;
/*	ifstream file;
	file.open("RESULT.txt", ios::in);
	file >> p2;
	file.close(); */
	cin >> p2;
	cout <<endl<<p2;
	ofstream file1;
	file1.open("RESULT.txt",ios::out);
	file1 << p2;
	file1.close();
	cout << "Complete"<<endl;
	system("pause");

	return;
};
