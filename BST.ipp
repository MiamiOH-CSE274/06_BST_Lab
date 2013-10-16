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

  add(k, x, root);
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
  

  if(r==NULL){
	Node<Key, T>* newNode = new Node<Key, T>();
	return newNode;
  }
  else if(r->k==k){
	r->data = x;
	return r;
  }
  else if(k<r->k)
	r->left = add(k, r->left->data, r->left);
  else
	r->right = add(k, r->right->data, r->right);

  return r;
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  if(r==NULL)
	return NULL;
  else if(r->k==k){
	if(r->left==NULL&&r->right==NULL){
		delete r;
		return NULL;
	}
	else if(r->left==NULL||r->right==NULL){
		Node<Key, T>* newR = r->left;
		if(newR==NULL){
			newR = r->right;
		delete r;
		return newR;
		}
		else{
		Node<Key, T>* maxR = max(r->left);
		Key temp = maxR->k;
		maxR->k = r->k;
		r->k = temp;

		T tempD = maxR->data;
		maxR->data = r->data;
		r->data = tempD;

		r->left = remove(k, r->left);
		return r;
		}
	}

	else if(k<r->k)
		r->left= remove(k, r->left);
	else
		r->right = remove(k, r->right);

  }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  //TODO
  if(r==NULL)
	throw (std::string) "There Node is Null";
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
