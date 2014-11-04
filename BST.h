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
  virtual Node<Key, T>* removeAllNodes(Node<Key,T>* r);

};

#define NULL 0
#define null 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){ 
	root = null;
}

template <class Key, class T>
BST<Key,T>::~BST(){
	// calls removeAllNodes(Node<Key, T>* r) which will delete all nodes below the passed node r and will work its way up to deleting the passed node r
	removeAllNodes(root);
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
	if (r == null)
		return 0;
	else
		return 1 + size(r->left) + size(r->right);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
	add(k, x, root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
	remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  // Calls the private find() using the provided key and the root node

	  return find(k, root)->data;
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  // tmpKey is set to the key of whatever node the private find() returns and if that equals k then true is returned
	Key tmpKey = null;
	tmpKey = find(k, root)->k;

	if (tmpKey == k)
		return true;
	else
		return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  return next(k, root)->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	if (r == null)
		return null;
	else if (k == r->k)
		return max(r->right);
	else if (k < r->k)
		return next(k, r->left);
	else
		return next(k, r->right);
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
	return prev(k, root)->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	if (r == null)
		return null;
	else if (k == r->k)
		return max(r->left);
	else if (k < r->k)
		return prev(k, r->left);
	else 
		return prev(k, r->right);
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
	// creates root node if not already made
	if (root == null){
		root->k = k;
		root->data = x;
		return root;
	}
	// if a node with that key exists, change the data of that key
	else if (keyExists(k) == true){
		find(k, root)->data = x;
		return find(k, root);
	}
	// if add() is passed a null node, then it knows to create a new node and return the address of it
	else if (r == null){
		Node<Key, T>* newNode = new Node<Key, T>;
		return newNode;
	}
	// returns r's left if k is smaller than r's k
	else if (k < r->k){
		return r->left;
	}
	// returns r's right if k is greater than r's k
	else if (k > r->k){
		return r->right;
	}
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
	if (keyExists(k) == false)
		throw std::string("That node doesn't exist!");
	else if (find(k, root)->left == null && find(k, root)->right == null){
		delete r; 
		return null;
	}
	else if (find(k, root)->left == null && find(k, root)->right != null){
		Node<Key, T>* tmp = find(k, root)->right;
		delete find(k, root);
		return tmp;
	}
	else if (find(k, root)->left != null && find(k, root)->right == null){
		Node<Key, T>* tmp = find(k, root)->left;
		delete find(k, root);
		return tmp;
	}
	else {
		find(k, root)->k = max(find(k, root)->left)->k;
		remove(max(find(k, root)->left)->k, find(k, root));
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::removeAllNodes(Node<Key, T>* r){
	if (r->left == null && r->right == null){
		delete r;
	}
	else if (r->left != null)
		return removeAllNodes(r->left);
	else
		return removeAllNodes(r->right);
}
template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  // recursively looks for a node with key k
	if (r == null)
		return null;
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
	if (r == null)
		throw std::string("Can't find that node!");
	else if (r->right == null)
		return r;
	else
		return max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  // recursively finds the min starting from node r
	if (r == null)
		throw std::string("Can't find that node!");
	else if (r->left = null)
		return r;
	else
		return min(r->left);
}
