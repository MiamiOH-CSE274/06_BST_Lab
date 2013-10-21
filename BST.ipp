#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
// We don't need to declare a pointer to the root just need to make a new Node for the root
// since we already declared the pointer in BST.h
  root = new Node<Key, T>;
  //root->left = NULL; // Not sure if we need these two lines or not. 
  //root->right = NULL;
}
// TODO
template <class Key, class T>
BST<Key,T>::~BST(){
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
// Call the private root method which takes the root as the parameter.
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  unsigned long numNodes = 0;
  if (r == NULL) {
	return 0;
  } else {
		// Count the number of nodes to the left and right of the root
		// node and add 1 to make sure you include the root node in the total.
		numNodes = 1 + size(r->left) + size(r->right);
		return numNodes;
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
  //TODO
  T fakeT;
  return fakeT;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  // TODO
  return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  //TODO
  Key fakeKey;
  return fakeKey;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

// This add method has been used from Dr. Brinkman's class notes 
template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  if (r == NULL) {
  // If there is no node then create a new one and assign correct values.
	Node<Key, T>* newNode = new Node<Key, T>;
	newNode->k = k;
	newNode->data = x;
	return newNode;
  } else if (r->k == k) { // If the key is already in the tree then overwrite its data.
		r->data = x;
		return r;
    } else if (k < r->k) { // Try to add to the left side of the current node
		r->left = add(k, x, r->left);
      } else { // Try to add to the right side of the current node
			r->right = add(k, x, r->right);
		}
	return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  if(r == NULL || r->right == NULL) {
	return r;
  }
  else 
	return max(r->right);	
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  if(r == NULL || r->left == NULL) { 
	return r; 
  }
  else 
	return min(r->left);
}
