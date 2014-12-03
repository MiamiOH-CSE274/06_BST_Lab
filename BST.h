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

  virtual Node<Key, T>* createNode(Key k, T x);

  //removes all descendants of the node
  virtual void removeAll(Node<Key, T>* r);

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

//removes all descendants of the node
template <class Key, class T>
void BST<Key, T>::removeAll(Node<Key, T>* r) {
	while (root != NULL){
		remove(root->k);
	}
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	if (r == NULL) {
		return 0;
	}
	else {
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
	if (find(k, root) == NULL) {
		std::cout << "Error: No such item exists" << std::endl;
	}
	return find(k, root)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	if (find(k, root) == NULL) {
		return false;
	}
	return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	Node<Key, T>* r2 = next(k, root);
	if (r2 == NULL) {
		return k;
	}
	return r2->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
	if (r == NULL) {
		return NULL;
	}
	else if (k < r->k) {
		Node<Key, T>* leftNode = next(k, r->left);
		if (leftNode == NULL) {
			return r;
		}
		return leftNode;
	}
	else {
		Node<Key, T>* rightNode = next(k, r->right);
		if (rightNode == NULL) {
			return NULL;
		}
		return rightNode;
	}
	
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	Node<Key, T>* r2 = prev(k, root);
	if (r2 == NULL) {
		return k;
	}
	return r2->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	if (r == NULL) {
		return NULL;
	}
	else if (k > r->k) {
		Node<Key, T>* rightNode = prev(k, r->right);
		if (rightNode == NULL) {
			return r;
		}
		return rightNode;
	}
	else {
		Node<Key, T>* leftNode = prev(k, r->left);
		if (leftNode == NULL) {
			return NULL;
		}
		return leftNode;
	}
	
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL) {
		r = createNode(k, x);
		return r;
	}
	if (k == r->k) {	//if the key already exists, overwrite the data
		r->data = x;
		return r;
	}
	else if (k < r->k) {
		r->left = add(k, x, r->left); 
	}
	else {
		r->right = add(k, x, r->right);	
	}	
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::createNode(Key k, T x){
	Node<Key, T>* newNode = new Node<Key, T>();	//Create new node
	newNode->k = k;
	newNode->data = x;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	if (k == r->k) { //if the key of the root is the same as the key you're removing
		if (r->right == NULL && r->left == NULL) { //if its pointers are both null, delete the node
			delete r;
			return NULL;
		}
		else if (r->right == NULL && r->left != NULL) { //if only right pointer is null
			Node<Key, T>* leftNode = r->left; //store the left pointer and return it, delete the node
			delete r;
			return leftNode;
		}
		else if (r->right != NULL && r->left == NULL) { //if only the left pointer is null
			Node<Key, T>* rightNode = r->right; //store the right pointer and return it, delete the node
			delete r;
			return rightNode;
		}
		
		else { //neither pointer is null, so find smallest value on right side of tree and make it the root
			Node<Key, T>* minRightNode = min(r->right); //then delete the minRightNode
			r->k = minRightNode->k;
			r->data = minRightNode->data;
			remove(minRightNode->k, minRightNode);
			return r;
		}
	}
	else if (r->k > k) { //the key is bigger than the key of the root so look to the right
		r->right = remove(k, r->right);
		return r;
	}
	else { //the key must be smaller than the key of the root so look to the left
		r->left = remove(k, r->left);
		return r;
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r == NULL) {   //if you reach the end of the sub-tree (r == NULL)
		return NULL;   //then the key doesn't exist and return NULL
	}
	else if (r->k == k) {   //if the key of the root is the key you're looking for
		return r;           //return the root
	}
	else if (k < r->k) {           //if the key of the root is larger than the key you're looking for
		return find(k, r->left);   //retest the find method with the pointer to the root on the left
	}
	else {                          //if the key of the root is smaller than the key you're looking for
		return find(k, r->right);   //retest the find method with the pointer to the root on the right
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if (r == NULL) {
		return NULL;
	}
	else if (r->right == NULL) {
		return r;
	}
	else {
		return max(r->right);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if (r == NULL) {
		return NULL;
	}
	else if (r->left == NULL) {
		return r;
	}
	else {
		return min(r->left);
	}
}

