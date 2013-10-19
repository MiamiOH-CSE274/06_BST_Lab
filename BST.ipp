#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
 // root= new Node();
 root=NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  //TODO
  return 0;
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
	if(root==NULL){
	root=new Node<Key, T>;
	root->k=k;
	root->data=x;
	}
	else
	root=add(k,x,root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
  //remove(k,root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  //TODO find(k,root);
  if(root==NULL)
	throw (std::string) ("Can't find it");
  if(root->k==k)
    return root->data;
  if(root->k>k)
	return find(k,root->left)->data;
  else
    return find(k,root->right)->data;
  //T fakeT;
  //return fakeT;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  if(find(k, root)==NULL)
  return false;
  else return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  /*if(keyExists (k)){
   Node<Key, T> q =find(k, root);
   if(q->right!=NULL)
     return q->right->k;
   else return k;
   }else*/
  return NULL;
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
  /*if(keyExists (k)){
   Node<Key, T> q =find(k, root);
   if(q->left!=NULL)
     return q->left->k;
   else return k;
   }else*/
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  if(r==NULL){
	Node<Key,T>* d= new Node<Key,T>();
	d->k=k;
	d->data=x;
	return d;//new Node(k, data);
  }
  
  else{if(r->k==k){
	r->data=x;
	return r;
	}
	else {
		if(k<r->k)
			r->left=add(k,x,r->left);
		else
			r->right=add(k,x,r->right);
	}
  }
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  if(r==NULL){
	
	return NULL;//new Node(k, data);
  }
  
  else{if(r->k==k){
		delete r;
		return null;
	}
	else {
		if(k<r->k)
			return remove(k,x,r->left);
		else
			return remove(k,x,r->right);
	}
  }
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  if(r==NULL)
	throw (std::string) ("Can't find it");
  if(r->k==k)
    return r;
  if(r->k>k)
    return find(k,r->left);
  else
    return find(k,r->right);
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  if(r->right==NULL)
	return r;

  return max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  if(r->left==NULL)
	return r;

  return max(r->left);
}
