#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){

  root = NULL;

}

template <class Key, class T>
BST<Key,T>::~BST(){
  
  //while(root != NULL) remove max(root -> right); remove min(root -> left);
  while (size() > 0)
    remove (root -> k);

}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  
  return size (root);

}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  
  if (r == NULL)
    return 0;
  return (1 + size(r -> left) + size(r -> right));

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
  
  return (find (k, root) -> data);

}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  
  Node<Key, T>* nodeToFind = find (k, root);
  if (nodeToFind == NULL)
    return false;
  else
    return true;

}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  
  Node<Key, T>* nextNode = next(k, root);
  if (nextNode == NULL)
    return k;
  else
	return nextNode -> k;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  
  if (r == NULL)
    return NULL;
  else if (r -> k > k){
    if (r -> left == NULL)
	  return r;
	else
	  return next(k, r -> left);
  }
  else if (r -> k < k)
    return next(k, r -> right);
  else
    return r;

}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  
  Node<Key, T>* prevNode = prev(k, root);
  if (prevNode == NULL)
    return k;
  else
    return prevNode -> k;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  
  if (r == NULL)
    return NULL;
  else if (r -> k > k){
    if (r -> left == NULL)
	  return NULL;
	else
	  return prev(k, r -> left);
  }
  else if (r -> k < k)
    return prev(k, r -> right);
  else
    return r;

}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  
  if (r == NULL){
    Node<Key, T>* newNode = new Node<Key, T>;
    newNode -> k = k;
	newNode -> data = x;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
  }
  else if (r -> k == k)
    r -> data = x;
  else if (k < (r -> k))
    r -> left = add(k, x, r -> left);
  else
    r -> right = add(k, x, r -> right);
  return r;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  
  if (r == NULL)
    return NULL;
  else if (r -> k == k){
    if (r -> right == NULL && r -> left == NULL){
	  delete r;
	  return NULL;
	}
	else if (r -> right == NULL || r -> left == NULL){
	  Node<Key, T>* newR = r -> left;
	  if (newR == NULL)
	    newR = r -> right;
	  delete r;
	  return newR;
	}
	else{
	  Node<Key, T>* maxR = max(r -> left);
	  r -> k = maxR -> k;
	  r -> data = maxR -> data;
	  r -> left = remove(k, r -> left);
	  return r;
	}
  }
  else if (r -> k > k){
    r = remove (k, r -> left);
	return r;
  }
  else{
    r = remove (k, r -> right);
	return r;
  }

}

template <class Key, class T>
Node<Key, T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  
  if (r == NULL)
	return NULL;
  else if (r -> k == k)
    return r;
  else if (k > r -> k)
    return find (k, r -> right);
  else
    return find (k, r -> left);

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  
  if (r == NULL)
    return NULL;
  else if (r -> right == NULL)
    return r;
  else
    return max(r -> right);

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  
  if (r == NULL)
    return NULL;
  else if (r -> left == NULL)
    return r;
  else
    return min(r -> left);

}
