
#include <iostream>
#include "Element.h"

using namespace std;


long Element::copy_count;
long Element::destructor_count;
/***** Complete this class. *****/

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    /***** Complete this class. *****/
	*this = other;
	copy_count ++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    /***** Complete this class. *****/
	destructor_count ++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

long Element:: get_copy_count(){
	return copy_count;
}

long Element:: get_destructor_count(){
	return destructor_count;
}

void Element:: reset(){
	copy_count = 0;
	destructor_count = 0;
}

bool Element:: operator  <(const Element& other) const{
	if(value < other.value) return true;
	else return false;
}

bool Element:: operator  >(const Element& other) const{
	if(value > other.value) return true;
	else return false;
}

ostream& operator <<(ostream& outs, const Element& elmnt){
	outs << elmnt.value;
	return outs;
}










