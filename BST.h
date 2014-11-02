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

#include <string>
#include <iostream>

#define NULL 0

template <class Key, class T>
BST<Key, T>::BST()
{
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST()
{
	//TODO
}
  
// Return the number of items currently in the SSet
template <class Key, class T>
unsigned long int BST<Key, T>::size()
{
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r)
{
	if (r == NULL) {
		return 0;
	}

	return 1 + size(r->left) + size(r->right);
}

// Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key, T>::add(Key k, T x)
{
	root = add(k, x, root);
}

// Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key, T>::remove(Key k)
{
	root = remove(k, root);
}

// Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key, T>::find(Key k)
{
	Node<Key, T> *n = find(k, root);

	if (n == NULL) {
		throw std::string("error: key does not exist");
	}

	return n->data;
}

// Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k)
{
	return find(k, root) != NULL;
}

// If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k)
{
	return next(k, root)->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r)
{
	if (r == NULL) {
		throw std::string("error: next was given NULL root");
	}

	if (r->k > k) {
		return r;
	}

	return next(k, r->right);
}

// If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k)
{
	return prev(k, root)->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r)
{
	if (r == NULL) {
		throw std::string("error: prev was given NULL root");
	}

	if (r->k < k || r->left == NULL) {
		return r;
	}

	return prev(k, r->left);
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r)
{
	if (r == NULL) {
		// found where this node should go

		r = new Node<Key, T>();
		r->k = k;
		r->data = x;
		r->left = NULL;
		r->right = NULL;

		return r;
	}

	if (r->k == k) {
		// node already exists, overwrite data

		r->data = x;

		return r;
	}

	if (k < r->k) {
		// look left

		Node<Key, T> *new_node = add(k, x, r->left);
		r->left = new_node;
	} else {
		// look right

		Node<Key, T> *new_node = add(k, x, r->right);
		r->right = new_node;
	}

	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r)
{
	
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r)
{
	if (r == NULL) {
		// we were handed a root that is NULL, key doesnt exist
		
		return NULL;
	}
	
	if (r->k == k) {
		// found what we wanted
		
		return r;
	}

	if (k < r->k) {
		// we need to look left

		return find(k, r->left);
	} else {
		// we need to look right

		return find(k, r->right);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r)
{
	if (r == NULL) {
		throw std::string("error: NULL root passed to max");
	}
	
	if (r->right == NULL) {
		return r;
	}
	
	return max(r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r)
{
	if (r == NULL) {
		throw std::string("error: NULL root passed to min");
	}
	
	if (r->left == NULL) {
		return r;
	}

	return min(r->left);
}
