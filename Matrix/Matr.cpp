#include "stdafx.h"
#include "Matr.h"


template <typename T = double>
int Matr<T>::count = 0;

template <typename T = double>
Matr<T>::Matr()
{
	str = 10;
	stl = 10;
	count++;
	name = "Matrix N.";
	mat = new T*[str];
	for (int i = 0; i<str; i++)
	{
		mat[i] = new T[stl];
	}
}

template <typename T = double>
Matr<T>::Matr(int n, int m)
{
	
	str = n;
	stl = m;
	count++;
	name = "Matrix N.";
	name.push_back(char(count + '0'));
	if (str==0 && stl==0)
	{
		cout << "min size is 1" << endl;
	}
	mat = new T*[n];
	for (int i = 0; i<n; i++)
	{
		mat[i] = new T[m];
	}
}

template<typename T = double>
Matr<T>::Matr(const Matr & mat1)
{
	mat = new T*[mat1.str];
	for (int i = 0; i<mat1.str; i++)
	{
		mat[i] = new T[mat1.stl];
	}
	str = mat1.str;
	stl = mat1.stl;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stl; j++)
		{
			mat[i][j] = mat1.mat[i][j];
		}
	}
}

template <typename T = double>
void Matr<T>::show()
{
	cout << name << endl;
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			cout << setw(3) << mat[i][j];
		}
		cout << endl;
	}
}

template<typename T = double>
void Matr<T>::show(int x, int y, int lx, int ly)
{

	for (int i = y; i<y+ly; i++)
	{
		for (int j = x; j< x+lx; j++)
		{
			cout << setw(5) << mat[i][j];
		}
		cout << endl;
	}
}

template <typename T = double>
void Matr<T>::randm()
{
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			mat[i][j] = rand() % 20;
		}
	}
}

template<typename T = double>
void Matr<T>::E(int s)
{
	for (int i = 0; i < str; i++)
	{
		delete[] mat[i];
	}

	mat = new T*[s];
	for (int i = 0; i<s; i++)
	{
		mat[i] = new T[s];
	}
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			mat[i][j] = 0;
			if (i == j)mat[i][j] = 1;
		}
	}
}

template<typename T = double>
void Matr<T>::exp(int n)
{
	if (n == 0)
	{
		for (int i = 0; i<str; i++)
		{
			for (int j = 0; j< stl; j++)
			{
				mat[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		this* = (this*)*(this*);
	}
}

template<typename T =double>
void Matr<T>::get()
{
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			cin >> mat[i][j];
		}
	}
	system("cls");
}

template<typename T = double>
void Matr<T>::get(int n, int m)
{
	cin >> mat[n][m];
}

template<typename T = double>
void Matr<T>::get(int x, int y, int lx, int ly)
{
	for (int i = y; i<y + ly; i++)
	{
		for (int j = x; j< x + lx; j++)
		{
			cin>> mat[i][j];
		}
	}
}

template<typename T = double>
void Matr<T>::names()
{
	cout << name<< endl;
}

template<typename T = double>
void Matr<T>::counter()
{
	cout << "amount is " << count << endl;
}

template<typename T = double>
T Matr<T>::min_of_column(int m)
{
	T minimum = mat[0][m];
	for (int i = 0; i < str; i++)
	{
		if (mat[i][m] < minimum)minimum = mat[i][m];
	}
	return minimum;
}

template<typename T = double>
T Matr<T>::max_of_column(int m)
{

	T maximum = mat[0][m];
	for (int i = 0; i < str; i++)
	{
		if (mat[i][m] < maximum)maximum = mat[i][m];
	}
	return maximum;
}

template<typename T = double>
T Matr<T>::summ_of_column(int m)
{
	T summ=0;
	for (int i = 0; i < stl; i++)summ += mat[i][m];
	return summ;
}

template<typename T = double>
T Matr<T>::summ_of_string(int n)
{
	T summ = 0;
	for (int i = 0; i < stl; i++)summ += mat[m][i];
	return summ;
}

template<typename T>
vector<T> Matr<T>::min_vector()
{
	vector<T> vec;
	for (int i = 0; i < stl; i++)
	{
		vec.push_back(min_of_column(i));
	}
	return vec;
}

template<typename T = double>
T Matr<T>::max()
{
	T maximum = mat[0][0];
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			if (maximum < mat[i][j])maximum = mat[i][j];
		}
	}
	return maximum;
}

template<typename T = double>
T Matr<T>::min()
{
	T minimum = mat[0][0];
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			if (minimum > mat[i][j])minimum  = mat[i][j];
		}
	}
	return minimum;
}

template <typename T = double>
Matr<T> Matr<T>::operator += (const Matr& mat2)
{
	if (str == mat2.str && stl == mat2.stl)
	{
		for (int i = 0; i<str; i++)
		{
			for (int j = 0; j< stl; j++)
			{
				mat[i][j] += mat2.mat[i][j];
			}
		}
		return *this;
	}
	else { cout << "Erore"; return *this; }
}

template<typename T =double>
Matr<T> Matr<T>::operator *=(T x)
{
	for (int i = 0; i<str; i++)
	{
		for (int j = 0; j< stl; j++)
		{
			 mat[i][j] *=x;
		}
	}
	return *this;
}

template <typename T = double>
Matr<T> Matr<T>::operator = (const Matr& mat2)
{
	if (str == mat2.str && stl == mat2.stl)
	{
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < stl; j++)
			{
				mat[i][j] = mat2.mat[i][j];
			}
		}
	}
	return *this;
}

template <typename T = double>
Matr<T> Matr<T>::operator -= (const Matr& mat2)
{
	if (str == mat2.str && stl == mat2.stl)
	{
		for (int i = 0; i<str; i++)
		{
			for (int j = 0; j< stl; j++)
			{
				mat[i][j] -= mat2.mat[i][j];
			}
		}
		return *this;
	}
	else
	{
		cout << "Erore"; return *this;
	}
}

template <typename T = double>
Matr<T> Matr<T>::operator + (const Matr& mat2)
{
	Matr<T> p(str, stl);
	if (str == mat2.str && stl == mat2.stl)
	{
		for (int i = 0; i<str; i++)
		{
			for (int j = 0; j< stl; j++)
			{
				p.mat[i][j] = mat[i][j] + mat2.mat[i][j];
			}
		}
		return p;
	}
	else { cout << "Erore"; return *this;	}
}

template <typename T = double>
Matr<T> Matr<T>::operator - (const Matr& mat2)
{
	Matr<T> p(str, stl);
	
	if (str == mat2.str && stl == mat2.stl)
	{
		for (int i = 0; i<str; i++)
		{
			for (int j = 0; j< stl; j++)
			{
				p.mat[i][j] = mat[i][j] - mat2.mat[i][j];
			}
		}
		return p;
	}
	else 
	{
		cout << "Erore";  return *this;
	}
}

template <typename T = double>
Matr<T> Matr<T>::operator * (const Matr& mat2)
{
	if (stl != mat2.str) { cout << "multiplication is impossible" << endl; return Matr<T>(1, 1); }
	Matr<T> p(str, mat2.stl);
		for (int i = 0; i<str; i++)
		{
			for (int k = 0; k < mat2.stl; k++)
			{
				p.mat[i][k] = 0;
				for (int j = 0; j < mat2.str; j++)
				{
					p.mat[i][k] += mat[i][j] * mat2.mat[j][k];
				}
			}
		}
		return p;
}

template <typename T = double>
void Matr<T>::transp()
{
	
	int** mat1 = new T*[stl];
	for (int i = 0; i < stl; i++)
	{
		mat1[i] = new T[str];
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stl; j++)
		{
			mat1[j][i] = mat[i][j];
		}
	}
	for (int i = 0; i < str; i++)
	{
		delete[] mat[i];
	}
	mat = mat1;
	int p = str;
	str = stl;
	stl = p;
}

template<typename T = double>
bool Matr<T>::operator==(const Matr & mat2)
{
	if (str == mat2.str && stl == mat2.stl)
	{
		for (int i = 0; i<str; i++)
		{
			for (int j = 0; j< stl; j++)
			{
				if (mat2.mat != mat[i][j])return 0;
			}
		}
		return 1;
	}
	return 0;
}

template<typename T = double>
T* Matr<T>::operator[](int n)
{
	return mat[n];
}

template<typename T = double>
Matr<T>::~Matr()
{
	count--;
	for (int i = 0; i < str; i++)
	{
		delete[] mat[i];
	}
	
}

template<typename T = double>
ostream& operator<< <>(ostream& s, const Matr<T>& mat2)
{
	for (int i = 0; i<mat2.str; i++)
	{
		for (int j = 0; j< mat2.stl; j++)
		{
			s << setw(5) << mat2.mat[i][j];
		}
		s << endl;
	}
	return s;
}

