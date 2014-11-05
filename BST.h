//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/10/01

#include "SSet.h"

template <class Key, class T>
class Node {
public:
  Key k;
  T data;
  Node* left;
  Node* right;
};

template <class Key, class T>
class BST : public SSet <Key,T> {
 public:
  BST();
  ~BST();
  
  //Return the number of items currently in the SSet
  virtual unsigned long size();

  //Add a new item, x, with Key k.
  // If an item with Key k already exists, overwrite it
  virtual void add(Key k, T x);

  //Remove the item with Key k. If there is no such item, do nothing.
  virtual void remove(Key k);

  //Return the item with Key k. 
  // If there is no such item, throw an exception.
  virtual T find(Key k);
  //Return true if there is an item with Key k in the table. If not,
  // return false
  virtual bool keyExists(Key k);

  //If there is a key in the set that is > k,
  // return the first such key. If not, return k
  virtual Key next(Key k);
  //If there is a key in the set that is < k,
  // return the first such key. If not, return k
  virtual Key prev(Key k);

private:
  Node<Key,T>* root;

  virtual unsigned long size(Node<Key,T>* r);
  //These are the recursive versions of each of your methods.
  // You should return the address of the new root node, whether
  // or not the root node changes.
  virtual Node<Key,T>* add(Key k, T x, Node<Key,T>* r);
  virtual Node<Key,T>* remove(Key k, Node<Key,T>* r);

  //This one returns the address of the found node, NULL
  // if not found
  virtual Node<Key,T>* find(Key k, Node<Key,T>* r);

  //Find the item in the sub-tree rooted at r which has the smallest key
  virtual Node<Key,T>* min(Node<Key,T>* r);

  //Find the item in the sub-tree rooted at r which has the largest key
  virtual Node<Key,T>* max(Node<Key,T>* r);

  //Find the next/prev node, and return its address
  virtual Node<Key,T>* next(Key k, Node<Key,T>* r);
  virtual Node<Key,T>* prev(Key k, Node<Key,T>* r);

  // Recursive method that removes all nodes
  virtual void removeAll(Node<Key, T>* r);

};

/* Originality: I used what we discussed in class and notes from
* the book Open Data Structures by Pat Morin. I worked with
* Aryelle Player discuss the recursion of next, prev, and add. 
* We drew pictures on a whiteboard what the methods should do and
* wrote some psuedo code. I only looked at Aryelle's code once to
* help her figure out an error message.
*
* Caroline Danzi
* 4 November 2014
*/

#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	// Call the private method that deletes all nodes
	// in the tree, including the root
	removeAll(root);
	// To be honest, I am not sure if removeAll actually
	// sets root to NULL. I think it might, but just in
	// case I put this in
	root = NULL;
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	// If we reach the bottom of the tree, there
	// is not a node here so return zero
	if (r == NULL)
		return 0;
	// Otherwise, return one plus the size of r's
	// left subtree plus the size of r's right
	// subtree. The one added here makes sure 
	// r is counted.
	else
		return 1 + size(r->left) + size(r->right);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key, T>::add(Key k, T x){
	add(k, x, root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key, T>::remove(Key k){
	remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key, T>::find(Key k){
	// Call the other find that returns a pointer
	// to either the Node with key k or NULL
	Node<Key, T>* foundNode = find(k, root);
	// If the node is not there, throw an exception
	if (foundNode == NULL)
		throw std::string("No such element exists");
	else
		return foundNode->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	// If find reached the end of the tree,
	// it will return NULL and thus the 
	// key does not exist
	if (find(k, root) == NULL)
		return false;
	else
		return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	// Find the next node using the other
	// next function
	Node<Key, T>* nextNode = next(k, root);
	// If there is no next node, return the same key
	if (nextNode == NULL)
		return k;
	// Otherwise, return the key of the next node
	else
		return nextNode->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
	// Base case: if r is NULL, we have reached a leaf
	// and thus the next cannot be here
	if (r == NULL)
		return NULL;
	// Create a variable to store what we think
	// the current next value is
	Node<Key, T>* currentNext;
	// If r's key is greater than k, we should
	// search for the next in the left subtree
	if (r->k > k)
		currentNext = next(k, r->left);
	// If r's key is less than or equal to k,
	// we should search the right subtree for next
	if (r->k <= k)
		currentNext = next(k, r->right);

	// Now that we have the current next node,
	// we should check to see if r is a better
	// candidate for the next
	if (currentNext == NULL && r->k > k)
		currentNext = r;

	// After all this checking and searching,
	// return the current next
	return currentNext;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	// Find the previous using the private function
	Node<Key, T>* previous = prev(k, root);
	// If there is no previous, return k
	if (previous == NULL)
		return k;
	else
		return previous->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	// Base case: if r is NULL, it cannot be
	// the previous, so return NULL
	if (r == NULL)
		return NULL;
	// Create a variable to store what we currently
	// think the previous value is
	Node<Key, T>* currentPrev;
	// If r's key is less than k, the we should look
	// in the right subtree for prev
	if (r->k < k)
		currentPrev = prev(k, r->right);
	// If r's key is greater than or equal to k,
	// look in the left subtree for prev
	if (r->k >= k)
		currentPrev = prev(k, r->left);
	// Once we have a potential value for prev,
	// we should check if r is a better value.
	// Specifically, if r is NULL that means 
	// we have not yet found the prev, so check
	// if I am the prev
	if (currentPrev == NULL && r->k < k)
		currentPrev = r;
	// Finally, we should return the currentPrev
	return currentPrev;
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	// If r is null, we have reached a spot where
	// we can add the new node with key k and data x
	if (r == NULL){
		// We need to create a new node that has
		// key k, data x, and left and right set to NULL
		Node<Key,T>* newNode = new Node<Key, T>();
		newNode->k = k;
		newNode->data = x;
		newNode->right = NULL;
		newNode->left = NULL;
		// If there is no root node, this new node will
		// be the root node
		if (root == NULL)
			root = newNode;
		// Return this node so that the caller can adjust
		// their pointer to point to it
		return newNode;
	}
	// If k already exists, just change the data
	if (r->k == k)
		r->data = x;
	// If r's key is greater than k, that means we 
	// need to search the left subtree for a place
	// to add since k is smaller.
	if (r->k > k)
		r->left = add(k, x, r->left);
	// If r's key is less than k, we should search
	// the right subtree for a place to add
	if (r->k < k)
		r->right = add(k, x, r->right);
	// Return a pointer to r - since the left and
	// right pointers for r may have been updated,
	// the root of the subtree (r) may have changed
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	// If there are no items, do nothing
	if (r == NULL)
		return NULL;

	// If r's key is less than k, we should look for k
	// in the right subtree
	if (r->k < k)
		r->right = remove(k, r->right);
	// If r's key is too big, look for k in the left subtree
	if (r->k > k)
		r->left = remove(k, r->left);
	// Once we find the node with the correct key, we 
	// need to remove it. However, there are three cases
	// we nee dto consider.
	if (r->k == k){
		// In the first case, r has no children,
		// so we can just delete r and return NULL
		if (r->left == NULL && r->right == NULL){
			delete r;
			r = NULL;
			return r;
		}
		// In the second case, r has one child. We need
		// to delete r and then return its child so 
		// the caller can update its pointer
		else if (r->left != NULL && r->right == NULL){
			Node<Key, T>* tempChild = r->left;
			delete r;
			r = NULL;
			return tempChild;
		}
		else if (r->left == NULL && r->right != NULL){
			Node<Key, T>* tempChild = r->right;
			delete r;
			r = NULL;
			return tempChild;
		}
		// In the third case, r has two children. Here we
		// should replace r with the max of its left subtree.
		// This keeps the correct order of keys, while then
		// moving the node we need to remove to a place where
		// it can be handled by one of the earlier cases.
		else{
			// Find the max of the left subtree
			Node<Key, T>* maxLeft = max(r->left);
			// Create a temporary node to store the key and value for maxLeft
			Node<Key, T>* tempMax = new Node<Key, T>();
			tempMax->k = maxLeft->k;
			tempMax->data = maxLeft->data;
			// Change maxLeft's key and value to that of r
			maxLeft->k = r->k;
			maxLeft->data = r->data;
			// Change r's key and value to that of maxLeft
			r->k = tempMax->k;
			r->data = tempMax->data;

			// Delete the temporary node to prevent memory leaks and 
			// dangling pointers
			delete tempMax;
			tempMax = NULL;

			// Call remove on the new r, so it will go find the 
			// node with key k, which has been moved to a place
			// where it is an easier case
			remove(k, r);
		}
	}
	// Return a pointer to the root of the new subtree
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	// If r is ever null, key k is not in the tree
	// and we should return NULL to reflect that
	if (r == NULL)
		return NULL;
	// If r's key is equal to k, then we have
	// found k and should return r
	else if (r->k == k)
		return r;
	// If k is less than r's key, we should
	// look r's left subtree 
	else if (k < r->k)
		return find(k, r->left);
	// Otherwise, search the right subtree
	else
		return find(k, r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	// If r is ever null, there is no max
	if (r == NULL)
		return NULL;
	// If the right child of r is NULL,
	// we have reached the max (there is no key
	// larger than r's key) so we should return r
	else if (r->right == NULL)
		return r;
	// Otherwise, we should continue to search
	// the keys larger than r, which are in r's
	// right subtree
	else
		return max(r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	// If r is NULL, there is no min (there
	// are no nodes in the tree)
	if (r == NULL)
		return NULL;
	// If r's left child is NULL, then r must 
	// be the min since there is nothing
	// smaller than r
	else if (r->left == NULL)
		return r;
	// Otherwise, we should search nodes with smaller
	// keys than r, which are located in r's left subtree
	else
		return min(r->left);
}

template <class Key, class T>
void BST<Key, T>::removeAll(Node<Key, T>* r){
	// Base case: if the root we are calling on
	// is actually NULL, return
	if (r == NULL)
		return;
	else{
		// post-order traversal
		removeAll(r->left);
		removeAll(r->right);
		// After traversing r's left and right
		// subtrees, we should delete r and get
		// rid of the resulting dangling pointer
		delete r;
		r = NULL;
	}
}


