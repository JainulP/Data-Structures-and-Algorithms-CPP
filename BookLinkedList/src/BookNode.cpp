#include "BookNode.h"
#include "Book.h"

BookNode::BookNode(Book book):book(book),next(nullptr)
{}

BookNode::~BookNode()
{}


void BookNode::setNext(BookNode *next)
{
	this->next = next;
}

Book BookNode::getBook() const
{
  return book;
}

BookNode* BookNode::getNext() const
{
  return next;
}
