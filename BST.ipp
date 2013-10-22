#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  //TODO
  return 0;
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  if (r == NULL)
  return NULL;
  else{
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
  if(find(k, root) != NULL)
	return find(k, root)->data;
  else
	throw (std::string) "The key does not Exists.";
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  if(find(k, root) != NULL)
	return true;
  else
	return false;
  
  /*
  if(k == NULL)
     return false;

  if(k == root->k)
	return true;

  if(k > root->k)
	return (k == root -> right -> k);
  if(k < root->k)
	return (k == root -> left -> k);
   
  return false;
  */
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  if(next(k, root) != NULL)
	return next(k, root) -> k;
  else
	return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  if (r -> right != NULL)
	return min(r -> right);
  
  return NULL;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  if(prev(k, root) != NULL)
	return prev(k, root) -> k;
  else
	return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  if (r -> right != NULL)
	return max(r -> left);
  return NULL;
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  if(r == NULL){
  r = new Node<Key, T>();
  r -> data = x;
  r -> k = k;
  r -> right = NULL;
  r -> left = NULL;
  }
  else if(k == r->k){
	r -> data = x;}
  else if(k < r->k){
	r -> left = add(k, x, r -> left);}
  else {
	r -> right = add(k, x, r-> right);}
  return r;
  }
  
template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  if (r == NULL){
	return NULL;}
  else if(k == r -> k){
	return r;}
  else if(k > r -> k){
    return find(k, r ->right);}
  else if(k < r -> k){
	return find(k, r ->left);}
  
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  if (r == NULL)
	return NULL;
  if(r -> right == NULL)
	return r;
  else return max(r-> right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  if (r == NULL)
	return NULL;
  if(r -> left == NULL)
	return r;
  else return max(r-> left);
}
