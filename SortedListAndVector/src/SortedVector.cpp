#include <iostream>
#include <iterator>
#include <cassert>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    //inserting at first position
	 vector<Node>::const_iterator it = data.begin();
	data.insert(it,Node(value));
}

void SortedVector::append(const long value)
{
  //insering node at last position using pushback
	data.push_back(Node(value));
}

void SortedVector::remove(const int index)
{
   //removing vector element at given index using erase
	data.erase(data.begin()+ index);
}

void SortedVector::insert(const long value)
{

	 vector<Node>::const_iterator it = data.begin();
	 //calculating the position for insering an element so that vector is sorted
	 while(it != data.end() && (value> it->get_value()))
	 {
		 it++;
	 }
	 data.insert(it,Node(value));

}

Node SortedVector::at(const int index) const
{
    //returning vector element at given index
	assert(index>=0 && index< data.size());

	return data[index];

}

//reserve the vector size according to requirement
 void SortedVector::reserve(const int size)
 {
	 data.reserve(size);
 }

