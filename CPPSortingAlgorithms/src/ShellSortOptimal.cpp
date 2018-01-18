#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :
		VectorSorter(name) {
}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {
}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string) {

	//REF: Malik Textbook
	int inc;

	for (inc = 1; inc < (data.size() - 1) / 9; inc = 3 * inc + 1)
		;
	do {

		for (int begin = 0; begin < inc; begin++) {

			int i, j;

			for (i = 1; i < data.size(); i++) {
				Element temp = data[i];
				j = i;
				while (j > 0 && data[j - 1] > data[j]) {
					compare_count++;
					move_count++;
					data[j] = data[j - 1];
					data[j - 1] = temp;

					j--;
				}
				if (j != i) {
					data[j - 1] = temp;
					//move_count++;
				}

				if (j != 0) {
					compare_count++;
				}
			}
		}

		inc = inc / 3;

	} while (inc > 0);
}

