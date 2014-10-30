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
BST<Key,T>::BST(){
	
}

template <class Key, class T>
BST<Key,T>::~BST(){
	
}

template <class Key, class T>
void BST<Key,T>::removeAll(){

}

template <class Key, class T>
unsigned long BST<Key,T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
	if (r == NULL)
		return 0;
    return 1 + size(r->left) + size(r->right);
}

template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
	
}

template <class Key, class T>
void BST<Key,T>::remove(Key k){
	
}

template <class Key, class T>
T BST<Key,T>::find(Key k){
	Node* n = find(k, root);
	if (n == NULL) {
		throw std::printf("ERROR: No such item exception.");
		return NULL;
	}
	return n->data;
}

template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
	if (find(k) == NULL)
		return false;
	return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
	Node *n = next(k, root);
	if (n == NULL)
		return k;
	return n->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	Node *n = find(k, r);
	if (n == NULL)
		return NULL;
	return min(n-right);
}

template <class Key, class T>
Key BST<Key,T>::prev(Key k){
	Node *n = prev(k, root);
	if (n == NULL)
		return k;
	return n->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	Node *n = find(k, r);
	if (n == NULL)
		return NULL;
	return max(n->left);
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
	
	return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
	
	return NULL;
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
	if (r->right != NULL)
		return r;
	return max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
	if (r->left != NULL)
		return r;
	return min(r->left);
}