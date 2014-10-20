#include <log.h>

#include <matrix.h>
#include <matrixaugmented.h>

//////////
// MAIN //
//////////

int main() {
	Log::l("main", "Begin");

	//Matrix a(2, 2);
	//float aValues[4] = {4, 5, 2, 7};
	Matrix a(4, 4);
	float aValues[] = {2, -4, 1, -3, 4, 16, -3, 1, 6, -2, -5, 1, -2, -8, 1, -1};
	a.fill(aValues);

	Log::l("main", "Matrix a");
	a.print();

	//Matrix b(2, 1);
	//float bValues[] = {8, 3};
	Matrix b(4, 1);
	float bValues[] = {6, -10, -3, 0};
	b.fill(bValues);

	Log::l("main", "Matrix b");
	b.print();

	MatrixAugmented augmented(&a, &b);

	Log::l("main", "MatrixAugmented augmented");
	augmented.print();

	Matrix results = MatrixAugmented::Gauss(augmented);
	Log::l("main", "Matrix results");
	results.print();

	Matrix verify = Matrix::Multiply(a, results);
	Log::l("main", "Matrix verify");
	verify.print();

	Log::l("main", "End");

	return 0;
}
