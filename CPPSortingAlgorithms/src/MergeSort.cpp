#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) :
		ListSorter(name) {
}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {
}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm() throw (string) {
	// Defensive programming: Make sure we end up
	// with the same size list after sorting.
	int size_before = data.get_size();

	mergesort(data);

	// Check sizes.
	int size_after = data.get_size();
	if (size_before != size_after) {
		string message = "***** Size mismatch: before " + to_string(size_before)
				+ ", size after " + to_string(size_after);
		throw message;
	}
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list) {


	if (list.get_size() != 0 && list.get_size() != 1) {
		LinkedList list1;
		LinkedList list2;
		move_count++;
		list.split(list1, list2);

		mergesort(list1);  // recursively sort the first sublist
		mergesort(list2);  // recursively sort the second sublist
		move_count++;
		merge(list, list1, list2);  // merge the two sublists back together
	}
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list, LinkedList& sublist1,
		LinkedList& sublist2) {
	list.reset();
	Node* first = sublist1.get_head(); //pointer to the head node of the first list

	Node* second = sublist2.get_head(); //pointer to the head node of the second list

	while (first != nullptr && second != nullptr) {

		if (first->element.get_value() <= second->element.get_value()) //compare the first nodes
				{
			list.add(sublist1.remove_head());
			first = sublist1.get_head();
		} else {
			list.add(sublist2.remove_head());
			second = sublist2.get_head();
		}
		move_count++;
		compare_count++;
	}

	if (first != nullptr) {
		list.concatenate(sublist1);
		move_count++;
	}

	if (second != nullptr) {
		list.concatenate(sublist2);
		move_count++;
	}

}

/**
 * Clear the data.
 */
void MergeSort::clear() {
	data.clear();
}

