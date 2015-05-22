#include <iostream>
#include <fstream>
using namespace std;

class CMyString
{
	char* pData;
public:
	CMyString();
	~CMyString();
	int GetSize();
	CMyString(CMyString&s);

	friend istream& operator>>(istream&, CMyString&);
	friend ostream& operator<<(ostream&, CMyString&);
	friend bool operator ==(CMyString S1, CMyString S2);
	friend bool operator <(CMyString S1, CMyString S2);
	friend bool operator > (CMyString S1, CMyString S2);
	CMyString& operator=(CMyString& s);


};
int CMyString::GetSize()
{
	int size;
	for (size = 0; pData[size] != '\0'; size++);
	return size;
}
bool operator == (CMyString a, CMyString b)
{
	for (int i = 0;; i++)
	{
		if ((a.pData[i] == '\0') && (b.pData[i] == '\0'))
			return 1;
		else
			if (a.pData[i] == '\0')
				return 0;
			else
				if (b.pData[i] == '\0')
					return 0;
				else
					if (a.pData[i] < b.pData[i])
						return 0;
					else
						if (a.pData[i] > b.pData[i])
							return 0;
	}
}
bool operator < (CMyString a, CMyString b)
{
	for (int i = 0;; i++)
	{
		if ((a.pData[i] == '\0') && (b.pData[i] == '\0'))
			return 0;
		else
			if (a.pData[i] == '\0')
				return 0;
			else
				if (b.pData[i] == '\0')
					return 1;
				else
					if (a.pData[i] < b.pData[i])
						return 0;
					else
						if (a.pData[i] > b.pData[i])
							return 1;
	}
}
bool operator > (CMyString a, CMyString b)
{
	for (int i = 0;; i++)
	{
		if ((a.pData[i] == '\0') && (b.pData[i] == '\0'))
			return 0;
		else
			if (a.pData[i] == '\0')
				return 1;
			else
				if (b.pData[i] == '\0')
					return 0;
				else
					if (a.pData[i] < b.pData[i])
						return 1;
					else
						if (a.pData[i] > b.pData[i])
							return 0;
	}
}
CMyString::~CMyString()
{
	delete[] pData;
}
CMyString::CMyString()
{
	pData = new char[1];
	pData[0] = '\0';
}
CMyString::CMyString(CMyString&s)
{
	
	int i;
	int size = s.GetSize();


	 char*p= new char[size + 1];
	 pData = p;
	for (i = 0; s.pData[i] != '\0'; i++)
	{
		pData[i] = s.pData[i];
	}
	pData[i] = '\0';

}
CMyString& CMyString::operator=(CMyString& s)
{
	int i;
	int size = s.GetSize();
	if (pData != 0)
	{
		delete[] pData;
	}
	pData = new char[size + 1];
	for (i = 0; s.pData[i] != '\0'; i++)
	{
		pData[i] = s.pData[i];
	}
	pData[i] = '\0';
	return *this;

}
istream& operator>>(istream& str, CMyString& s)
{
	str >> s.pData;
	return str;
}
ostream& operator<<(ostream& str, CMyString& s)
{
	str << s.pData;
	return str;
}
class CBirthDay
{
	int Year;
	int Month;
	int Day;
public:
	CBirthDay();
	~CBirthDay();
	CBirthDay(int Year, int Month, int Day);
	friend istream& operator >>(istream& str, CBirthDay&);
	friend ostream& operator <<(ostream& str, CBirthDay&);
	void operator = (CBirthDay P);

};
CBirthDay::~CBirthDay()
{
}
istream& operator >>(istream& str, CBirthDay& date)
{
	cout << "Year-";
	str >> date.Year;
	cout << "Month-";
	str >> date.Month;
	cout << "Day-";
	str >> date.Day;
	return str;
}

ostream& operator <<(ostream& str, CBirthDay& date)
{
	str << "Year-" << date.Year << endl;
	str << "Month-" << date.Month << endl;
	str << "Day-" << date.Day << endl;
	return str;
}
CBirthDay::CBirthDay()
{
	Year = 0;
	Month = 0;
	Day = 0;
}
CBirthDay::CBirthDay(int Year1, int Month1, int Day1)
{
	Year1 = Year;
	Month1 = Month;
	Day1 = Day;
}
void CBirthDay::operator = (CBirthDay P)
{
	Year = P.Year;
	Month = P.Month;
	Day = P.Day;

}
class CStudent
{
public:
	CMyString Name;
	CMyString Surname;
	CBirthDay BD;
	int group;
	CStudent* pNext;
	~CStudent();
	CStudent();
	friend istream& operator>>(istream&, CStudent*&);
	friend ostream& operator<<(ostream&, CStudent*&);
	void operator = (CStudent P);
	//friend void  Add(CStudent*);
	int Finder(CStudent*, CMyString, int);
};
CStudent::CStudent()
{
	pNext = NULL;
}
CStudent::~CStudent()
{

}

istream& operator>>(istream& str, CStudent*& s)
{
	cout << "Name-";
	str >> s->Name;
	cout << "Surname-";
	str >> s->Surname;
	cout << "Birthday:";
	str >> s->BD;
	cout << "Group-";
	str >> s->group;

	return str;
}
ostream& operator<<(ostream& str, CStudent*& s)
{

	str << "Name-" << s->Name << endl;
	str << "Surname-" << s->Surname << endl;
	str << "Birthday:" << s->BD;
	str << "Group-" << s->group << endl;
	return str;
}

void CStudent ::operator =(CStudent P)
{
	Name = P.Name;
	Surname = P.Surname;
	BD = P.BD;
	group = P.group;
	pNext = P.pNext;

}
class CMyBase
{
	CStudent *pBegin;
public:
	void Add(CStudent* pCur);
	void Sort(int pole_num); // pole / type
	//int Delete(int t, CMyString q);
	//	f<<
	//	f>>

	int GetSize();
	int Finder(CStudent* pBegin, CMyString finder, int param);
	//void Delete(int k, CMyString p_a);
	void Swap(CStudent*p1, CStudent*p2);
	int DeleteElement(int name_surname, CMyString Del);
	CMyBase();
	~CMyBase();
	friend ostream& operator<<(ostream& str, CMyBase& s);
	friend ifstream& operator>>(ifstream& enter, CMyBase& s);
	friend ofstream& operator<<(ofstream& out, CMyBase& s);
};
int CMyBase::Finder(CStudent* pBegin, CMyString finder, int param)
{


	CStudent *pLast = NULL;
	//pLast->Name = pBegin->Name;
	//pLast->Surname = pBegin->Surname;
	pLast = pBegin;
	if (param == 1)
	{
		int i = 1;
		while (pLast->pNext != NULL)
		{
			if (pLast->Name == finder)
			{
				return i;
			}
			pLast = pLast->pNext;
			i++;
		}
	}
	if (param == 2)
	{
		int i = 1;
		while (pLast->pNext != NULL)
		{
			if (pLast->Surname == finder)
			{
				return i;
			}
			pLast = pLast->pNext;
			i++;
		}

	}

	return 0;
}
/*int CMyBase::Delete(int name_surname, CMyString Del)
{
	CMyString finder;
	int z;
	switch (name_surname)
	{
	case 1:
	{
		cout << "Enter the name of the item to remove" << endl;
		cin >> finder;
		z = Finder(pBegin, finder, name_surname);
		return z;
	}
	case 2:
	{
		cout << "Enter the surname of the item to remove" << endl;
		cin >> finder;
		z = Finder(pBegin, finder, name_surname);
		return z;
	}

	default:
		cout << "Error, bad input";
		return z = 0;
		break;
	}
}*/
int CMyBase::DeleteElement(int name_surname, CMyString Del)
{
	CStudent* pCur = pBegin;
	if (pCur == NULL)
	{
		cout << "Nothing to delete" << endl; return 0;
	}
	else
	{
		CStudent *p_Iter;
		int num = Finder(pBegin, Del, name_surname);
		if (num == 0)
		{
			return 0;
		};
		if (num == 1)
		{
			p_Iter = pBegin;
			pBegin = pBegin->pNext;
			delete p_Iter; return 0;
		}
		else
		{
			for (int i = 1; i < num - 1; i++)
				pCur = pCur->pNext;
			CStudent* pDel = pCur->pNext;
			pCur->pNext = (pCur->pNext)->pNext;
			delete (pDel); return 0;
		}
	}
	return 0;
}
/*void CMyBase::DeleteFromList(CStudent *pDel)
{
	CStudent *pIter;
	for (pIter = pBegin; pIter->pNext != pDel; pIter = pIter->pNext);
	pIter->pNext = pDel->pNext;
	delete pDel;
}*/

/*void CMyBase::Delete(int k, CMyString p_a)
{
	CStudent*pCur=pBegin;
	CStudent*pPrev = NULL;
	for (pCur = pBegin; pCur != NULL; pCur = pCur->pNext)
	{
		if (k == 1)
		{
			if (p_a == pCur->Surname)
			{
				if (pBegin == pCur)
					pBegin = pBegin->pNext;
				else
					pPrev->pNext = pCur->pNext;
				delete (pCur);
				return;
			}
		}
		else {
			if (p_a == pCur->Name)
			{
				if (pBegin == pCur)
					pBegin = pBegin->pNext;
				else
					pPrev->pNext = pCur->pNext;
				delete (pCur);
				return;
			}
		}
		pCur=pPrev;
		
	}

}*/
CMyBase::~CMyBase()
{
	CStudent*pIter;
	CStudent*pTemp;
	for (pIter = pBegin; pIter != NULL; pIter = pTemp)
	{
		pTemp = pIter->pNext;
		delete pIter;
	}
}
CMyBase::CMyBase()
{
	pBegin = NULL;
}
ostream& operator<<(ostream& str, CMyBase& s)
{
	CStudent *pCur = s.pBegin;

	while (pCur != NULL)
	{
		str << pCur << endl;
		//cout << *pCur;
		pCur = pCur->pNext;
	}
	return str;
}
ifstream& operator>>(ifstream& in, CMyBase& s)
{
	CStudent *pCur = s.pBegin;

	while (pCur != NULL)
	{
		in >> pCur;
		pCur = pCur->pNext; 
	
	}
	return in;

}
ofstream& operator<<(ofstream& out, CMyBase&s)
{
	CStudent *pCur = s.pBegin;

	while (pCur != NULL)
	{
	out << pCur << endl;
	pCur = pCur->pNext;out << "\n";
	}
	return out;
	
}
void CMyBase::Add(CStudent* pCur)
{
	pCur->pNext = pBegin;
	if (pBegin == NULL)
	{
		pBegin = pCur;
	}
	else
	{
		pCur->pNext = pBegin;
		pBegin = pCur;
	}
}
int CMyBase::GetSize()
{
	int k = 1;
	if (pBegin == NULL)
	{
		k = 0; return k;
	}
	CStudent* El = pBegin;
	while (El->pNext != NULL)
	{
		El = El->pNext;
		k++;
	}
	return k;
}
void CMyBase::Swap(CStudent*p1, CStudent*p2)
{
	CStudent*pTemp;
	p1->pNext = p2->pNext;
	pTemp = p2->pNext;
	p2->pNext = p2->pNext->pNext;
	pTemp->pNext = p2;	
}
void CMyBase::Sort(int pole_num)
{
	int n = GetSize();
	if (n == 0)
	{
		cout << "This list is empty" << endl;
	}
	if (n == 1)
	{
		cout << "This list contains one element" << endl;
	}
	if (n >= 2)
	{
		CStudent*pCur;
		int f = 1;
		for (pCur = pBegin; pCur != 0 && pCur->pNext != NULL;)
		{
			if (pole_num == 1)
			{
					if (pCur->Name < pCur->pNext->Name)
					{
						Swap( pCur,pCur->pNext);
					}
					pCur = pCur->pNext;
			}
			if (pole_num == 2)
			{
					if (pCur->Surname < pCur->pNext->Surname)
					{
						Swap(pCur, pCur->pNext);
					}
					pCur = pCur->pNext;
			}
			else
			{
				cout << "Error" << endl;
			}
		}
	
	}
}

void main()
{
	CMyBase Base;
	CStudent* pCur;

	while (1)
	{
		cout << endl;
		cout << "1 - Add new element" << endl;
		cout << "2 - Sort List" << endl;
		cout << "3 - Delete element" << endl;
		cout << "4 - Print" << endl;
		cout << "5 - Print to file" << endl;
		cout << "6 - Load from file" << endl;
		cout << "Enter a command: " << endl;

		int choise;
		cin >> choise;
		switch (choise)

		{
		case 1:
		{
			pCur = new CStudent;
			cin >> pCur;
			Base.Add(pCur);
			break;
		}

		case 2:
		{
			int pole_num, type;
			cout << "1- by name" << endl;
			cout << "2- by surname" << endl;
			cout << "Enter a command:" << endl;
			cin >> pole_num;
			Base.Sort(pole_num);
			break;
		}

		case 3:
		{
			CMyString Del;
			int k;
			cout << "2- delete by surname, 1- delete by name" << endl;
			cin >> k;
			cout << "Enter word" << endl;
			cin >> Del;
			Base.DeleteElement(k, Del);
		}
		break;

		case 4:
			cout << Base;
			break;
		default:
			cout << "Error, bad input,\n";
			break;
		case 5:
		{
			char filename[80];
			cout << "Enter name of file" << endl;
			cin >> filename;
			ofstream of(filename);
			of << Base;
			of.close();
			break;
		}

		case 6:
		{
			char filename[80];
			cout << "Enter name of file" << endl;
			cin >> filename;
			ifstream In(filename);
			In >> Base;
			In.close();
			break;
		}
			}
		}
	}

