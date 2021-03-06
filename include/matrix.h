#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
	int m_id;
	int m_m;
	int m_n;
	int m_size;
	float *m_matrix;

	static int ID;

	void init(int _m, int _n);

public:
	Matrix();
	Matrix(int _m, int _n);
	Matrix(Matrix *_matrix);
	~Matrix();

	int getId();
	int getM();
	int getN();
	float getIJ(int _i, int _j);
	void setIJ(int _i, int _j, float _value);
	float* getLine(int _i);
	float* getColumn(int _j);

	void fill(float *_values);
	void fillLine(int _i, float *_values);

	bool equals(Matrix &_b);

	void add(Matrix &matrix);
	void scale(float _s);

	void print();

	static Matrix Zero(int _m, int _n);
	static Matrix Identity(int _m, int _n);

	static Matrix Transpose(Matrix &_matrix);

	static Matrix Multiply(Matrix &_a, Matrix &_b);
};

#endif // MATRIX_H