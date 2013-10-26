#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
    root=NULL;
//    root->right=NULL;
//    root->left=NULL;
    //int numItems=0;
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
  //TODO
  return 0;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
     add(k,x,root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
  //TODO
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){

    return find(k,root)->data;
//  T fakeT;
//  return fakeT;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  return true;
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
  //looked at https://github.com/MiamiOH-CSE274/06_BST_Lab/blob/blasedd/BST.ipp 
  //because I could not get it to make a new node, which i needed to add the Node<Key,T>* before it.
    if (r==NULL){
       
        Node<Key,T>* newNode = new Node<Key, T>;
          newNode->k=k;
        newNode->data=x;
       return newNode;
        //root=Node(k,x);
    }
    else if (r->k==k) {
        r->data = x;
    }
    else if (k<r->k) {
        r->left= add(k, x,r->left);
    }
    else {
        r->right=add(k, x,r->right);
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
  
    if (root==NULL) {
        throw (std::string) "key does not exist";
    }
    else if (root->k==k){
        //return root->x;
    }
    else if (k<root->k) {
        return find(k, root->left);
    }
    else {
        return find(k,root->right);
    }
    
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
