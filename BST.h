//Edited and submitted by: Justin Reed
//11/4/14
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
  void  deleteAll();//done
  virtual unsigned long size(Node<Key,T>* r);
  //These are the recursive versions of each of your methods.
  // You should return the address of the new root node, whether
  // or not the root node changes.
  virtual Node<Key, T>* add(Key k, T x, Node<Key, T>* r);//done?
  virtual Node<Key,T>* remove(Key k, Node<Key,T>* r);//done

  //This one returns the address of the found node, NULL
  // if not found
  virtual Node<Key,T>* find(Key k, Node<Key,T>* r);//done

  //Find the item in the sub-tree rooted at r which has the smallest key
  virtual Node<Key,T>* min(Node<Key,T>* r);//done

  //Find the item in the sub-tree rooted at r which has the largest key
  virtual Node<Key,T>* max(Node<Key,T>* r);//done

  //Find the next/prev node, and return its address
  virtual Node<Key,T>* next(Key k, Node<Key,T>* r);
  virtual Node<Key,T>* prev(Key k, Node<Key,T>* r);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	deleteAll();
}

template <class Key, class T>
void BST<Key, T>::deleteAll(){
	Node<Key, T>* temp = root;
	Node<Key, T>* temp2 = root;
	while (root != NULL)
	{
		if (temp->left != NULL){
			temp2 = temp;
			temp = temp->left;
		}
		else if (temp->right != NULL){
			temp2 = temp;
			temp = temp->right;
		}
		else{
			delete temp;
			temp = temp2;
			temp2 = root;
		}
	}
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	//searching for bottom node
	if (r->left == NULL && r->right == NULL)
		return 0;
	//searching for left child
	else if (r->left != NULL)
		return size(r->left) + 1; 
	//searching for right child
	else if (r->right != NULL)
		return size(r->left) + 1;

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
	Node<Key, T>* n = find(k, root);
	if (n == NULL) {
		throw std::printf("ERROR: no such item: " + k);
		return NULL;
	}
	return n->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	if (find(k, root) != NULL)
		return true;
	return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	return (next(k, root))->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
	Node<Key, T>* temp = find(k, r);
	return temp->right;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	return (prev(k, root))->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	Node<Key, T>* temp = find(k, r);
	return temp->left;
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL){
		//Time to build this nodes home
		Node<Key, T>* temp = new Node<Key, T>();
		temp->k = k;
		temp->data = x;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}
	else if (k == r->k){
		//Node already has a home, time to furnish it.
		r->data = x;
	} else if (k > r->k)
		//check right
		r->right = add(k,x,r->right);
	else if (k < r->k)
		//check left
		r->left = add(k, x, r->left);
	return r;

}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	if (k == r->k) {
		//best case scenario, no children
		if (r->left == NULL && r->right == NULL) {
			delete r;
			return NULL;
		}
		//one left child easy fix
		else if (r->left != NULL && r->right == NULL) {
			Node<Key, T>* n = r->left;
			delete r;
			return n;
		}
		//one right child easy fix
		else if (r->left == NULL && r->right != NULL) {
			Node<Key, T>* n = r->right;
			delete r;
			return n;	
		}
		//2 children, sets new top of tree as min of right and reassigns the 2 new trees in the proper location.
		else {
			Node<Key, T>* n = min(r->right);
			r->k = n->k;
			r->data = n->data;
			remove(n->k, n);
			return r;
		}
	}
	//looks to remove in left tree
	else if (r->k > k) {
		r->left = remove(k, r->left);
		return r;
	}
	//looks to remove in right tree
	else {
		r->right = remove(k, r->right);
		return r;
	}
}





template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r->k == k)
		return r;
	else if (r == NULL)
		return NULL;
	else if (r->k > k)
		return find(k, r->left);
	else
		return find(k, r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if (r->right == NULL)
		return r;
	else
		return r->right;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if (r->left == NULL)
		return r;
	else
	return r->left;
}
