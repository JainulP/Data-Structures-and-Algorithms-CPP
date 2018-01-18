///*
// * BinarySearchTree.cpp
// *
// *  Created on: Nov 24, 2017
// *      Author: jainulpatel
// */
//
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

BinaryNode *BinarySearchTree::getRoot() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
	if (ptr == nullptr)
	return -1;
	else
		return 1+ max(height(ptr->left), height(ptr->right));
}

long BinarySearchTree::findMin() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMin(root)->data;
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *ptr) const
{


	if(ptr->left == nullptr)
	{
		return ptr;
	}
	else
	{
		 return findMin(ptr->left);
	}


}

long BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMax(root)->data;
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *ptr) const
{
	if(ptr->right == nullptr)
		{
			return ptr;
		}
		else
		{
			return findMax(ptr->right);
		}

}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
	if(ptr != nullptr) {
		    clear(ptr->left);
		    clear(ptr->right);
		    delete ptr;
		    ptr = nullptr;
		}
}

bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const long data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const long data, BinaryNode *ptr) const
{
	if(ptr == nullptr) return false;

		if(ptr->data == data) return true;
		else {
		    if(data < ptr->data)
			return contains(data, ptr->left);
		    else
			return contains(data, ptr->right);
		}

}

void BinarySearchTree::insert(const long data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const long data, BinaryNode* &ptr)
{
//    cout << "=== Insert called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;

	//website reference: geeksforgeeks

	  /* If the tree is empty, return a new node */
	    if (ptr == nullptr)
	    	{
	    		ptr = new BinaryNode(data);
	    	}

	    /* Otherwise, recur down the tree */
	    else if (data < ptr->data)
	    {
	        insert(data, ptr->left);
	    }
	    else if (data > ptr->data)
	    {
	        insert(data, ptr->right);
	    }

}

void BinarySearchTree::remove(const long data)
{
    remove(data, root);
}


//website reference: geeksforgeeks
void BinarySearchTree::remove(const long data, BinaryNode* &ptr)
{
//    cout << "=== Remove called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;


	//base case
	if (ptr == nullptr) return;

	    // If the value is less than root's value then it is in left subtree
	    if (data < ptr->data)
	       remove(data,ptr->left);

	    // If the value is greater than root's value then it is in right subtree
	    else if (data > ptr->data)
	        remove(data,ptr->right);

	    //if value is equal to root's value then delete node
	    else if (ptr->left == nullptr || ptr->right == nullptr)
	    {

	        // node with only one child or no child
	    	 BinaryNode *temp = ptr;
	         (ptr->left == nullptr) ? (ptr = ptr->right): (ptr = ptr->left);
	         delete temp;
	    }
	    else
	   	         {
	    	  // Remove a target node with two children.
	   	        	   ptr->data = findMin(ptr->right)->data;
	   	        	   remove(ptr->data,ptr->right);
	   	         }

}
