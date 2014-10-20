#ifndef MATRIX_AUGMENTED_H
#define MATRIX_AUGMENTED_H

#include "log.h"
#include "matrix.h"

class MatrixAugmented : public Matrix
{
protected:
	int m_p;

	void init(int _m, int _n, int _p);

public:
	MatrixAugmented();
	MatrixAugmented(int _m, int _n, int _p);
	MatrixAugmented(Matrix *_coefficients, Matrix *_constants);
	MatrixAugmented(MatrixAugmented *_m);
	~MatrixAugmented();

	int getP();

	void toEchelon();

	void print();

	static Matrix Gauss(MatrixAugmented &_m);
};

#endif // MATRIX_AUGMENTED_H