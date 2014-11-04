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

// Originality: So far I have worked alone, just using our class
// notes and the book Open Data Structures by Pat Morin.

// Caroline Danzi
// 4 November 2014

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
	if (r == NULL)
		return 0;
	else
		return 1 + size(r->left) + size(r->right);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key, T>::add(Key k, T x){
	//TODO
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key, T>::remove(Key k){
	//TODO
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key, T>::find(Key k){
	// Call the other find that returns a pointer
	// to either the Node with key k or NULL
	Node<Key, T>* foundNode = find(k, root);
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

	//if (r == NULL)
	//	return r;
	//// If the key of r is greater than the key we
	//// want, we need to search the left subtree
	//else if (r->k > k)
	//	return next(k, r->left);
	//// If the key of r is equal to or less than
	//// the key we are looking for, we should search
	//// the right subtree
	//else
	//	return next(k, r->right);
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	Node<Key, T>* previous = prev(k, root);
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
	if (r == NULL){
		Node<Key, T>* newNode = new Node<Key, T>();
		newNode->k = k;
		newNode->data = x;
		return newNode;
	}
	Node<Key, T>* newSubtreeRoot;
	if (r->k < k)
		newSubtreeRoot = add(k, x, r->left);
	else
		newSubtreeRoot = add(k, x, r->right);
	return newSubtreeRoot;

}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	//TODO
	return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r == NULL)
		return NULL;
	else if (r->k == k)
		return r;
	else if (k < r->k)
		return find(k, r->left);
	else
		return find(k, r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if (r == NULL)
		return NULL;
	else if (r->right == NULL)
		return r;
	else
		return max(r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if (r == NULL)
		return NULL;
	else if (r->left == NULL)
		return r;
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

