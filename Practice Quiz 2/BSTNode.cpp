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
template <class ElementType>
BSTNode<ElementType>::BSTNode() {
	left = nullptr;
	right = nullptr;
}

template <class ElementType>
BSTNode<ElementType>::BSTNode(ElementType element) {
	this->element = element;
	left = nullptr;
	right = nullptr;
}

template <class ElementType>
BSTNode<ElementType>::BSTNode(ElementType element, BSTNode<ElementType>* left, BSTNode<ElementType>* right) {
	this->element = element;
	this->left = left;
	this->right = right;	
}

// Boolean helper functions
template <class ElementType>
bool BSTNode<ElementType>::isLeaf() const {
	return (left == nullptr && right == nullptr);
}

template <class ElementType>
bool BSTNode<ElementType>::hasLeft() const {
	return (left != nullptr);
}

template <class ElementType>
bool BSTNode<ElementType>::hasRight() const {
	return (right != nullptr);
}