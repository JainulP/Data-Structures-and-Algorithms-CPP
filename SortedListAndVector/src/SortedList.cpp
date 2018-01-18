#include <iostream>
#include <iterator>
#include<cassert>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
	 list<Node>::iterator it = data.begin();
	 //adding element at first position
	 data.insert(it,Node(value));


}

void SortedList::append(const long value)
{
	//adding element at last position
    data.push_back(Node(value));
}

void SortedList::remove(const int index)
{
	list<Node>::iterator it = data.begin();
	//move iterator by given index to remove the element from given position
	advance(it, index);
	data.erase(it);
}

void SortedList::insert(const long value)
{
	 list<Node>::const_iterator it = data.begin();
	 //calculating the position for insering an element so that it is sorted
		 while(it != data.end() && (value> it->get_value()))
		 {
			 it++;
		 }
		 data.insert(it,Node(value));

}

Node SortedList::at(const int index)
{

	assert(index>=0 && index< data.size());

	  //returning list element at given index
	list<Node>::const_iterator it = data.begin();
			advance(it, index);
			return *it;
}
