#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
	int m_m;
	int m_n;
	int m_size;
	float *m_matrix;

private:
	void init(int _m, int _n);

public:
	Matrix();
	Matrix(int _m, int _n);
	Matrix(Matrix *_m);
	~Matrix();

	int getM();
	int getN();
	float getIJ(int _i, int _j);
	void setIJ(int _i, int _j, float _value);
	float* getLine(int _i);
	float* getColumn(int _j);

	void fill(float *_values);

	bool equals(Matrix &_b);

	void add(Matrix &m);
	void scale(float _s);

	void print();

	static Matrix Identity(int _m, int _n);

	static Matrix Transpose(Matrix &_m);

	static Matrix Multiply(Matrix &_a, Matrix &_b);
};

#endif // MATRIX_H