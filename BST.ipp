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
  while(size() > 0)
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

  if(find(k, root) == NULL)
	throw std::string("No such item");

  return find(k,root)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  if(find(k, root) == NULL)
	return false;
  else
	return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
	Node<Key,T>* temp = next(k, root);

	if(temp == NULL)
		return k;
	else
		return temp->k;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){

  if(r->left != NULL && r->left->k > k)
	return next(k, r->left);
  else if(r->right != NULL && r->k < k)
	return next(k, r->right);
  return r;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  return prev(k, root)->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){

  if(r->right->k != NULL && r->right->k < k)
	return prev(k, r->right);
  else if(r->left->k != NULL && r->left->k >= k)
	return prev(k, r->left);
  else
	return r;
  
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){

  if(r == NULL) {
    r = new Node<Key, T>;
	r->k = k;
	r->data = x;
	r->left = NULL;
	r->right = NULL;
	return r;
  }
  else if(r->k == k)
	r->data = x;
  else if(r->k < k)
	r->right = add(k, x, r->right);
  else if(r->k > k)
	r->left = add(k, x, r->left);
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  
  if(r->right == NULL && r->left == NULL) {
	delete r;
	return NULL;
  }
  else if(r->right == NULL || r->left == NULL) {
	if(r->right == NULL) {
		prev(k, r)->left = r->left;
		delete r;
		return NULL;
	}
	else {
		prev(k, r)->right = r->right;
		delete r;
		return NULL;
	}
  }
  else {
	if(prev(k,r)->right == r) {
		prev(k,r)->right = min(r);	
		delete r;
		return NULL;
	}
	else {
		prev(k,r)->left = min(r);
		delete r;
		return NULL;
	}		
  }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){

  if(r == NULL)
	return NULL;
  else if(r->k == k)
	return r;
  else if(r->k < k)
	return find(k, r->right);
  else
	return find(k,r->left);

}

//Find the item in the sub-tree rooted at r which has the largest key
template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  if(r == NULL)
	return r;
  //Logic behind this is that if the tree is setup correctly, the last node on the right should be the largest
  while(r->right != NULL) {
	return max(r->right);
  }

  return r;
}

//Find the item in the sub-tree rooted at r which has the smallest key
template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  if(r == NULL)
	return r;
  //Logic behind this is that if the tree is setup correctly, the last node on the left should be the smallest
  while(r->left != NULL) {
	return min(r->left);
  }

  return r;
}
