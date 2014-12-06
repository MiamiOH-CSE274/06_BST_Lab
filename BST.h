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

  // Recursively removes all nodes connected to root node r
  // Used in the destructor to properly destroy an entire binary search tree
  virtual void removeAllNodes(Node<Key,T>* r);

};

// Kyle Busdieker
// Prof. Bo Brinkman
// Date: November 22, 2014
// The skeleton code was created by Bo Brinkman and modified by Kyle Busdieker with help from other students, Open Data Structures textbook, and the internet.

#include <iostream>
#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){ 

	root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
	// calls removeAllNodes(Node<Key, T>* r) which will delete all nodes below the passed node r and will work its way up to deleting the passed node r
	removeAllNodes(root);
}

template <class Key, class T>
void BST<Key, T>::removeAllNodes(Node<Key, T>* r){
	
	if (r->left != NULL)
		removeAllNodes(r->left);

	if (r->right != NULL)
		removeAllNodes(r->right);

	if (r->left == NULL && r->right == NULL){
		delete r;
		r = NULL;
		return;
	}
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  // makes a call to the private size() with the root node as the parameter
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  // recursively finds the size of a tree from root r
	if (r == NULL)
		return 0;
	else
		return 1 + size(r->left) + size(r->right);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){

	root = add(k, x, root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){

	root = remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  // Calls the private find() using the provided key and the root node

	Node<Key, T> *temp = find(k, root);

	if (temp == NULL)
		throw std::string("That key does not exist.");

	return temp->data;
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  // tmpKey is set to the key of whatever node the private find() returns and if that equals k then true is returned
	return find(k, root) != NULL;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  
	Node<Key, T> * temp = next(k, root);

	if (temp == NULL)
		return k;

	return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){

	if (r == NULL)
		return NULL;

	Node<Key, T> *temp;

	if (k < r->k)
		temp = next(k, r->left);
	if (k >= r->k)
		temp = next(k, r->right);

	if (temp == NULL && r->k > k)
		return r;

	return temp;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){

	Node<Key, T> *temp = prev(k, root);

	if (temp == NULL)
		return k;

	return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	if (r == NULL)
		return NULL;

	Node<Key, T> *temp;

	if (k > r->k)
		temp = prev(k, r->right);

	if (r->k >= k)
		temp = prev(k, r->left);

	if (temp == NULL && r->k < k)
			temp = r;

	return temp;
	

}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){

	if (r == NULL) {

		r = new Node<Key, T>();
		r->k = k;
		r->data = x;
		r->left = NULL;
		r->right = NULL;

		return r;
	}

	if (r->k == k) {

		r->data = x;

		return r;
	}

	if (k < r->k) {

		Node<Key, T> *newNode = add(k, x, r->left);

		r->left = newNode;
	} else {
		Node<Key, T> *newNode = add(k, x, r->right);

		r->right = newNode;
	}

	return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
	
	if (r == NULL)
		return NULL;

	Node<Key, T> *temp;

	if (r->k == k) {

		if (r->left == NULL && r->right == NULL) {
			delete r;
			r = NULL;
			return NULL;
		}

		if (r->right != NULL)
			temp = min(r->right);
		else
			temp = max(r->left);

		Node<Key, T> moreTemp;
		moreTemp.k = temp->k;
		moreTemp.data = temp->data;

		remove(temp->k, r);

		r->k = moreTemp.k;
		r->data = moreTemp.data;

		return r;
	}

	if (r->k < k) {
		temp = remove(k, r->right);
		r->right = temp;
	} else {
		temp = remove(k, r->left);
		r->left = temp;
	}
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  // recursively looks for a node with key k
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
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  // recursively finds the max starting from node r
	if (r == NULL)
		throw std::string("Can't find that node!");
	else if (r->right == NULL)
		return r;
	else
		return max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  // recursively finds the min starting from node r
	if (r == NULL)
		throw std::string("Can't find that node!");
	else if (r->left = NULL)
		return r;
	else
		return min(r->left);
}
