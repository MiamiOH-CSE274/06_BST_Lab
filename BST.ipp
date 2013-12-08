#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  //Initialize root of the tree using defined NULL
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //De-allocate any allocated memory
  while(size > 0)
	remove(root->k);
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  if (r == NULL) return 0;
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
  return find(k, root);
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  while(root != null) {
	if(root->k < k)
		root = root->left;
	else if (root->k > k)
		root = root->right;
	else
		return root->x;
  }
  throw std::string("There is no such item");
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  return next(k, root)->k;
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
  return prev(k, root)->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  if(r == NULL)
	return NULL;
  else if (r->k < k)
	r = find(k, r->left);
  else if(r->k > k)
	r = find(k, r->right);
  else
	return r->k;
  return NULL;
}

//Find the item in the sub-tree rooted at r which has the largest key
template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){

  while(r->right != NULL) {
	r = max(r->right);
  }

  return r;
}

//Find the item in the sub-tree rooted at r which has the smallest key
template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  
  while(r->left != NULL) {
	r = min(r->left);
  }

  return r;
}
