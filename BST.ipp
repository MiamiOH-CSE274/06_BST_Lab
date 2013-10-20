#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
    delete [] root;
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
  if (root == NULL) {
    root = new Node<Key, T>;
    root -> k = k;
    root -> data = x;
    root -> left = NULL;
    root -> right = NULL;
    }
  root = add(k, x, root);
    
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
    if (root == NULL)
        throw (std::string)("No root has been created");
    else if (root -> k == k)
        return root -> data;
    else if (k < root -> k)
        return find(k, root -> left) -> data;
    else
        return find(k, root -> right) -> data;
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  if (find(k, root) == NULL)
      return false;
    else
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
    if (r == NULL) {
      Node<Key, T>* toAdd = new Node<Key, T>();
        toAdd -> k = k;
        toAdd -> data = x;
        toAdd -> left = NULL;
        toAdd -> right = NULL;
        return toAdd;
    }
    else if (r -> k == k){
        r -> data = x;
        return r;
    }
    else if (k < r -> k)
        r -> left = add(k, x, r -> left);
    else if (k > r -> k)
        r -> right = add(k, x, r -> right);
    return r;
    
    }

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
    if (r == NULL)
        return false;
    else if (r -> k == k)
        return r;
    else if (k < r -> k)
        return find(k, r -> left);
    else if (k > r -> k)
            return find(k, r -> right);
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
