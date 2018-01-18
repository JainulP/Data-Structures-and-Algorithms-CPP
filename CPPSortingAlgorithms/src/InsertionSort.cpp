#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{

	//https://codereview.stackexchange.com/questions/110793/insertion-sort-in-c
	 int i,j;

	    for (i = 1; i < data.size(); i++) {
	        j = i;
	        Element tmp = data[j];
	        while (j > 0 && data[j - 1] > data[j]) {
	        	compare_count++;
	        	move_count++;
	        	data[j]= data[j-1];
	        	data[j-1] = tmp;
	            //swap(j,j-1);
	            j--;
	        }
	        if(j!=0)
	        {
	        	  compare_count++;
	        }


	    }


}


