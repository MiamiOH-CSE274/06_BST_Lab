#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  Node root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){ //public, calls private method;
  //TODO
  return 0;
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){ //private. Also, no size variable this time. Really gonna force us to use recursion? Bah...
  //TODO
  return 0;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){ //this calls private version, gets back a Node*
  root = add(k, x, root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){//public, calls private version
  //TODO
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  //TODO
  T fakeT;
  return fakeT;
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


//Not sure whether iteration or recursion is more effective for this...
template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){ //must check if r is null, if the key of root is the same, 
    if(r==NULL){
        Node<Key,T>* myNode = new Node<Key, T>;
        myNode->k = k;
        myNode->data = x;
        return myNode;
    }
    else if(r->k==k){
        r->data = x;
        return r;
    }
    else if(r->k > k)
        r->left = add(k, x, r->left);
    else
        r->right = add(k, x, r->right);
    
    return r;
}//end private version of add

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){//private version, make intelligent recurse right/left choices based on k. (check if r is NULL?)
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  //TODO
  return NULL;
}
