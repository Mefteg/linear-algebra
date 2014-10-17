#include "matrix.h"

#include <iostream>

Matrix::Matrix()
{
	init(0, 0);
}

Matrix::Matrix(int _m, int _n)
{
	init(_m, _n);
}

Matrix::Matrix(Matrix *_m)
{
	init(_m->getM(), _m->getN());

	float value;
	for (int i = 0; i < m_m; ++i)
	{
		for (int j = 0; j < m_n; ++j)
		{
			value = _m->getIJ(i, j);
			setIJ(i, j, value);
		}
	}
}

void Matrix::init(int _m, int _n)
{
	m_m = _m;
	m_n = _n;
	m_size = m_m * m_n;

	m_matrix = new float[m_size];
}

Matrix::~Matrix()
{
	delete[] m_matrix;
}

/**
* Return the number of lines of the matrix
*/
int Matrix::getM()
{
	return m_m;
}

/**
* Return the number of columns of the matrix
*/
int Matrix::getN()
{
	return m_n;
}

/**
* Return the value at the line i and the column j
*/
float Matrix::getIJ(int _i, int _j)
{
	return m_matrix[_i * m_n + _j];
}

/**
* set the value at the line i and the column j
*/
void Matrix::setIJ(int _i, int _j, float _value)
{
	m_matrix[_i * m_n + _j] = _value;
}

/**
* Return a copy off the line i
*/
float* Matrix::getLine(int _i)
{
	float *line = new float[m_n];

	for (int j = 0; j < m_n; ++j)
	{
		line[j] = getIJ(_i, j);
	}

	return line;
}

/**
* Return a copy off the column j
*/
float* Matrix::getColumn(int _j)
{
	float *column = new float[m_n];
	
	for (int i = 0; i < m_m; ++i)
	{
		column[i] = getIJ(i, _j);
	}

	return column;
}

/**
* Fill the matrix with the given values
*/
void Matrix::fill(float *_values)
{
	float value;
	for (int i = 0; i < m_m; ++i)
	{
		for (int j = 0; j < m_n; ++j)
		{
			value = _values[i * m_n + j];
			setIJ(i, j, value);
		}
	}
}

/**
* Return true if the matrix equals the matrix b
*/
bool Matrix::equals(Matrix &_b)
{
	bool isEqual = true;

	if (getM() == _b.getM() && getN() == _b.getN())
	{
		int i = 0;
		while (i < getM() && isEqual)
		{
			int j = 0;
			while (j < getN() && isEqual)
			{
				if (getIJ(i, j) != _b.getIJ(i, j))
				{
					isEqual = false;
				}

				++j;
			}

			++i;
		}
	}
	else
	{
		isEqual = false;
	}

	return isEqual;
}

/**
* Add the matrix m to the matrix
*/
void Matrix::add(Matrix &m)
{
	float value;
	for (int i = 0; i < m_m; ++i)
	{
		for (int j = 0; j < m_n; ++j)
		{
			value = getIJ(i, j) + m.getIJ(i, j);
			setIJ(i, j, value);
		}
	}
}

/**
* Scale the matrix by the scalar s
*/
void Matrix::scale(float _s)
{
	float value;
	for (int i = 0; i < m_m; ++i)
	{
		for (int j = 0; j < m_n; ++j)
		{
			value = _s * getIJ(i, j);
			setIJ(i, j, value);
		}
	}
}

/**
* Print the matrix
*/
void Matrix::print()
{
	for (int i = 0; i < m_m; ++i)
	{
		std::cout << "(";

		for (int j = 0; j < m_n; ++j)
		{
			std::cout << getIJ(i, j);
			if (j < (m_n - 1))
			{
				std::cout << ", ";
			}
		}

		std::cout << ")" << std::endl;
	}
}

////////////
// STATIC //
////////////

/**
* Create and return the matrix identity Imn
*/
Matrix Matrix::Identity(int _m, int _n)
{
	Matrix identity(_m, _n);

	float value;
	for (int i = 0; i < _m; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			value = 0;
			if (j == i)
			{
				value = 1;
			}
			identity.setIJ(i, j, value);
		}
	}

	return identity;
}

Matrix Matrix::Transpose(Matrix &_m)
{
	int nbLines = _m.getN();
	int nbColumns = _m.getM();
	Matrix transpose(nbLines, nbColumns);

	float value;
	for (int i = 0; i < nbLines; ++i)
	{
		for (int j = 0; j < nbColumns; ++j)
		{
			value = _m.getIJ(j, i);
			transpose.setIJ(i, j, value);
		}
	}

	return transpose;
}

Matrix Matrix::Multiply(Matrix &_a, Matrix &_b)
{
	int nbProducts = _a.getN();

	int nbLines = _a.getM();
	int nbColumns = _b.getN();
	Matrix c(nbLines, nbColumns);

	float value;
	for (int i = 0; i < nbLines; ++i)
	{
		for (int j = 0; j < nbColumns; ++j)
		{
			value = 0;
			for (int k = 0; k < nbProducts; ++k)
			{
				value += _a.getIJ(i, k) * _b.getIJ(k, j);
			}

			c.setIJ(i, j, value);
		}
	}

	return c;
}

