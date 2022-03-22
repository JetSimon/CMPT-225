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
    
	BST::BST() {
		root = NULL;
		elementCount = 0;
	}

	// Parameterized constructor
    
    BST::BST(int& element) {
		root = new BSTNode(element);
		elementCount = 1;
	}

	// wrapper function for copy constructor 
    
	BSTNode* copyR(BSTNode* current)
	{
		BSTNode *newtree = nullptr;
		if (current){ // if current is not null
			newtree = new BSTNode(current->element);
			//copy elements to the left
			newtree->left = copyR(current->left);
			//copy elements to the right
			newtree->right = copyR(current->right);
		}
		return newtree;
	}
	
    // Copy constructor
    
	BST::BST(const BST& aBST)
	{
		root = copyR(aBST.root);
	}

	// helper function for destroying
    
	void destroyR(BSTNode* current)
	{
		if (current){
			destroyR(current->left);
			destroyR(current->right);
			delete current;
		}
	}

	// Destructor
    
	BST::~BST() {
		destroyR(this->root);
    }


/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.
	// Time efficiency: O(1)
    
	unsigned int BST::getElementCount() const {

		return this->elementCount;
	}


/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException"
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)
    
	void BST::insert(const int& newElement) {

	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode(newElement);
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
    
	bool BST::insertR(const int& anElement, BSTNode* current) {

		bool goingRight = anElement >= current->element; // check to see which way to go
		BSTNode* nextNode = goingRight ? current->right : current->left; //Maybe we should destroy this later?

		// INSERTING THE NODE
		if(nextNode == nullptr) { //If the next node is null then we can just insert it else we must either go left or right until we hit a spot to put it
			if(goingRight) {
				current->right = new BSTNode(anElement);
			}
			else {
				current->left = new BSTNode(anElement);
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
    
    int& BST::retrieve(const int& targetElement) const {

	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)
			throw EmptyDataCollectionException("Binary search tree is empty.");

		// Otherwise, search for it
		int& translated = retrieveR(targetElement, root);

		return translated;
	}

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException"
	//            if "targetElement" is not found in the binary search tree.
    
    int& BST::retrieveR(const int& targetElement, BSTNode* current) const {

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
		BSTNode* nextNode = goingRight ? current->right : current->left;
		return retrieveR(targetElement, nextNode);

	} // end of retrieveR


    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Time efficiency: O(n)
    
	void BST::traverseInOrder(void visit(const int&)) const {

		// Check precondition: If binary search tree is empty
		if (elementCount == 0)
			throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);

		return;
	}

    // Description: Recursive in order traversal of a binary search tree.
	
	void BST::traverseInOrderR(void visit(const int&), BSTNode* current) const {

		// in order means in alpha order, so need to go in acsending order
		// if you can go left, go left, if you can't go right then left...

		//if node is null, return
		if (current == nullptr)
			return;
	
		traverseInOrderR(visit, current->left);
		visit(current->element);
		traverseInOrderR(visit, current->right);

	}

	
	int BST::nodesCount() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return nodesCountR(root);
	}

	
	int BST::nodesCountR(BSTNode* current) {
		if(current == NULL) return 0;

		return 1 + nodesCountR(current->left) + nodesCountR(current->right);
	}

	
	int BST::min() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return minR(root);
	}

	
	int BST::minR(BSTNode* current) {
		if(current->left == NULL) return current->element;

		return minR(current->left);
	}

	
	int BST::evenCount() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return evenCountR(root);
	}

	
	int BST::evenCountR(BSTNode* current) {
		if(current == NULL) return 0;

		int val = current->element % 2 == 0 ? 1 : 0;

		return val + evenCountR(current->left) + evenCountR(current->right);
	}

	
	int BST::oddCount() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return oddCountR(root);
	}

	
	int BST::oddCountR(BSTNode* current) {
		if(current == NULL) return 0;

		int val = current->element % 2 == 0 ? 0 : 1;

		return val + oddCountR(current->left) + oddCountR(current->right);
	}

	
	int BST::duplicateCount(const int targetElement) {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");

		return duplicateCountR(root, targetElement);
	}

	
	int BST::duplicateCountR(BSTNode* current, const int targetElement) {
		if(current == NULL) return 0;

		int val = current->element == targetElement ? 1 : 0;

		return val + duplicateCountR(current->left, targetElement) + duplicateCountR(current->right, targetElement);
	}

	
	int BST::height() {

		if(root == NULL) return 0;

		return heightR(root, 0);
	}

	
	int BST::heightR(BSTNode* current, int currentHeight) {
		if(current == NULL) return currentHeight - 1;

		int leftHeight = heightR(current->left, currentHeight + 1);
		int rightHeight = heightR(current->right, currentHeight + 1);

		if(leftHeight > rightHeight) return leftHeight;
		return rightHeight;
		
	}

	
	int BST::sum() {
		return sumR(root);
	}

	
	int BST::sumR(BSTNode* current) {
		if(current == NULL) return 0;
		return current->element + sumR(current->left) + sumR(current->right);
	}

	
	double BST::average() {
		if(root == NULL) return 0;

		return sum() / (double)getElementCount();
	}

	
	void BST::printInReverseOrder() {
		if(root == NULL) throw EmptyDataCollectionException("Binary search tree is empty.");
		printInReverseOrderR(root);
		cout << endl;
	}

	
	void BST::printInReverseOrderR(BSTNode* current) {
		if(current == NULL) return;

		printInReverseOrderR(current->left);
		printInReverseOrderR(current->right);
		cout << current->element << " ";
	}
