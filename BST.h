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
class BST : public SSet < Key, T > {
public:
	BST();
	~BST();
	//all public versions of these methods should simply
	//call the private version of itself

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
	Node<Key, T>* root;

	virtual unsigned long size(Node<Key, T>* r);
	//These are the recursive versions of each of your methods.
	// You should return the address of the new root node, whether
	// or not the root node changes.
	virtual Node<Key, T>* add(Key k, T x, Node<Key, T>* r);
	virtual Node<Key, T>* remove(Key k, Node<Key, T>* r);

	//This one returns the address of the found node, NULL
	// if not found
	virtual Node<Key, T>* find(Key k, Node<Key, T>* r);

	//Find the item in the sub-tree rooted at r which has the smallest key
	virtual Node<Key, T>* min(Node<Key, T>* r);

	//Find the item in the sub-tree rooted at r which has the largest key
	virtual Node<Key, T>* max(Node<Key, T>* r);

	//Find the next/prev node, and return its address
	virtual Node<Key, T>* next(Key k, Node<Key, T>* r);
	virtual Node<Key, T>* prev(Key k, Node<Key, T>* r);

	virtual void removeAll();
};




#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	removeAll();

	/*while (root != NULL){
		root->k = NULL;
		delete root;
		}*/
}


template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
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
	if (!keyExists(k)){
		throw std::string("Sorry. This key does not exist");
	}
	return find(k, root)->data;
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	if (find(k, root) != NULL){
		return true;
	}
	return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	while (find(k, root) != NULL){
		return next(k, root)->k;
	}
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	return prev(k, root)->k;
}





//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	if (r != NULL){
		return 1 + size(r->left) + size(r->right);
	}
	return 0;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL){
		Node<Key, T>* newNode = new Node<Key, T>();
		newNode->k = k;
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return r;
	}
	if (r->right = add(k, x, r->right)){
		return r;
	}
	if (r->left = add(k, x, r->left)){
		return r;
	}
	if (r->k == k){
		r->data == x;
		return r;
	}
	return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	else if (r->left != NULL){
		r->k = NULL;
		r = r->left;
		return r->left;
	}
	else if (r->right != NULL){
		r->k = NULL;
		r = r->right;
		return r->right;
	}
	else if (r->left != NULL && r->right != NULL){
		Node<Key, T>* m = max(r);
		Node<Key, T>* temp = m;
		m = r;
		r = temp;
		remove(k, max(r));
	}
	return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r == NULL){
		throw std::string("Not found");
	}
	else if (r->k == k){
		return r;
	}
	else if (k < r->k){
		return find(k, r->left);
	}
	else {
		return find(k, r->right);
	}
	return NULL;
}

//go right until you can't anymore
template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	if (r->right != NULL){
		max(r->right);
	}
	return r;
}


//go left until you can't anymore
template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	if (r->left != NULL){
		min(r->left);
	}
	return r;
}

//is the min of the right sub-tree
template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	if (r->k < k){
		return next(k, r->right);
	}
	if (r->k > k){
		if (next(k, r->left) == NULL){
			return r;
		}
		else{
			return next(k, r->left);
		}
	}
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	if (r->k < k){
		return prev(k, r->left);
	}
	if (r->k > k){
		return prev(k, r->right);
	}
	return r;
}

template <class Key, class T>
void BST<Key, T>::removeAll(){
	while (root->right != NULL){
		remove(root->right->k, root->right);
	}
	while (root->left != NULL){
		remove(root->left->k, root->left);
	}
		delete root;
}