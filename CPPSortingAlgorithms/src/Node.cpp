

#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/

Node::Node(){

}

Node::Node(Element elmnt){
	element = elmnt;
}

void Node::setNext(Node *next)
{
	this->next = next;
}


Node* Node::getNext() const
{
  return next;
}
