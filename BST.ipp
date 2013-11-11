#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  destroy(root);
}

template <class Key, class T>
void destroy(Node<Key,T>* r){
	if(r!=NULL){
		destroy(r->left);
		destroy(r->right);
		delete r;
	}
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
    return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  if(r==NULL)
    return 0;
  else if(r->right != NULL && r->left != NULL)
    return 1 + size(r->right) + size(r->left);
  else if(r->right == NULL && r->left != NULL)
    return 1+size(r->left);
  else if(r->right != NULL && r->left == NULL)
    return 1+size(r->right);
  else
    return 1;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  root = add(k,x,root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
  remove(k,root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  return find(k, root)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  return keyExists(k,root);
}

template <class Key, class T>
bool BST<Key,T>::keyExists(Key k, Node<Key,T>* r){
  if(k == r->k)
	return true;
  else if(k>r->k && r->right != NULL)
	return keyExists(k,r->right);
  else if(k<r->k && r->left != NULL)
	return keyExists(k,r->left);
  else if(k>r->k && r->right == NULL)
	return false;
  else if(k<r->k && r->left == NULL)
	return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  Node<Key,T>* checkHere = next(k,root);
  if(checkHere==NULL)
    return k;
  else
    return checkHere->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  if(r==NULL)
	return NULL;
  else if(r->left!=NULL){
    if(r->left->k > k)
	  return next(k,r->left);
  }
  if(r->k > k)
    return r;
  else if(r->k <= k)
    return next(k,r->right);
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  Node<Key,T>* checkHere = prev(k,root);
  if(checkHere==NULL)
    return k;
  else
    return checkHere->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  if(r==NULL)
	return NULL;
  if(r->right!=NULL){
    if(r->right->k < k)
	  return prev(k,r->right);
  }
  if(r->k < k)
    return r;
  else if(r->k >= k)
    return prev(k,r->left);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  if(r==NULL){
	r = new Node<Key,T>();
	r->data = x;
	r->k = k;
	r->right = NULL;
	r->left = NULL;
  }
  else if(k==r->k)
	r->data = x;
  else if(k>r->k)
	r->right=add(k,x,r->right);
  else if(k<r->k)
	r->left=add(k,x,r->left);
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  if(r==NULL)
    return NULL;
  else if(r->k==k){
    if(r->left == NULL && r->right == NULL){
	  delete r;
	  r=NULL;
	  return r;
	}
	else if(r->right == NULL && r->left != NULL){
	  Node<Key,T>* placeHolder = r->left;
	  delete r;
	  return placeHolder;
	}
	else if(r->right != NULL && r->left == NULL){
	  Node<Key,T>* placeHolder = r->right;
	  delete r;
	  return placeHolder;
	}
	else{
	  Node<Key,T>* placeHolder = max(r->left);
	  r->k=placeHolder->k;
	  r->data=placeHolder->data;
	  if(r->left != placeHolder)
	    remove(placeHolder->k, r->left);
	  else{
	    r->left = placeHolder->left;
		delete placeHolder;
	  }
	  return r;
	}
  }
  else if(r->k<k)
    r->right = remove(r->right->k,r->right);
  else
    r->left = remove(r->left->k,r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  if(r->k == k)
	return r;
  else if(r->right == NULL && k > r->k)
    throw (std::string)"There is no such item.";
  else if(r->left == NULL && k < r->k)
    throw (std::string)"There is no such item.";
  else if(k>r->k)
	return find(k,r->right);
  else if(k<r->k)
    return find(k,r->left);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  Node<Key,T>* checkHere = r;
  if(checkHere==NULL)
    throw (std::string)"Not a valid Node";
  while(checkHere->right != NULL){
    checkHere = checkHere->right;
  }
  return checkHere;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  Node<Key,T>* checkHere = r;
  if(checkHere==NULL)
    throw (std::string)"Not a valid Node";
  while(checkHere->left != NULL){
    checkHere = checkHere->left;
  }
  return checkHere;
}
