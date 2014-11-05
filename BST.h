//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/10/01

#include "SSet.h"

template <class Key, class T>
class Node {
public:
  Key k;
  T data;
  Node* left;
  Node* right;
};

template <class Key, class T>
class BST : public SSet <Key,T> {
 public:
  BST();
  ~BST();
  

  //Return the number of items currently in the SSet
  virtual unsigned long size();

  //Add a new item, x, with Key k.
  // If an item with Key k already exists, overwrite it
  virtual void add(Key k, T x);

  //Remove the item with Key k. If there is no such item, do nothing.
  virtual void remove(Key k);

  //Return the item with Key k. 
  // If there is no such item, throw an exception.
  virtual T find(Key k);
  //Return true if there is an item with Key k in the table. If not,
  // return false
  virtual bool keyExists(Key k);

  //If there is a key in the set that is > k,
  // return the first such key. If not, return k
  virtual Key next(Key k);
  //If there is a key in the set that is < k,
  // return the first such key. If not, return k
  virtual Key prev(Key k);

  virtual void removeAll(Node<Key, T> *r);

private:
  Node<Key,T>* root;

  virtual unsigned long size(Node<Key,T>* r);
  //These are the recursive versions of each of your methods.
  // You should return the address of the new root node, whether
  // or not the root node changes.
  virtual Node<Key,T>* add(Key k, T x, Node<Key,T>* r);
  virtual Node<Key,T>* remove(Key k, Node<Key,T>* r);

  //This one returns the address of the found node, NULL
  // if not found
  virtual Node<Key,T>* find(Key k, Node<Key,T>* r);

  //Find the item in the sub-tree rooted at r which has the smallest key
  virtual Node<Key,T>* min(Node<Key,T>* r);

  //Find the item in the sub-tree rooted at r which has the largest key
  virtual Node<Key,T>* max(Node<Key,T>* r);

  //Find the next/prev node, and return its address
  virtual Node<Key,T>* next(Key k, Node<Key,T>* r);
  virtual Node<Key,T>* prev(Key k, Node<Key,T>* r);

};

#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  removeAll(root);
}

template <class Key, class T>
void BST<Key,T>::removeAll(Node<Key,T>* r){
  if (r->right==NULL && r->left==NULL) {
		delete r;
		return;}
 else if (r->left !=NULL) {
		removeAll(r->left);}
 else if (r->right !=NULL) {
		removeAll(r->right);}
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  return size(root);
}


template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  if(r==NULL)
  { return 0;}
  else
	return 1+ size(r->left) + size(r->right);
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
	root = remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
	Node<Key, T>* tempNode = find(k, root);
	if(tempNode==NULL)
	{ throw std::string("find returned null"); }
	else
		return tempNode->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  if( find(k, root) !=NULL )
  { return true;}
  else
	 return false;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  Node<Key, T>* tempNode = next(k, root);
  if (tempNode==NULL)
	{ return k; }
  return tempNode->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	//if r is null, return null. if all the way right and null, return the last valid key.
	//if left is null, parent is key.

  if(r==NULL)
  { return NULL;}
  
  if (k >= r->k)
  {  Node<Key, T>* tempNode = next(k, r->right);
	 if(tempNode==NULL) 
		{return NULL;}
	 return tempNode;
  }
  else
  {  Node<Key, T>* tempNode = next(k, r->left);
	 if(tempNode==NULL) 
		 {return r;}
	 return tempNode;
  }
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
   Node<Key, T>* tempNode = prev(k, root);
   if(tempNode==NULL)
   {  return k;	}
  return tempNode->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
   if(r==NULL)
  { return NULL;}
  else if (k <= r->k)
  {  Node<Key, T>* tempNode = prev(k, r->left);
	 if(tempNode==NULL)
	 {return NULL;}
	 return tempNode;
  }
  else
  {  Node<Key, T>* tempNode = prev(k, r->right);
	 if(tempNode==NULL) 
	 { return r;}
	 return tempNode;
  }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  //if there are no nodes
	if(r==NULL)
	{   r = new Node<Key, T>();
		r->k = k;
		r->data = x;
		r->left=NULL;
		r->right=NULL;
		return r; 
	}
 //if the key already exists (update item though)
	else if(r->k==k)
	{  r->data=x; 
	   return r;}
//if the key is larger than given
	else if(k > r->k)
	{
	//	Node<Key, T>* tempNode = add(k, x, r->right);
		r->right = add(k, x, r->right);
		return r;
	}
//if the key is smaller than given
	else
	{
	//	 Node<Key, T>* tempNode = add(k, x, r->left);
		 r->left = add(k, x, r->left);
		 return r;
	}
	
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
 //There are no nodes to remove
	if(r ==NULL)
	{ return NULL; }
//check for match 
	else if(r->k == k)
	{ 
		//node for swapping
		 Node<Key, T>* swapNode;

		//removing a leaf 
		if(r->right==NULL && r->left==NULL)
		{
			delete r; 
			return NULL;
		}
		//two children- find the min/max to replace
		
		else if(r->left !=NULL)
		{ Node<Key, T>* lastNode = min(r->left);
		  swapNode->k= lastNode->k;
		  swapNode->data= lastNode->data;
		  
		  remove(lastNode->k, r);
		  r->k= swapNode->k;
		  r->data = swapNode->data;
		  return r; 

		}
		else
		{ Node<Key, T>* lastNode = max(r->right); 
		  swapNode->k= lastNode->k;
		  swapNode->data= lastNode->data;
		  
		  remove(lastNode->k, r);
		  r->k= swapNode->k;
		  r->data = swapNode->data;
		  return r; 
		
		}
	}
	else if(r->k < k)
	{ r->right=remove(k, r->right); }
	else
	{ r->left=remove(k, r->left);}
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  if(r==NULL)
  { return NULL;}
  else if(r->k == k)
  { return r; }
  else if(r->k > k)
  { return find(k, r->left); }
  else
  { return find(k,r->right); }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  if(r==NULL)
  { return NULL;}
  else if(r->right ==NULL)
  { return r;}
  else
  { return max(r->right); }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  if(r==NULL)
  { return NULL;}
  else if(r->left==NULL)
  { return r;}
  else
  { return min(r->left); }
}
