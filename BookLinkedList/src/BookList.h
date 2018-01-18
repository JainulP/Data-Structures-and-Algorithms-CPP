#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "BookNode.h"

using namespace std;


/**
 * A list of book nodes.
 */
class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    /**
     * Print the list.
     */
    void print();

    /**
	 * Adds the book in the list which are sorted by isbn
	 */
    void addBook(BookList& bookList, Book book);

    /**
	 * splits the merged list according to author's last names initials given in start and end parameters
	 */
    void splitList(BookList& mergedbookList,BookList& splittedbookList,string start, string end);

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
