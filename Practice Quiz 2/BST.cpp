/*
 * BST.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Jet Simon and Shadi Zoldjalali
 * Date of last modification: March 6 2022
 */

#include "BST.h"

#include <iostream>
using namespace std; //just for debugging - JET

// You can modify the implementation of these methods, but cannot modify their proptotype.
// However, if you modify the implementation of these methods, your code must still
// satisfy the documentation contract above each of these methods.

/* Constructors and destructor */

	// Default constructor
    template<class ElementType>
	BST<ElementType>::BST() {
		root = NULL;
		elementCount = 0;
	}

	// Parameterized constructor
    template<class ElementType>
    BST<ElementType>::BST(ElementType& element) {
		root = new BSTNode<ElementType>(element);
		elementCount = 1;
	}

	// wrapper function for copy constructor 
    template<class ElementType>
	BSTNode<ElementType>* copyR(BSTNode<ElementType>* current)
	{
		BSTNode<ElementType> *newtree = nullptr;
		if (current){ // if current is not null
			newtree = new BSTNode<ElementType>(current->element);
			//copy elements to the left
			newtree->left = copyR(current->left);
			//copy elements to the right
			newtree->right = copyR(current->right);
		}
		return newtree;
	}
	
    // Copy constructor
    template<class ElementType>
	BST<ElementType>::BST(const BST<ElementType>& aBST)
	{
		root = copyR(aBST->root);
	}

	// helper function for destroying
    template<class ElementType>
	void destroyR(BSTNode<ElementType>* current)
	{
		if (current){
			destroyR(current->left);
			destroyR(current->right);
			delete current;
		}
	}

	// Destructor
    template<class ElementType>
	BST<ElementType>::~BST() {
		destroyR(this->root);
    }


/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.
	// Time efficiency: O(1)
    template<class ElementType>
	unsigned int BST<ElementType>::getElementCount() const {

		return this->elementCount;
	}


/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException"
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)
    template<class ElementType>
	void BST<ElementType>::insert(const ElementType& newElement) {

	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode<ElementType>(newElement);
			elementCount++;
			return;
		}
		
		insertR(newElement, root);

  		return;
  	}

	int count = 0;

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the
	//              binary search tree. Otherwise, returns false.
    template<class ElementType>
	bool BST<ElementType>::insertR(const ElementType& anElement, BSTNode<ElementType>* current) {

		bool goingRight = anElement >= current->element; // check to see which way to go
		BSTNode<ElementType>* nextNode = goingRight ? current->right : current->left; //Maybe we should destroy this later?

		// INSERTING THE NODE
		if(nextNode == nullptr) { //If the next node is null then we can just insert it else we must either go left or right until we hit a spot to put it
			if(goingRight) {
				current->right = new BSTNode<ElementType>(anElement);
			}
			else {
				current->left = new BSTNode<ElementType>(anElement);
			}
			elementCount++;
			return true;
		}
		else 
			return insertR(anElement, nextNode); // keep traversing
	
		return true;
	}


    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException"
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
    template<class ElementType>
    ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const {

	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)
			throw EmptyDataCollectionException("Binary search tree is empty.");

		// Otherwise, search for it
		ElementType& translated = retrieveR(targetElement, root);

		return translated;
	}

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException"
	//            if "targetElement" is not found in the binary search tree.
    template<class ElementType>
    ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {

		//If where the element should be is NULL then it must not exist so throw exception
		if(current == NULL) {
			throw ElementDoesNotExistException();
		}

		//If we found the element, return it!
		if(current->element == targetElement) {
			return current->element;
		}

		//Else we need to decide which direction to go and keep callign retrieveR until we find it or know that it isn't in the tree
		bool goingRight = targetElement > current->element;
		BSTNode<ElementType>* nextNode = goingRight ? current->right : current->left;
		return retrieveR(targetElement, nextNode);

	} // end of retrieveR


    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Time efficiency: O(n)
    template<class ElementType>
	void BST<ElementType>::traverseInOrder(void visit(const ElementType&)) const {

		// Check precondition: If binary search tree is empty
		if (elementCount == 0)
			throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);

		return;
	}

    // Description: Recursive in order traversal of a binary search tree.
	template<class ElementType>
	void BST<ElementType>::traverseInOrderR(void visit(const ElementType&), BSTNode<ElementType>* current) const {

		// in order means in alpha order, so need to go in acsending order
		// if you can go left, go left, if you can't go right then left...

		//if node is null, return
		if (current == nullptr)
			return;
	
		traverseInOrderR(visit, current->left);
		visit(current->element);
		traverseInOrderR(visit, current->right);

	}

	template<class ElementType>
	int BST<ElementType>::nodesCount() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return nodesCountR(root);
	}

	template<class ElementType>
	int BST<ElementType>::nodesCountR(BSTNode<ElementType>* current) {
		if(current == NULL) return 0;

		return 1 + nodesCountR(current->left) + nodesCountR(current->right);
	}

	template<class ElementType>
	int BST<ElementType>::min() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return minR(root);
	}

	template<class ElementType>
	int BST<ElementType>::minR(BSTNode<ElementType>* current) {
		if(current->left == NULL) return current->element;

		return minR(current->left);
	}

	template<class ElementType>
	int BST<ElementType>::evenCount() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return evenCountR(root);
	}

	template<class ElementType>
	int BST<ElementType>::evenCountR(BSTNode<ElementType>* current) {
		if(current == NULL) return 0;

		int val = current->element % 2 == 0 ? 1 : 0;

		return val + evenCountR(current->left) + evenCountR(current->right);
	}

	template<class ElementType>
	int BST<ElementType>::oddCount() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return oddCountR(root);
	}

	template<class ElementType>
	int BST<ElementType>::oddCountR(BSTNode<ElementType>* current) {
		if(current == NULL) return 0;

		int val = current->element % 2 == 0 ? 0 : 1;

		return val + oddCountR(current->left) + oddCountR(current->right);
	}

	template<class ElementType>
	int BST<ElementType>::duplicateCount(const ElementType targetElement) {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return duplicateCountR(root, targetElement);
	}

	template<class ElementType>
	int BST<ElementType>::duplicateCountR(BSTNode<ElementType>* current, const ElementType targetElement) {
		if(current == NULL) return 0;

		int val = current->element == targetElement ? 1 : 0;

		return val + duplicateCountR(current->left, targetElement) + duplicateCountR(current->right, targetElement);
	}

	template<class ElementType>
	int BST<ElementType>::height() {

		if(root == NULL) return 0;

		return heightR(root, 0);
	}

	template<class ElementType>
	int BST<ElementType>::heightR(BSTNode<ElementType>* current, int currentHeight) {
		if(current == NULL) return currentHeight - 1;

		int leftHeight = heightR(current->left, currentHeight + 1);
		int rightHeight = heightR(current->right, currentHeight + 1);

		if(leftHeight > rightHeight) return leftHeight;
		return rightHeight;
		
	}

	template<class ElementType>
	int BST<ElementType>::sum() {
		return sumR(root);
	}

	template<class ElementType>
	int BST<ElementType>::sumR(BSTNode<ElementType>* current) {
		if(current == NULL) return 0;
		return current->element + sumR(current->left) + sumR(current->right);
	}

	template<class ElementType>
	double BST<ElementType>::average() {
		if(root == NULL) return 0;

		return sum() / (double)getElementCount();
	}

	template<class ElementType>
	void BST<ElementType>::printInReverseOrder() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");
		printInReverseOrderR(root);
		cout << endl;
	}

	template<class ElementType>
	void BST<ElementType>::printInReverseOrderR(BSTNode<ElementType>* current) {
		if(current == NULL) return;

		printInReverseOrderR(current->left);
		printInReverseOrderR(current->right);
		cout << current->element << " ";
	}
