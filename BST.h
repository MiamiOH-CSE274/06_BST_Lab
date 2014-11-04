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

};

#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST(){
	Node<Key, T>* root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	delete root;
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
	if (r == NULL)
		return r;
	// If the key of r is greater than the key we
	// want, we need to search the left subtree
	else if (r->k > k)
		return next(k, r->left);
	// If the key of r is equal to or less than
	// the key we are looking for, we should search
	// the right subtree
	else
		return next(k, r->right);
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	//TODO
	return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	//TODO
	return NULL;
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	//TODO
	return NULL;
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

