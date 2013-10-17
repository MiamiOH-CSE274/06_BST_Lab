#define NULL 0
#include <string>

int numItems;

template <class Key, class T>
BST<Key,T>::BST(){
	root = NULL;
	numItems = 0;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  for(int i = 0; i<numItems; i++)
	remove(root->k);
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  if(root == NULL){
	return 0;
  }
  else if(root->right==NULL && root->left==NULL){
	return 1;
  }
  else if(root->right!=NULL && root->left==NULL){
	return size(root->right)+1;
  }
  else if(root->right==NULL && root->left!=NULL){
    return size(root->left)+1;
  }
  else{
	return size(root->right)+size(root->left)+1;
  }
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  if(r->right == NULL && r->left == NULL){
	return 1;
  }
  else if(root->right != NULL && root->left == NULL){
	return size(r->right)+1;
  }
  else if(root->right == NULL && root->left != NULL){
    return size(r->left)+1;
  }
  else{
	return size(r->right) + size(root->left) + 1;
  }
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  if(root == NULL){
    root = new Node<Key,T>();
	root->data = x;
	root->k = k;
	root->right = NULL;
	root->left = NULL;
  }
  else if(k == root->k)
	root->data = x;
  else if(k > root->k)
	root->right = add(k,x,root->right);
  else if(k<root->k)
	root->left = add(k,x,root->left);
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
  if(root->k == k)
	return root->data;
  else if(root->right == NULL && k > root->k)
    throw (std::string)"There is no such item.";
  else if(root->left == NULL && k < root->k)
    throw (std::string)"There is no such item.";
  else if(k>root->k)
	return find(k,root->right)->data;
  else if(k<root->k)
    return find(k,root->left)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  Node<Key,T>* checkHere;
  checkHere=root;
  while(checkHere != NULL){
    if(k>checkHere->k)
	  checkHere=checkHere->right;
	else if(k<checkHere->k)
	  checkHere=checkHere->left;
	else if(k=checkHere->k)
	  return true;
  }
  return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  if(root->k>k)
    return root->k;
  else if(root->right!=NULL){
    Node<Key,T>* checkHere = next(k,root->right);
	if(checkHere = NULL)
	  return k;
	else
	  return checkHere->k;
  }
  else
    return k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  if(r->k>k)
    return r;
  else if(r->right!=NULL)
    return next(k,r->right);
  else
    return NULL;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  if(root->k<k)
    return root->k;
  else if(root->left!=NULL){
    Node<Key,T>* checkHere = next(k,root->left);
	if(checkHere = NULL)
	  return k;
	else
	  return checkHere->k;
  }
  else
    return k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  if(r->k<k)
    return r;
  else if(r->left!=NULL)
    return next(k,r->left);
  else
    return NULL;
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
  //TODO
  return NULL;
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
	return find(k,root->right);
  else if(k<r->k)
    return find(k,root->left);
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
