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
    
  virtual void removeAll(Node<Key,T>* r);

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
void BST<Key, T>::removeAll(Node<Key,T>* r){
    
    if (r->right != NULL){
            removeAll(r->right);
        }
    
    if (r->left != NULL){
            removeAll(r->left);
        }
    
    if (r->right == NULL && r->left == NULL){
        delete r;
        r = NULL;
        return;
    }
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  
  return size(root);
    
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
    
  if(r == NULL){
	  return 0;
  }
  else 
	  return 1+ size(r->left) + size(r->right);
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
    
    Node<Key, T>* temp = find(k, root);
    
    if(temp == NULL){
        throw std::string("There is no such item in the tree");
    }
    return temp->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
    
    return (find(k,root) != NULL);
    
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
    
    Node<Key, T>* temp = next(k, root);
    
    if(temp == NULL){
        return k;
    }
    return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
    
    if(r == NULL){
        
        return NULL;
    }
    if(k < r->k){
        
        Node<Key, T>* varNode = next(k, r->left); //varNode simply just stores the information of the
        if(varNode == NULL){                      //next node. This allows for comparison to NULL
            return r;
        }
        
        return varNode;
    }
    else{
        
         Node<Key, T>* varNode = next(k, r->right);
        return varNode;
    }
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  
    Node<Key, T>* temp = prev(k, root);
    
    if(temp == NULL){
        return k;
    }
    return temp->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
    
    if(r == NULL){
        return NULL;
    }
    if(k > r->k){
        
        Node<Key, T>* varNode = prev(k, r->right);
        
        if(varNode == NULL){
            return r;
        }
        
        return varNode;
    }
    else{
        
        Node<Key, T>* varNode = prev(k, r->left);
        
        if(varNode == NULL){
            return NULL;
        }
        
        return varNode;
    }
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
    
    if(r == NULL){
        r = new Node<Key, T>();
        r->k = k;
        r->data = x;
        r->right = NULL;
        r->left = NULL;
        
        return r;
    }
    if (r->k == k){
        r->data = x;
        return r;
    }
    if(k < r->k){
        r->left = add(k, x, r->left);
        
    }
    if(k > r->k){
        r->right = add(k, x, r->right);
        
    }
    
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
    
    if(r == NULL){
        return NULL;
    }
    Node<Key, T>* nodeToRemove;
    
    if(r->k == k){
        if(r->right == NULL && r->left == NULL){
            delete r;
            r = NULL;
            return r;
        }
        if(r->right == NULL){
            nodeToRemove = max(r->left);
        }
        else{
            nodeToRemove = min(r->right);
        }
        
        Node<Key, T> tempNode;
        tempNode.k = nodeToRemove->k;               //By far the hardest method to code
        tempNode.data = nodeToRemove->data;
        
        remove(nodeToRemove->k, r);
        
        r->k = tempNode.k;
        r->data = tempNode.data;
        
        return r;
    }
    if(k < r->k){
        r->left = remove(k, r->left);
    }
    else{
        r->right = remove(k, r->right);
        
    }
    return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
    
	if (r == NULL) {
        return NULL;
    }
    if (r->k == k) {
        return r;
    }
    if (k < r->k) {
        return find(k, r->left);
    }
    else {
        return find(k, r->right);
    }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
    
  if(r == NULL){
	  throw std::string("There is no max because there are no nodes in the tree");
  }
  else if(r->right == NULL){
	  return r;
  }
  else
	  return max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
    
  if(r == NULL){
	  throw std::string("There is no min because there are no nodes in the tree");
  }
    
  else if(r->left == NULL){
	  return r;
  }
    
  else
	  return min(r->left);
}

