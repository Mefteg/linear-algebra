#include "matrixaugmented.h"

#include <iostream>

MatrixAugmented::MatrixAugmented()
{
}

MatrixAugmented::MatrixAugmented(int _m, int _n, int _p)
{
	init(_m, _n, _p);
}

MatrixAugmented::MatrixAugmented(Matrix *_coefficients, Matrix *_constants)
{
	init(_coefficients->getM(), _coefficients->getN() + _constants->getN(), _constants->getN());

	float value;
	for (int i = 0; i < m_m; ++i)
	{
		for (int j = 0; j < (m_n - m_p); ++j)
		{
			value = _coefficients->getIJ(i, j);
			setIJ(i, j, value);
		}

		for (int k = 0; k < m_p; ++k)
		{
			value = _constants->getIJ(i, k);
			setIJ(i, (m_n - m_p + k), value);
		}
	}
}

MatrixAugmented::MatrixAugmented(MatrixAugmented *_m)
{
	init(_m->getM(), _m->getN(), _m->getP());

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

void MatrixAugmented::init(int _m, int _n, int _p)
{
	Matrix::init(_m, _n);
	m_p = _p;
}

MatrixAugmented::~MatrixAugmented()
{
}

/**
* Return the number of constant columns of the matrix
*/
int MatrixAugmented::getP()
{
	return m_p;
}

/**
* Transform the matrix to an echelon matrix
*/
void MatrixAugmented::toEchelon()
{
	// for each row
	for (int i = 0; i < m_m; ++i)
	{
		float pivot = getIJ(i, i);
		float invPivot = 1 / pivot;

		Matrix currentLine(1, m_n);
		currentLine.fill(getLine(i));

		currentLine.scale(invPivot);

		Matrix tmp(1, m_n);
		Matrix row(1, m_n);
		// for each row under the current
		for (int k = (i + 1); k < m_m; ++k)
		{
			tmp.fill(currentLine.getLine(0));

			row.fill(getLine(k));

			float coeff = row.getIJ(0, i);
			tmp.scale(coeff * -1);

			row.add(tmp);

			fillLine(k, row.getLine(0));
		}
	}
}

/**
* Print the matrix
*/
void MatrixAugmented::print()
{
	for (int i = 0; i < m_m; ++i)
	{
		std::cout << "(";

		for (int j = 0; j < (m_n - m_p); ++j)
		{
			std::cout << getIJ(i, j);
			if (j < (m_n - m_p - 1))
			{
				std::cout << ", ";
			}
		}

		std::cout << " | ";

		for (int k = (m_n - m_p); k < m_n; ++k)
		{
			std::cout << getIJ(i, k);
			if (k < (m_n - 1))
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

Matrix MatrixAugmented::Gauss(MatrixAugmented &_m)
{
	Matrix results(Matrix::Zero(_m.getM(), _m.getP()));

	MatrixAugmented copy(&_m);
	copy.toEchelon();

	int nbLines = copy.getM();
	int nbCoeffPerLine = copy.getN() - copy.getP();

	// for each row (from the bottom to the top)
	for (int i = (nbLines - 1); i >= 0; --i)
	{
		float value = 0;
		// protection against division by zero
		if (copy.getIJ(i, i) != 0) {
			// for each coeff except the one on the diagonal
			for (int k = (i + 1); k < nbCoeffPerLine; ++k)
			{
				// add the value off each variable scale by its coefficient
				value += copy.getIJ(i, k) * results.getIJ(k, 0);
			}
			// substract to the constant
			value = copy.getIJ(i, (nbCoeffPerLine)) - value;
			// divide by the coefficient of the variable on the diagonal
			value = value / copy.getIJ(i, i);
		}
		// store the result
		results.setIJ(i, 0, value);
	}

	return results;
}




