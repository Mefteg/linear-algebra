#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
	int m_m;
	int m_n;
	int m_size;
	float *m_matrix;

public:
	Matrix(int _m, int _n);
	~Matrix();

	float getIJ(int _i, int _j);
	void setIJ(int _i, int _j, float _value);
	void fill(float *_values);

	void add(Matrix &m);

	void print();

	static Matrix Identity(int _m, int _n);
};

#endif // MATRIX_H