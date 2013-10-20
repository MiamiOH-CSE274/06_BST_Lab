#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
    root = new Node< Key, T>;
}

template <class Key, class T>
BST<Key,T>::~BST(){
    while (size()>0) {
        remove(root->k);
    }
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
    return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
    unsigned long numItems = 0;
    if (r==NULL){
        return numItems;
    }
    else numItems++;
    if (r->left==NULL) {
        numItems += size(r->right);
    }
    
    else if (r->right==NULL) {
        numItems+= size(r->left);
    }
    
    else{
        numItems += size(r->right);
        numItems+= size(r->left);
    }
    
    return numItems;

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
    Node<Key, T>* data = find(k, root);
    if (data==NULL) {
        throw (std::string)"This key does not exist in the tree.";
    }
    return data->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
    Node<Key,T>* data = find(k, root);
    
    if (data==NULL) {
        return false;
    }
    else return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
   
    Node<Key, T>* toReturn=root;
    
    toReturn = next(k, root);
    
    if (toReturn==NULL) {
        return k;
    }
    
    return toReturn->k;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
    
    Node<Key,T>* previousPtr=r;
    Node<Key,T>* curPtr = r;
    
    while (curPtr !=NULL) {
        if (curPtr->k > k) {
            previousPtr = curPtr;
            curPtr = curPtr->left;
        }
        else if (curPtr->k < k){
            previousPtr = curPtr;
            curPtr = curPtr->right;
        }
        else{
            curPtr = curPtr->right;
        }
    }
    
    if (previousPtr->k <k) {
        return NULL;
    }
    
    return previousPtr;
   }

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
    
    Node<Key, T>* toReturn=root;
    
    toReturn = prev(k, root);
    
    if (toReturn==NULL) {
        return k;
    }
    
    return toReturn->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
    Node<Key,T>* previousPtr=r;
    Node<Key,T>* curPtr = r;
    
    while (curPtr !=NULL) {
        if (curPtr->k < k) {
            previousPtr = curPtr;
            curPtr = curPtr->right;
        }
        else if (curPtr->k > k){
            previousPtr = curPtr;
            curPtr = curPtr->left;
        }
        else{
            curPtr = curPtr->left;
        }
    }
    
    if (previousPtr->k >k) {
        return NULL;
    }
    
    return previousPtr;
}



template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
    if (r==NULL) {
        Node<Key,T>* toAdd = new Node<Key, T>;
        toAdd->k = k;
        toAdd->data = x;
        return toAdd;
    }
    else if (r->k==k){
        r->data = x;
        return r;
    }
    
    else if(r->k > k){
        r->left = add(k, x, r->left);
    }
    
    else{
        r->right = add(k, x, r->right);
    }
    
    return r;
 
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
    if (r == NULL) {
        return NULL;
    }
    else if (r->k==k){
        if (r->left==NULL && r->right==NULL) {
            delete r;
            return NULL;
        }
        else if (r->left==NULL || r->right==NULL){
            Node<Key, T>* newR = r->left;
            if (newR==NULL) {
                newR = r->right;
            }
            delete r;
            return newR;
        }
        else{
            Node<Key, T>* maxR = max(r->left);
            Key temp = maxR->k;

            maxR->k = r->k;
            r->k = temp;
            T dataTemp = r->data;
            r->data = maxR->data;
            maxR->data = dataTemp;
            r->left = remove(k, r->left);
            return r;
        }
    }
    
    else if (r->k >k){
       return r = remove(k, r->left);
    }
    
    else return r= remove(k, r->right);
    
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
    if (r==NULL) {
        return NULL;
    }
    else if (k==r->k){
        return r;
    }
    else if (k>r->k){
        return find(k, r->right);
    }
    else return find(k, r->left);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
    if (r==NULL) {
        return NULL;
    }
    else if (r->right==NULL){
        return r;
    }
    
    else return max(r->right);
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
    if (r==NULL) {
        return NULL;
    }
    else if (r->left==NULL){
        return r;
    }
    
    else return min(r->left);
}
