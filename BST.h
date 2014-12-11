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

  virtual Node<Key, T>* deleteAll(Node<Key,T>* r);

};

#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	root = deleteAll(root);
	delete root;
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	if (r == NULL){
		return 0;
	}
	else{
		return 1 + size(r->left) + size(r->right);
	}
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
	root = remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key, T>::find(Key k){
	if (find(k, root) == NULL){
		throw std::string("Key not within tree.");
	}
	return (find(k, root))->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	Node<Key,T>* temp = find(k,root);
	if (temp==NULL){
		return false;
	}
	return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	Node<Key, T>* temp = next(k, root);
	if (temp == NULL){
		return k;
	}
	else{
		return temp->k;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){	//min of the right subtree
	if (r == NULL){
		return NULL;
	}
	else if (k > r->k){
		return next(k, r->right);
	}
	else if (k < r->k){
		Node<Key, T>* temp = r->left;
		if (temp == NULL){
			return r;
		}
		if (k < temp->k){
			if (temp->left == NULL || k > temp->left->k){
				return temp;
			}
			return next(k, temp->left);
		}
		else{
			if (k >= temp->k){
				return r;
			}
			return next(k, temp->right);
		}
	}
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	Node<Key, T>* temp = prev(k, root);
	if (temp == NULL){
		return k;
	}
	else{
		return temp->k;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	else if (k <= r->k){
		return prev(k, r->left);
	}
	else if (k > r->k){
		Node<Key, T>* temp = r->right;
		if (temp == NULL){
			return r;
		}
		if (k > temp->k){
			if (temp->right == NULL || k < temp->right->k){
				return temp;
			}
			return prev(k, temp->right);
		}
		else{
			if (k >= r->k){
				return r;
			}
			return prev(k, temp->left);
		}
	}
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL){
		Node<Key, T>* toAdd = new Node < Key, T >();
		toAdd->k = k;
		toAdd->data = x;
		toAdd->left = NULL;
		toAdd->right = NULL;
		return toAdd;
	}
	else if (k == r->k){
		r->data = x;
	}
	else if (k < r->k){
		r->left = add(k, x, r->left);
	}
	else if (k > r->k){
		r->right = add(k, x, r->left);
	}
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	if (r == NULL){
		throw std::string("No Tree to search");
	}
	Node<Key, T>* temp;
	if (k == r->k){ 
		if (r->left == NULL && r->right == NULL){
			delete r;
			return NULL;
		}
		else if (r->left == NULL && r->right != NULL){
			temp = r->right;
			delete r;
			return temp;
		}
		else if (r->left !=NULL && r->right == NULL){
			temp = r->left;
			delete r;
			return temp;
		}
		else{
			temp = min(r->right);
			r->data = temp->data;
			r->k = temp->k;
			r->right = remove(temp->k, temp);
		}
	}
	else if (k < r->k){
		 r->left = remove(k, r->left);
	}
	else{
		r->right = remove(k, r->right);
	}
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (k == r->k){
		return r;
	}
	else if (k < r->k && r->left!=NULL){
		return find(k, r->left);
	}
	else if (k > r->k && r->right!=NULL){
		return find(k, r->right);
	}
	else{
		return NULL;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if (r == NULL){
		return root;
	}
	else if (r->right == NULL){
		return r;
	}
	else{
		return max(r->right);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if (r == NULL){
		return root;
	}
	else if (r->left == NULL){
		return r;
	}
	else{
		return min(r->left);
	}
}
//add recursive delete all method to delete subtree
template <class Key, class T>
Node<Key, T>* BST<Key, T>::deleteAll(Node<Key, T>* r){
	if (r->left == NULL){
		return deleteAll(r->left);
	}
	if (r->right == NULL){
		return deleteAll(r->right);
	}
	if (r->left == NULL && r->right == NULL){
		delete r;
		r = NULL;
		return NULL;
	}
}