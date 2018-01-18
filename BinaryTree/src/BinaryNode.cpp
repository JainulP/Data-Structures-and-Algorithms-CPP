/*
 * BinaryNode.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: jainulpatel
 */

#include "BinaryNode.h"

BinaryNode::BinaryNode(const long data)
    : data(data), height(0), left(nullptr), right(nullptr)
{
}

BinaryNode::BinaryNode(const long data, BinaryNode *left, BinaryNode *right)
  : data(data), height(0), left(left), right(right)
{
}

BinaryNode::~BinaryNode()
{
}
