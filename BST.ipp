#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  while(root != NULL){
	BST::remove(root -> k, root);
  }
}

//Recursively get the size of the tree starting from the node r
//Has the posibility to get sizes of certain subtrees!
template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){

  //If the node doesn't exist, break the recursive loop
  if(r == NULL) return 0;

  //Return the this, plus the size of the branches to the left and right!
  return 1 + size(r -> right) + size(r -> left);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(){
	return size(root);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  root = add(k, x, root);
}

//Add the node to the tree, putting it where it needs to go
template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  
  if(r == NULL){
		r = new Node<Key, T>();
		r -> data = x;
		r -> k = k;
		r -> left = NULL;
		r -> right = NULL;
		return r;
  }else if(k == r -> k){
		r -> data = x;
		return r;
  }else if(k < r -> k){
		r -> left = add(k, x, r -> left);
		return r;
  }else{
		r -> right = add(k, x, r -> right);
		return r;
  }
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
  //TODO
  remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
Node<Key, T>* BST<Key,T>::find(Key k, Node<Key, T>* root){
  //TODO
  
  return NULL;
}

template <class Key, class T>
T BST<Key, T>::find(Key k){
	if(root == NULL) throw (std::string) "The Node is Null!";
	return find(k, root) -> data;
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  if(find(k, root) != NULL) return true;
  return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  //TODO
  return NULL;
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
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  //TODO
  return NULL;
}
