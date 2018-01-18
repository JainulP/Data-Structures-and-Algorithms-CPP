#include "BookList.h"
#include <iostream>
#include <string>

using namespace std;

BookList::BookList(const string name) :
		name(name), head(nullptr), tail(nullptr) {

}

void BookList::print() {
	BookNode *tmp;
	tmp = head;
	cout << "Book list: " << name << endl << endl;
	int count = 0;

	while (tmp != nullptr) {
		cout << tmp->getBook() << endl;
		tmp = tmp->getNext();
		count++;
	}
	cout << "    (" << count << " books)" << endl;
// 	cout << endl;
}

void BookList::addBook(BookList& bookList, Book book) {
	BookNode *node = new BookNode(book);

	// First node of the list.
	if (head == nullptr) {
		head = node;
	}
	// Insert at the first position
	else if (node->getBook().get_isbn() < head->getBook().get_isbn()) {
		node->setNext(head);
		head = node;
	} else {
		BookNode *current = head;  // pointer to iterate through the list
		BookNode *prev;        // pointing to previous booknode

		while ((current != nullptr)
				&& (node->getBook().get_isbn() > current->getBook().get_isbn())) {
			prev = current;
			current = current->getNext();

		}

		if ((current != nullptr)
				&& (node->getBook().get_isbn() == current->getBook().get_isbn())) {
			node = nullptr;
			//node->setNext(nullptr);
		} else {
			prev->setNext(node);
			node->setNext(current);
		}

	}

}

void BookList::splitList(BookList& mergedbookList, BookList& splittedbookList,
		string start, string end) {
	BookNode *tmp;
	tmp = head;

	while (tmp != nullptr) {
		string lastname = tmp->getBook().get_last();
		lastname.substr(1, 1);
		string firstchar = lastname.substr(0, 1);
		//cout<< firstchar <<endl;
		if (firstchar >= start && firstchar <= end) {
			splittedbookList.addBook(splittedbookList, tmp->getBook());
		}
		tmp = tmp->getNext();

	}

}
