//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/10/01

#include "SSet.h"
#include <string>

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

/////////////////////////////////////////////////////////////////////////////////////////////////////// #include "BST.ipp"

#define NULL 0
#include <string>


template <class Key, class T>
BST<Key,T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
	// found this on stack overflow, I like it a lot.
	while (root != NULL) {
		root = remove(root->k, root);
	}
	root = NULL;
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
	return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  if (r==NULL) {
	  return 0;
  } else {
	  // Brinkman says:
	  // We call this TREE TRAVERSAL
	  // Not only tree traversal access all the nodes, but it does it in order!
	  // Super cool!!!!! (Also it's basically quicksort)
	  return 1+size(r->left)+size(r->right);
  }
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
	Node<Key, T>* node = find(k, root);
	if (node == NULL) {
		throw std::string("Can't find that item!");
	} else {
		return node->data;
	}
}


//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
	return find(k, root) != NULL; // ???
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
	Node<Key, T>* temp = next(k, root);
	if (temp == NULL)
		return k;
	return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	// if the node is null, return null
	if (r == NULL) return NULL;
	// k is bigger...search right
	else if (k > r->k)
		return next(k, r->right);
	// k is smaller...
	else if (k < r->k) {
		// recursively search leftwards until you find null, then return the r previous
		if (next(k, r->left) == NULL)
			return r;
		else
			return next(k, r->left);
	}
	else { // k == r->k
		// If you happen to find the key itself, if it has a right child return that.
		// otherwise return null (which will probably, in turn return the r previous as next)
		if (r->right != NULL)
			return next(k, r->right);
		else
			return NULL;
		
	}
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
	Node<Key, T>* temp = prev(k, root);
	if (temp == NULL)
		return k;
	return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	if (r == NULL) return NULL;
	// k is bigger...
	else if (k > r->k) {
		// recursively search rightwards
		if (prev(k, r->right) == NULL)
			return r;
		else
			return prev(k, r->right);
	}
	// k is smaller...search left
	else if (k < r->k)
		return prev(k, r->left);
	else { // k == r->k
		// If you happen to find the key itself, return it's left child
		// otherwise return null (ergo, eventually return the previous r)
		if (r->left != NULL)
			return prev(k, r->left);
		else
			return NULL;
	}
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
	// If there's nothing yet.
	if (r == NULL) {
		r = new Node < Key, T >();
		r->k = k;
		r->data = x;
		r->left = NULL;
		r->right = NULL;
	}
	else if (k == r->k) // found it, rewrite it.
		r->data = x;
	else if (k < r->k) // too small, set it left of left.
		r->left = add(k, x, r->left);
	else {  // too big, set it right of right
		r->right = add(k, x, r->right);
	}
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	// Couldn't figure this one by myself......
	if (r == NULL)
		return NULL;
	else if (r->k == k){
		// childless node
		if (r->left == NULL&&r->right == NULL){
			delete r;
			return NULL;
		} // otherwise
		else if (r->left == NULL || r->right == NULL){
			Node<Key, T>* newRoot = r->left; // left first?
			if (newRoot == NULL){
				newRoot = r->right; //no left? just right then.
				delete r;
				return newRoot;
			}
			else{ // Systematically destroy the node.
				Node<Key, T>* maxNode = max(r->left);
				Key temp = maxNode->k;
				maxNode->k = r->k;
				r->k = temp;

				T dataStore = maxNode->data;
				maxNode->data = r->data;
				r->data = dataStore;

				r->left = remove(k, r->left);
				return r;
			}
		}

		// Recursively find the node we ought to remove.
		else if (k<r->k)
			r->left = remove(k, r->left);
		else
			r->right = remove(k, r->right);
	}
}




template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
	if (r == NULL) {
		return NULL;
	} else if (r->k == k) { // We found it!
		return r;
	} else if (r->k < k) { // Look right..
		return find(k, r->right);
	} else if (r->k > k) { // Look left..
		return find(k, r->left);
	}
	
	return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
	if (r == NULL) {

		throw std::string("Error, null max root");

	} else if (r->right == NULL) {
		return r;
	} else {
		return max(r->right);
	}
	return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
	if (r == NULL) {
		
		throw std::string("Error, null min root");

	} else if (r->left == NULL) {
		return r;
	} else {
		return min(r->left);
	}
	return NULL;
}
