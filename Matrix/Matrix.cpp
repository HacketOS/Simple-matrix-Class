//Класс матриц, для которго перегружены все операции

#include "stdafx.h"

#include "Matr.h"
#include "Matr.cpp"
using namespace std;

int main()
{
	Matr<int> s1(3,2),s2 (2,3);
	s1.randm();
	s2.randm();
	s1.show();
	s2.show();
	cout << "transp" << endl;
	s1.transp();
	s2.transp();
	s1.show();
	s2.show();
	_getch();
    return 0;
}

