#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);

    /***** Complete this class. *****/
    ~BookNode();

    //getters
    Book getBook() const;
    BookNode* getNext() const;

    //setters for setting private variable
    void setNext(BookNode *next);


private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */
