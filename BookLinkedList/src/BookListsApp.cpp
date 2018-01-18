//============================================================================
// Name        : Week7BookLinkedList.cpp
// Author      : Jainul Patel
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <string>
#include <iostream>
#include <fstream>
#include "Book.h"
#include "BookList.h"
using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

/**
 * The main. Create and print the book lists.
 */
int main() {

//file stream reads categories from the file
	ifstream input;
	input.open(CATEGORIES_FILE_NAME);
	if (input.fail()) {
		cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
		return -1;
	}
	string category;

	BookList mergedList("MERGED");

	while ((input >> category).good()) {

		//inputcategory reads values from each category file
		ifstream inputCategory;
		string filename = category + ".txt";
		BookList booklist(category);

		inputCategory.open(filename);
		if (inputCategory.fail()) {
			cout << "Failed to open " << filename << endl;
			return -1;
		}
		Book book;

		while ((inputCategory >> book).good()) {
			//reading book from file and storing it to linked list
			booklist.addBook(booklist, book);
			mergedList.addBook(mergedList, book);
		}

		cout << endl;
		booklist.print();
		inputCategory.close();
	}

	input.close();
	cout << endl;
	mergedList.print();

	//splitting the list for last name of author
	BookList bookListAM("AUTHORS A-M");
	mergedList.splitList(mergedList, bookListAM, "A", "M");
	cout << endl;
	bookListAM.print();


	BookList bookListNZ("AUTHORS N_Z");
	mergedList.splitList(mergedList, bookListNZ, "N", "Z");
	cout << endl;
	bookListNZ.print();

	return 0;
}

