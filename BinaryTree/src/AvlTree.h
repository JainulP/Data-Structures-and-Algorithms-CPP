/*
 * AvlTree.h
 *
 *  Created on: Nov 24, 2017
 *      Author: jainulpatel
 */

/**
 * An implementation of the AVL tree and its operations.
 * Derived from the binary search tree.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 *
 * Modified from Data Structures and Algorithm Analysis in C++, 4th ed.
 * by Mark Allen Weiss
 * Pearson, 2014
 */
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BinarySearchTree.h"

class AvlTree : public BinarySearchTree
{
public:
    /**
     * Default constructor.
     */
    AvlTree();

    /**
     * Destructor.
     */
    virtual ~AvlTree();

private:
    /**
     * Compute the height of a subtree.
     * Overrides the base class method.
     * @param ptr pointer to the root node of the subtree.
     * @return the height of the subtree.
     */
    int height(const BinaryNode *ptr) const;

    /**
     * Insert a data item into a subtree
     * and set the new root of the subtree.
     * Overrides the base class method.
     * @param data the data to insert.
     * @param ptr pointer to the root node of the subtree.
     */
    void insert(const long data, BinaryNode* &ptr);

    /**
     * Remove a data item from a subtree
     * and set the new root node of the subtree.
     * Do nothing if the data item is not found.
     * Overrides the base class method.
     * @param data the data to remove.
     * @param ptr pointer to the root node of the subtree.
     */
    void remove(const long data, BinaryNode* &ptr);

    /**
     * Rebalance the tree.
     * @param ptr pointer to the node to balance.
     * @return pointer to the balanced node.
     */
    BinaryNode *rebalance(BinaryNode* &ptr);

    /**
     * Case 1 (outside left-left): Rebalance with a single right rotation.
     * Update heights and return the new root node.
     * @param k2 pointer to the node to rotate.
     * @return pointer to the new root node.
     */
    BinaryNode *singleRightRotation(BinaryNode *k2);

    /**
     * Case 2 (inside left-right): Rebalance with a double left-right rotation.
     * @param k3 pointer to the node to rotate.
     * @return pointer to the new root node.
     */
    BinaryNode *doubleLeftRightRotation(BinaryNode *k3);

    /**
     * Case 3 (inside right-left): Rebalance with a double left rotation.
     * @param k1 pointer to the node to rotate.
     * @return pointer to the new root node.
     */
    BinaryNode *doubleRightLeftRotation(BinaryNode *k1);

    /**
     * Case 4 (outside right-right): Rebalance with a single left rotation.
     * Update heights and return the new root node.
     * @param k2 pointer to the node to rotate.
     * @return pointer to the new root node.
     */
    BinaryNode *singleLeftRotation(BinaryNode *k1);

    /**
     * Private method for a paranoid check of whether a tree node is balanced.
     * @param ptr pointer to the node to check.
     * @return the height of the node if balanced, -1 if the node is null,
     *         or -2 if unbalanced.
     */
    int checkBalance(BinaryNode *ptr);
};

#endif // AVL_TREE_H
