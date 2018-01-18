#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};
const string INPUT_FILE_NAME = "commands.in";

string error_msg;

/**
 * Executes the addition or search or removal of book from the catalog
 * @param command is either +, ? or -
 * @param bookList the vector of books.
 * @param input is the input read from a file
 * @prints the book matching the search criteria
 */
void executeCommand(const char command, istream &input,vector<Book>& bookList);

//Prints all the books in catalog
void print_all_books(const vector<Book>& bookList);

/**
 * Find the book in the catalog with the given search criteria.
 * Use a linear search.
 * @param search is either author last name or category.
 * @param catalog the vector of book records.
 * @prints the book matching the search criteria
 */
void findBook(const string search, const string value, vector<Book>& bookList);

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, vector<Book>& catalog);

int main() {

	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail()) {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}
	vector<Book> catalog;//book ctalog

	catalog.reserve(10);
	char command;
	input >> command;//read the first command


	/**
     * Loop to read commands until the end of file.
     */
	while (!input.eof()) {
		cout << endl << command << " ";
		executeCommand(command, input, catalog); // execute the current command
		cout << endl;
		input >> command;  // reading the next command

	}

}

void executeCommand(const char command, istream &input,
		vector<Book>& bookList) {

	Book book;
	int index = 0;
	string isbn = "";
	string currIsbn = "";


	switch (command) {

	//add the book into the catalog
	case '+': {
		input >> book;

		isbn = book.get_isbn();
		string strIsbn = isbn.erase(4, 1);
		long intIsbn = stol(strIsbn);

		//if it is an empty vector then add first book to the vector
		if (bookList.size() == 0) {

			bookList.push_back(book);
			index = 0;
			cout << "Inserted at index " << index << ": " << book;
			error_msg = " ";
			return;

		}

		//insert the book by sorting the isbn. add the book at the position where isbn is greater than the previously added record
		while ((index < bookList.size())
				&& (intIsbn > stol((bookList[index].get_isbn()).erase(4, 1))))
			index++;

		currIsbn = (bookList[index].get_isbn());
		if (currIsbn.size() > 1) {
			string newStr = currIsbn.erase(4, 1);
		}

		//if book with the same isbn already exists in the catalog then print the error msg
		if (isbn == currIsbn) {

			error_msg = "*** Duplicate ISDN ***";
			book = bookList[index];
			cout << "Inserted at index " << index << ": " << book << endl
					<< error_msg;
		} else {

			// Inserting into a vector at position = index.
			bookList.insert(bookList.begin() + index, book);
			book = bookList[index];
			cout << "Inserted at index " << index << ": " << book;
			error_msg = "";

		}
		break;
	}


	case '?': {

		string searchCriteria;
		input >> searchCriteria;

		if (searchCriteria == "?") {
			print_all_books(bookList);
			input >> searchCriteria;
			cout << endl << "? ";
		}
		//if only "?" as input then print all the books in the catalog
		if (searchCriteria == "") {
			print_all_books(bookList);

		}
		string search = searchCriteria.substr(0, searchCriteria.find("="));
		string value = searchCriteria.substr((searchCriteria.find("=")) + 1);
		findBook(search, value, bookList);

		break;
	}

	//Removes the book by isbn number
	case '-': {
		int index = 0;
		int count = 0;
		string isbn;
		input >> isbn;

		cout << "Removed ";
		for (Book book : bookList) {

			string bookIsbn = book.get_isbn();

			if ((" " + isbn) == bookIsbn) {
				count++;
				cout << book;
				bookList.erase(bookList.begin() + index);

			}
			index++;

		}

		//if book with the isbn number not found in the catalog then print the error msg
		if (count == 0) {
			error_msg = "*** Book not found ***";
			cout << "Book{ISBN=" << isbn
					<< ", last=, first=, title=, category=none}" << endl
					<< error_msg;

		}
		break;
	}

	//for invalid command print the error msg
	case '$': {
		error_msg = "*** Invalid command ***";
		cout << error_msg;
		string jkl;
		input >> jkl;
		break;
	}
	default:
		input >> isbn;
		break;
	}

}

void print_all_books(const vector<Book>& bookList) {

	cout << "All books in the catalog: ";

	// printing each book record in the booklist vector.
	for (int index = 0; index < bookList.size(); index++) {
		cout  <<endl<<bookList[index];
	}
	cout <<endl;
}

void findBook(const string search, const string value, vector<Book>& bookList) {
//if search criteria is author then iterate the catalog and compare last name of author
	if (search == "author")
	{
		cout << "Books by " << search << " " << value << ":";
		for (Book book : bookList) {
			if (value == book.get_last()) {
				cout <<endl<< book ;
			}
		}
	}

	//if search criteria is category then iterate the catalog and compare book category
	Book::Category cat;
	if (search == "category") {

		if (value == "fiction") {
			cat = Book::Category::FICTION;
		} else if (value == "history") {
			cat = Book::Category::HISTORY;
		} else if (value == "technical") {
			cat = Book::Category::TECHNICAL;
		} else {
			cat = Book::Category::NONE;
		}

		cout << "Books in " << search << " " << value << ":";
		for (Book book : bookList) {

			if (cat == book.get_category()) {
				cout << endl<<book;
			}

		}
	}

	//if search criteria is isbn then use binary search
	if (search == "isbn") {

		string str = " " + value;
		int indexof = find(str,bookList);
		if(indexof>0)
		{
			cout << "Book with ISBN " << value << ":" << endl;
			cout << bookList[indexof];
		}
		else
		{
			cout << "Book with ISBN " << value << ":";
		}
	}
}


int find(const string isbn, vector<Book>& catalog)
{

	//using binary search algorithm to find the book with given isbn in the catalog
int low = 0;
int high = catalog.size();
	while (low <= high) {
	        int mid = (low + high)/2;

	        if (isbn == catalog[mid].get_isbn()) {
	            return mid;
	        }
	        else if (isbn < catalog[mid].get_isbn()) {
	            high = mid-1;
	        }
	        else {
	            low = mid+1;
	        }
	    }

	    return -1;

}

