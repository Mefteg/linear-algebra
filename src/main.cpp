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

	a.print();

	Log::l("main", "End");

	return 0;
}
