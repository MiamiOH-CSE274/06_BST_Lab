#define NULL 0
#include <string>
#include <cmath>

template <class Key, class T>
BST<Key,T>::BST(){
  root=NULL;

 
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  int count = 0;
  return count;
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
  return next(k,root)->k;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
 Node<Key,T>* cur = find(k,root);
 Node<Key,T>* curUp = root;
 while(curUp->right != cur && curUp->left != cur) {
   if (k < curUp->k)
     curUp = curUp -> left;
  else 
    curUp = curUp ->right;
 }
 Node<Key,T>* maxNum = max(cur);
 if (abs(curUp->k - k ) < abs(maxNum->k - k))
   return curUp;
 else 
   return maxNum;

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
  std::cout<<r<<std::endl;
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

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  Node<Key,T>* cur = r;
  if (cur == NULL) {
    return NULL;
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
