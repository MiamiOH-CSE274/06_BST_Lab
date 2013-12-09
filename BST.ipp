#define NULL 0
#include <string>
#include <cmath>

template <class Key, class T>
BST<Key,T>::BST(){
  root=NULL;

 
}

template <class Key, class T>
BST<Key,T>::~BST(){
  while(root != NULL)
    remove(root->k,root);
}

template <class Key, class T>
void keysInOrder(Node<Key,T>* r) {
  if (r == NULL)
    return;
else {
  std::cout<<""<<" ";
  keysInOrder(r->left);
  }



}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r) {
  int count = 0;
  if (r == NULL)
    return 0;
  else{
    count = 1;
	}
    return count + size(r->left) + size(r->right);
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  root=add(k,x,root);
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
  return find(k,root)-> data;
  }

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  Node<Key,T>* cur = root;
  while(cur != NULL) {
    if (cur->k == k)
	  return true;
	else if(k > cur-> k)
	  cur = cur->right;
	else if(k < cur->k)
	  cur = cur->left;
  }
  return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  Node<Key,T>* rtn = next(k,root);
  if (rtn == NULL) 
   return k;
  return rtn->k;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  Node<Key,T>* cur = root;
  Node<Key,T>* best = root;
  if (k > max(root)->k) {
    return NULL;
  }
  while (cur != NULL) {
    if (k < cur->k)
	  cur = cur -> left;
	else if (k > cur-> k)
	  cur = cur-> right;
	else if (k == cur->k) 
	  return best;
	 if (cur!= NULL && cur-> k < best-> k && cur->k > k)
	    best = cur;
  }
  return best;
}

//If there is a key in the set that is < k
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
Node<Key,T>* rtn = prev(k,root);
  if (rtn == NULL) {
   return k;
   }
  return rtn->k;



}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
   Node<Key,T>* cur = root;
  Node<Key,T>* best = root;
  if (k < min(root)->k)
    return NULL;

  while (cur != NULL) {
    if (k < cur->k) {
	best = cur;
	  cur = cur->left;
	}
	else if (k > cur ->k) {
	  cur = cur-> right;
	}

	else if (k == cur->k)
	  return cur->left;
  }
  return best;
    
  

 
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  if(r == NULL) {
    r = new Node<Key,T>();
	r->k = k;
	r->data = x;
	r->left = NULL;
	r->right = NULL;
	return r;
  }
  else if (r->k==k) {
    r->data = x;
	return r;
  }
  else if(k < r->k) {
    r->left = add(k,x,r->left);
	return r;
  }
  else if(k > r->k) {
    r->right = add(k,x,r->right);
	return r;
  }
  return r;
}

//Remove method was figured out while working with Doug Blaise
//while studying for exam, our methods could be similar.
template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
    if (r == NULL)
	  return NULL;
	if (k < r->k)
	  return r->left = remove(k,r->left);
	if (k > r-> k)
	  return r->right = remove(k,r->right);
	if (k== r->k) {
	  if (r -> left == NULL && r->right == NULL) {
	    delete r;
		return NULL;
	}
	if(r->left != NULL && r->right != NULL) {
	  Node<Key,T>* toCopy = min(r->right);
	  Key temp = r->k;
	  T tempData = r->data;
	  r->data = toCopy->data;
	  r->k = toCopy->k;
	  toCopy->data = tempData;
	  toCopy->k = temp;
	  if (k < r->k)
	    return r->left = remove(k,r->left);
	 if (k > r-> k)
	   return r->right = remove(k,r->right);
	}
	if (r->left != NULL || r->right != NULL) {
	  Node<Key,T>* toCopy = r->left;
	  if (toCopy == NULL)
	    toCopy = r->right;
	  delete r;
	  return toCopy;
	}
	}
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  Node<Key,T>* cur = r;
  if (cur == NULL) {
    throw std::string("This key does not exist. Please choose a different one.");
  }
  if (cur->k == k) {
    return cur;
  } else if (cur-> k > k) {
    cur = find(k,cur->left);
  } else {
    cur = find(k,cur-> right);
  }

  return cur;


}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  Node<Key,T>* cur = r;
  while(cur -> right != NULL) {
    cur = cur->right;

  }
  return cur;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  Node<Key,T>* cur = r;
  while(cur -> left != NULL) {
    cur = cur->left;

  }
  return cur;
}
