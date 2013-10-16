#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  //TODO

  root = new Node<Key,T>;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  //TODO

  if(keyExists(root->k))
	return 0;
  return 1 + size(root->left) + size(root->right);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  //TODO
  return 0;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  //TODO
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
  return find(k, root)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  //TODO

  
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
  //TODO
  if(r==NULL)
	throws (std::string) "There Node is Null";
  else if(r->k==k)
	return r;
  else if(k<r->k)
	return find(k, r->left);
  else
    return find(k, r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  //TODO
  if(r==NULL)
	return NULL;
  while(r->right !=NULL)
	r=r->right;
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  //TODO
  if(r==NULL)
	return NULL;
  while(r->left != NULL)
	r=r->left;
  return r;
}
