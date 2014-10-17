  #include <log.h>

  #include <matrix.h>

//////////
// MAIN //
//////////

int main() {
	Log::l("main", "Begin");

	Matrix identity = Matrix::Identity(2, 2);

	Matrix a(2, 2);
	float values[4] = {0, 1, 2, 3};

	a.fill(values);

	a.add(identity);
	a.scale(2);

	Log::l("main", "Matrix a");
	a.print();

	Matrix aCopy(&a);

	Log::l("main", "Matrix aCopy");
	aCopy.print();

	Matrix aTrans = Matrix::Transpose(a);

	Log::l("main", "Matrix aTrans");
	aTrans.print();

	Matrix b(2, 1);
	float *bValues = a.getColumn(0);
	b.fill(bValues);
	delete[] bValues;

	Log::l("main", "Matrix b");
	b.print();

	Matrix c = Matrix::Multiply(a, b);
	Log::l("main", "Matrix c");
	c.print();

	if (b.equals(c))
	{
		Log::l("main", "EQUALS :)");
	}
	else
	{
		Log::l("main", "NOT EQUALS :(");
	}

	Log::l("main", "End");

	return 0;
}
