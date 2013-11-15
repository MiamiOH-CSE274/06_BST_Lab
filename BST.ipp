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
   while (root!=NULL) 
        root = remove(root->k, root);
    
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
  root = add(k, x, root);
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
  if(root==NULL)
	throw (std::string) "The Node is Null";
  return find(k, root)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  //TODO
  if (find(k, root) == NULL)
      return false;
  return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  //TODO
  Node<Key, T>* temp = next(k, root);
  if(temp == NULL)
	return k;
  return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  //TODO

  if(r==NULL)
	return NULL;

// if the key is greater that the root key, the look in the right.
// if the the right node is null, return null, otherwise, keep
// looking in the right
  else if((r->k)<k){
	if(r->right!=NULL)
		return next(k, r->right);
	else
		return NULL;
  }
  else if((r->k)>k){
	if(next(k, r->left)==NULL)
		return r;
	else
		return next(k, r->left);
   }
  else{
	return next(k, r->right);
  }
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  //TODO
  Node<Key, T>* temp = prev(k, root);
  if(temp==NULL)
	return k;
  return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  //TODO
   if (r == NULL)
        return NULL;
    else if (k > (r->k)){ 
        if(prev(k, r->right)==NULL) 
            return r;
        else
            return prev(k, r->right);;
    }
    else if (k < (r->k)) 
        return prev(k, r->left);
    
    else{
			 return prev(k, r->left);
    }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  //TODO
  
  if(r==NULL){
	r = new Node<Key, T>();
	r->data=x;
	r->k=k;
	r->left = NULL;
	r->right = NULL;
  }
  else if(k==(r->k)){
	r->data = x;
  }
  else if(k< (r->k)){
	r->left = add(k, x, r->left);
  }
  else{
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
		Node<Key, T>* newN = r->left;
		if(newN==NULL){
			newN = r->right;
			delete r;
			return newN;
		}
		else{
			Node<Key, T>* maxN = max(r->left);
			Key temp = maxN->k;
			maxN->k = r->k;
			r->k = temp;

			T tempD = maxN->data;
			maxN->data = r->data;
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
	return NULL;
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
