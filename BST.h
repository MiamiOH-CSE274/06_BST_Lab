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
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	removeAll(root);
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	if(r == NULL){
	return 0;
	} else {
	return 1 + size(r->right) + size(r->left);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key, T>::add(Key k, T x){
	root = add(k, x, root);
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
	find(k, root);
	
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	if (find(k) != false){
		return true;
	}
	else {
		return false;
	}
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	return next(k, root)->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
	if(r->right == NULL){
	if(r->key > k){
		return next(r->left);
	} else {
		return NULL;
	}
	} else {
		return min(r->right);
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	return prev(k, root)->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	if (r->left == NULL){
		if (r->key < k){
			return next(r->right);
		}
		else {
			return NULL;
		}
	}
	else {
		return max(r->left);
	}
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (keyExists(k) == true){
		find(k)->data = x;
	}
	else {
		Node<Key, T>* n = new Node<k, x>*;
		find(prev(k, root))->right = n;
		return n;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	if (keyExists(k) == false){
		throw std::string("Node doesn't exist!");
	}
	else  if (find(k)->right == NULL && find(k)->left == NULL){
		delete find(k);
		prev(k)->right = NULL;
		next(k)->left = NULL;
		return  prev(k);
	}
	else {
		find(k)->data = prev(k)->data;
		find(k)->Key = prev(k)->Key;
		remove(prev(k)->Key, prev(k));
	}

	
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r == NULL){
		throw std::string("The node can't be found!");
	}
	else if (r->k == k){
		return r;
	}
	else if (r->k < k){
		return find(k, r->right);
	}
	else {
		return find(k, r->left);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if(r == NULL){
		throw std::string("Invalid node!");
	} else if(r->right == NULL){
		return r;
	} else {
	return max(r->right);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if(r == NULL){
		throw std::string("Invalid node!");
	} else if(r->left == NULL){
		return r;
	} else {
	return max(r->left);
	}
}

template <class Key, class T>
void BST<Key, T>::removeAll(Node<Key, T>* r){
	remove(r->Key);
}

