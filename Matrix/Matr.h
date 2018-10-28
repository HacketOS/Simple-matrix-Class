#pragma once

#include <vector>
#include <string>
using namespace std;

template <typename T = double>
class Matr
{
private:
	int str, stl;					// ���������� ����� � ��������
	T** mat;						// ���� �������
	string name;					// ��� �������
	static int count;				// ������� ������
public:
	Matr();							// �� ��������� ������� 10�10
	Matr(int n, int m);				// ������� � �������� ��������� n -���-�� �����, m - ���-�� ��������
	Matr(const Matr &mat1);			//����������� �����������

	void randm();				// ��������� ������� ���������� ���������� int 
	void E(int size);			// ��������� ������� 
	void exp(int n);			// ���������� � ������� n
	T min_of_column(int m);		// ����������� ������� �� ������� m
	T max_of_column(int m);		//������������ ������� �� ������� m
	T summ_of_column(int m);	// ����� ��������� ������� m
	T summ_of_string(int n);	// ����� ������� n
	vector<T> min_vector();		// ������ �� ����������� �������� �������� 
	T max();					//������������ ������� �������
	T min();					//����������� ������� �������
	void transp();			// ��������������� ������� 

	void show();								// ������� �������
	void show(int x, int y, int lx, int ly);	// ������� ����� ������� x,y - � ������ � ������; lx, ly -������� ��������� �����
	void get();									// ���� ������� ����� �������
	void get(int n, int m);						// ���� �������� �� ������� [n][m]
	void get(int x, int y, int lx, int ly);		// ������ ����� ������� x,y - � ������ � ������; lx, ly -������� ��������� �����
	void names();								// ��� �������
	static void counter();						// ���������� ������ �� ������ ������
	
	bool operator == (const Matr& mat2);		// �������� ���������
	T* operator [](int n);						// �������� ��������������
	Matr<T> operator += (const Matr& mat2);		//�������� �������� ������
	Matr<T> operator *= (T x);					//�������� �������� �� �����
	Matr<T> operator = (const Matr& mat2);		//�������� �������������
	Matr<T> operator -= (const Matr& mat2);		//������� ��������� � ������������� ������
	Matr<T> operator + (const Matr& mat2);		//�������� �������� ������
	Matr<T> operator - (const Matr& mat2);		//�������� �������� ������
	Matr<T> operator * (const Matr& mat2);		//�������� ��������� ������
	friend ostream& operator<< <>(ostream& s, const Matr<T>& mat2);	// ���������� ��������� ������ 


	~Matr();							// ���������� 
};

