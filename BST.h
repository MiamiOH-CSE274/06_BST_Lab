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
  
  //Remove all the nodes in tree
  virtual void remove_all(Node<Key, T> *r);
  
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
#define NULL 0



template <class Key, class T>
BST<Key,T>::BST(){
	root = NULL;
	unsigned int numItems = 0;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  remove_all(root);
}


template <class Key, class T>
void BST<Key,T>::remove_all(Node<Key,T> *r){
	
	if (r->left != NULL && r->right != NULL){
		remove_all(r->left);
		remove_all(r->right);
	
	}
	else if (r->left != NULL) {
		remove_all(r->left);

		
	}
	else if(r->right != NULL) {
		 remove_all(r->right);
	}
	
	delete r;
	r = NULL;
	
	
	/* if (r->left == NULL && r->right == NULL) {
		 delete r;
		 r = NULL;
		 return;
	 }
	 
	 if (r->left != NULL) {
		 remove_all(r->left);
	 }
	 if (r->right != NULL) {
		 remove_all(r->right);
	 }*/
} 

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
    if(r == NULL){
		return 0;
	} else{
		return 1 + size(r->right) + size(r->left);
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
  //TODO
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
	
	
	Node<Key, T>* Temp = find(k, root);
	
	if(Temp == NULL){
		throw std::string("That leaf does not exist");
	}
	
	
	return Temp->data;

}


//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){

	
	if(find(k, root) == NULL) return false;
	
	return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
	Node<Key, T> *u = next(k, root);
	
	if(u == NULL)return k;
	
	
	return u->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	if (r == NULL) {
		return NULL;
	}

	if (k < r->k) {
		Node<Key, T> *n = next(k, r->left);
		
		if (n == NULL) {
			return r;
		}
		
		return n;
		
	}else {
		Node<Key, T> *n = next(k, r->right);
		if (n == NULL) {
			return NULL;
		}

		return n;
	}
}
//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){

	Node<Key, T> *u = prev(k, root);

	if (u == NULL) {
		return k;
	}
	
	return u->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	if (r == NULL) {
		return NULL;
	}

	if (k > r->k) {
		
		Node<Key, T> *n = prev(k, r->right);

		if (n == NULL) {
			return r;
		}

		return n;
	} else {

		Node<Key, T> *n = prev(k, r->left);
		
		if (n == NULL) {
			return NULL;
		}

		return n;
	}
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
	
	//adds new node to NULL space and breaks from recursion
	if (r == NULL) {

		r = new Node<Key, T>();
		r->k = k;
		r->data = x;
		r->left = NULL;
		r->right = NULL;
		return r;
	}
	
	
	// node exists, overwrite data
	if (r->k == k) {
		r->data = x;
		return r;
	}
	
	
	if (k < r->k) {
		Node<Key, T> *w = add(k, x, r->left);
		r->left = w;
	} else {
		Node<Key, T> *w = add(k, x, r->right);
		r->right = w;
	}

	return r;
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
	if (r == NULL) {        //If there is no such Node where r->k == k, then do nothing
		return NULL;
	}

	if(r->k == k){		
		
		if (r->left == NULL && r->right == NULL) {
			// no right or left means no need to find replacement
			delete r;
			r = NULL;
			return NULL;
		}
		else if(r->right == NULL){
			Node<Key, T> *temp;
			temp = r->left;
			delete r;
			return temp;	
		}else if(r->left == NULL){
			Node<Key,T> * temp;
			temp = r->left;
			delete r;
			return temp;
		}else{
		
			Node<Key, T> *w = r->right; 
			
			while (w->left != NULL){
				w = w->left;
			}
			r->k = w->k;
			r->data = w->data;
			delete r;
			return w;
		}
	} 
	
	else if (r->k < k) {
		r->right = remove(k, r->right);
		
	} else {
		r->left = remove(k, r->left);
	}

	return NULL;
}
	//Node<Key, T> *n;

	/*if (r->k == k) {

		if (r->left == NULL && r->right == NULL) {
			// no right or left means no Node to replace this one
			delete r;
			r = NULL;
			return NULL;
		}

		// find replacement node
		if (r->right != NULL) {
			n = min(r->right);
		} else {
			n = max(r->left);
		}
		// store new node in temp variable 
		
		
		Node<Key, T> temp;
		temp.k = n->k;
		temp.data = n->data;

		remove(n->k, r);

		// now update this nodes data with our new nodes data
		r->k = temp.k;
		r->data = temp.data;

		return r;
	}

	if (r->k < k) {
		n = remove(k, r->right);
		r->right = n;
	} else {
		n = remove(k, r->left);
		r->left = n;
	} 
	*/


template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
	if(r == NULL) return NULL;
	else if (r->k == k) return r;
	else if (k < r->k) return find(k, r->left);
	else return find(k, r->right);

  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
	
	if(r == NULL){
		throw std::string("Invalid root");
	}
	if(r->right == NULL){
		return r;
	}
	return max(r->right);
	

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
	if(r == NULL){
		throw std::string("Invalid root");
	}
	else if(r->left == NULL){
		return r;
	}
	else{
		return min(r->left);
	}	
		return NULL;
}