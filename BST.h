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


//Author: Sam Bowdler
//Date: 2014/10/28

#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
	delete root;
}

template <class Key, class T>
unsigned long BST<Key,T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
	return r == NULL ? 0 : 1 + size(r->left) + size(r->right);
}

template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
	Node<Key,T>* n = add(k, x, root);
}

template <class Key, class T>
void BST<Key,T>::remove(Key k){
	Node<Key,T>* n = remove(k, root);
}

template <class Key, class T>
T BST<Key,T>::find(Key k){
	Node<Key,T>* n = find(k, root);
	if (n == NULL) {
		throw std::printf("ERROR: No such item exception.");
		return NULL;
	}
	return n->data;
}

template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
	return !(find(k, root) == NULL);
}

template <class Key, class T>
Key BST<Key,T>::next(Key k){
	Node<Key,T>* n = next(k, root);
	return n == NULL ? k : n->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	if (r == NULL)
		return NULL;
	else if (k < r->k)
		return (r->left == NULL || r->left->k <= k) ? NULL : next(k, r->left);
	else
		return next(k, r->right);
}

template <class Key, class T>
Key BST<Key,T>::prev(Key k){
	Node<Key,T>* n = prev(k, root);
	return n == NULL ? k : n->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	if (r == NULL)
		return NULL;
	else if (k > r->k)
		return (r->right == NULL || r->right->k >= k) ? NULL : prev(k, r->right);
	else
		return prev(k, r->left);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
	if (r == NULL){
		Node<Key, T>* newNode = new Node<Key, T>();
		newNode->k = k;
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	} else if (k == r->k)
		r->data = x;
	else if (k < r->k)
		r->left = add(k,x,r->left);
	else
		r->right = add(k,x,r->right);
	return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
	if (r == NULL) 
		return r;
	else if (k == r->k) {
		if (r->left == NULL && r->right == NULL)
			delete r;
		else if (size(r->left) >= size(r->right))
			r = max(r->left);
		else
			r = min(r->right);
	} else if (k < r->k)
		r->left = remove(k, r->left);
	else
		r->right = remove(k, r->right);
	return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
	if (r == NULL)
		return NULL;
	else if (k == r->k)
		return r;
	else if (k > r->k)
		return find(k, r->right);
	else if (k < r->k)
		return find(k, r->left);
	return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
	return r->right == NULL ? r : max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
	return r->left == NULL ? r : min(r->left);
}