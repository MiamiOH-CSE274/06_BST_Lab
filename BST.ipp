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
  Node<Key,T>* checkHere = root;
  Key ret = k;
  while(true){
    if(checkHere == NULL||checkHere->k==k)
	  break;
    else if(checkHere->k>k){
	  ret = checkHere->k;
	  checkHere = checkHere->left;
	}
	else if(checkHere->k<=k)
	  checkHere = checkHere->right;
  }
  return ret;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  Node<Key,T>* checkHere = root;
  Key ret = k;
  while(true){
    if(checkHere == NULL)
	  break;
    else if(checkHere->k<k){
	  ret = checkHere->k;
	  checkHere = checkHere->right;
	}
	else if(checkHere->k>=k)
	  checkHere = checkHere->left;
  }
  return ret;
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
  if(k==r->k){
    if(r->left!=NULL && r->right!=NULL){
	  delete r;
	  r=NULL;
	}
    Node<Key,T> replaceWith;
	if(r->left->right == NULL)
	  replaceWith = r->left;
	else{
	  replaceWith = r->left;
	  while(replaceWith->left!=NULL && replaceWith->right!=NULL){
	    if(replaceWith->right!=NULL)
	      replaceWith = max(replaceWith);
		if(replaceWith->left!=NULL)
		  replaceWith = min(replaceWith);
	  }
	}
	r->k=replaceWith->k;
	r-data=replaceWith->data;
	delete replaceWith;
  }
  if
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
