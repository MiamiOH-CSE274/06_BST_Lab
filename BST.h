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
	root = NULL;
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
	if (next(k, root) == NULL){
		return k;
	}
	else{
		return next(k, root)->k;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){	//min of the right subtree
	if (k < r->k && r->left != NULL){
		if (k < r->left->k){
			return next(k, r->left);
		}
		else{
			return min(r->left->right);
		}
	}
	else if (k < r->k){
		return r;
	}
	else if (k > r->k && r->right != NULL){
		if (k > r->right->k){
			return next(k, r->right);
		}
		else{
			return min(r->right);
		}
	}
	else{
		return NULL;
	}
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	if (prev(k, root) == NULL){
		return k;
	}
	else{
		return prev(k, root)->k;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	if (k < r->k && r->left!=NULL){
		if (k < r->left->k){
			return prev(k, r->left);
		}
		else if (k == r->left->k){
			return r->left->left;
		}
		else{
			return max(r->left);
		}
	}
	else if (k > r->k && r->right != NULL){
		if (k > r->right->k){
			return prev(k, r->right);
		}
		else{
			return max(r->left);
		}
	}
	else if (k > r->k){
		return r;
	}
	else{
		return NULL;
	}
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL){
		r = new Node<Key,T>;
		r->data = x;
		r->k = k;
		r->left = NULL;
		r->right = NULL;
		return r;
	}
	else if (k < r->k && r->left!=NULL){
		r->left = add(k, x, r->left);
		return r;
	}
	else if (k < r->k){
		r->left = new Node < Key, T > ;
		r->left->data = x;
		r->left->k = k;
		r->left->left = NULL;
		r->left->right = NULL;
		return r;
	}
	else if (k > r->k && r->right!=NULL){
		r->right=add(k, x, r->right);
		return r;
	}
	else if (k > r->k){
		r->right = new Node < Key, T > ;
		r->right->data = x;
		r->right->k = k;
		r->right->right = NULL;
		r->right->left = NULL;
		return r;
	}
	else{
		return r;
	}
		
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
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
			remove(temp->k, r);
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
	if (r->left == NULL && r->right == NULL){
		delete r;
		r = NULL;
		return NULL;
	}
	else if (r->left== NULL){
		return deleteAll(r->right);
	}
	else{
		return deleteAll(r->left);
	}
}