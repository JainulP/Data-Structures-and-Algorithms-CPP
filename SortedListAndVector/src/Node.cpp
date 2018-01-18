#include <iostream>
#include "Node.h"

using namespace std;

/***** Complete this file. *****/

long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

Node::Node(const long the_value):value(the_value)
{
   constructor_count++;
}

Node::~Node()
{
   destructor_count++;
}

Node::Node(const Node& other)
{
	value = other.value;

   copy_count++;

}

long Node::get_value() const
{
   return value;
}
 long Node::get_constructor_count()
{
	 //return 0;
   return constructor_count;
}
 long Node::get_copy_count()
{
	 //return 0;
  return copy_count;
}
 long Node::get_destructor_count()
{
	 //return 0;
   return destructor_count;
}
void Node::reset()
{
   constructor_count = 0;
  copy_count =0;
   destructor_count =0;
}

bool Node::operator ==(const Node& other) const
{
	if(value == other.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Node::operator  >(const Node& other) const
{
  if(value> other.value)
  {
	  return true;
  }
  else
  {
	  return false;
  }
}
