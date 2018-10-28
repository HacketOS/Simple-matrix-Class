#pragma once

#include <vector>
#include <string>
using namespace std;

template <typename T = double>
class Matr
{
private:
	int str, stl;					// количество строк и столбцов
	T** mat;						// сама матрица
	string name;					// имя матрицы
	static int count;				// счётчик матриц
public:
	Matr();							// по умолчанию матрица 10х10
	Matr(int n, int m);				// матрица с задаными размерами n -кол-во строк, m - кол-во столбцов
	Matr(const Matr &mat1);			//конструктор копирования

	void randm();				// заполнить матрицу рандомными занчениями int 
	void E(int size);			// единичная матрица 
	void exp(int n);			// возведение в степень n
	T min_of_column(int m);		// минимальный элемент из столбца m
	T max_of_column(int m);		//максимальный элемент из столбца m
	T summ_of_column(int m);	// сумма элементов столбца m
	T summ_of_string(int n);	// сумма столбца n
	vector<T> min_vector();		// вектор из минимальных значений столбцов 
	T max();					//максимальный элемент матрицы
	T min();					//минимальный элемент матрицы
	void transp();			// транспнирование матрицы 

	void show();								// вывести матрицу
	void show(int x, int y, int lx, int ly);	// вывести часть матрицы x,y - № столба и строки; lx, ly -размеры выводимой части
	void get();									// ввод матрицы через консоль
	void get(int n, int m);						// ввод элемента на позиции [n][m]
	void get(int x, int y, int lx, int ly);		// ввести часть матрицы x,y - № столба и строки; lx, ly -размеры выводимой части
	void names();								// имя матрицы
	static void counter();						// количество матриц на данный момент
	
	bool operator == (const Matr& mat2);		// оператор ставнения
	T* operator [](int n);						// оператор индексирования
	Matr<T> operator += (const Matr& mat2);		//оператор сложения матриц
	Matr<T> operator *= (T x);					//оператор умнжения на число
	Matr<T> operator = (const Matr& mat2);		//оператор приравнивания
	Matr<T> operator -= (const Matr& mat2);		//операор вычитания и приравнивания матриц
	Matr<T> operator + (const Matr& mat2);		//оператор сложения матриц
	Matr<T> operator - (const Matr& mat2);		//оператор разности матриц
	Matr<T> operator * (const Matr& mat2);		//оператор умножения матриц
	friend ostream& operator<< <>(ostream& s, const Matr<T>& mat2);	// перегрузка оператора вывода 


	~Matr();							// деструктор 
};

