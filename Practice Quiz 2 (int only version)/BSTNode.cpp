/*
 * BSTNode.cpp
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL
 * Date of last modification: Feb. 2022
 */

#include "BSTNode.h"

// Constructors

BSTNode::BSTNode() {
	left = nullptr;
	right = nullptr;
}


BSTNode::BSTNode(int element) {
	this->element = element;
	left = nullptr;
	right = nullptr;
}


BSTNode::BSTNode(int element, BSTNode* left, BSTNode* right) {
	this->element = element;
	this->left = left;
	this->right = right;	
}

// Boolean helper functions

bool BSTNode::isLeaf() const {
	return (left == nullptr && right == nullptr);
}


bool BSTNode::hasLeft() const {
	return (left != nullptr);
}


bool BSTNode::hasRight() const {
	return (right != nullptr);
}