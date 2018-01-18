#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) :
		VectorSorter(name) {
}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {
}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string) {

	//Ref: Malik's Textbook
	for (int gap = data.size() / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < data.size(); i++) {
			Element temp = data[i];
			int j;
							j = i;
							while (j >=gap && data[j - gap] > data[j]) {
								compare_count++;
								move_count++;
								data[j] = data[j - gap];
								data[j - gap] = temp;

								j -= gap;
							}

								compare_count++;



		}
	}
}

