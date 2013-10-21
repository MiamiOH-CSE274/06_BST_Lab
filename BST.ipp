#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  //TODO
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO
   while (size()>0) {
        remove(root->k);
    }
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  //TODO
  return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  //TODO
   if (r == NULL) 
	return 0;
   return 1 + size(r->left) + size(r->right);
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
	if(root==NULL)
		return false;
	else if(k==root->k)
		return true;
	else if(k>root->k){
		root = root->right;
		keyExists(k);
	}
	else{
		root = root->left;
		keyExists(k);
	}
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  //TODO
  Node<Key, T>* temp = next(k, root);
  return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  //TODO
  Node<Key, T>* temp = find(k, r);
  while(temp->k<=k)
	temp = temp->right;
  return temp;
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
	r = new Node<Key, T>();
	r->data=x;
	r->k=k;
	r->right = NULL;
	r->left = NULL;
	return r;
  }
  else if(k==r->k){
	r->data = x;
	return r;
  }
  else if(k< (r->k)){
	r->left = add(k, x, r->left);
  }
  else if (k>r->k){
	r->right = add(k, x, r->right);
  }
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
