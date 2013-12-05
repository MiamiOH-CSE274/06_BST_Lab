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
    //size does not decrement with size but if it did the below code would work.
//    while (size()>0) {
//        remove(root->k);
//    }
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
    
    return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
        //book
      if (r==NULL)
      return 0;
        return 1+ size(r->left) +size(r->right);

}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
    //looked at https://github.com/MiamiOH-CSE274/06_BST_Lab/blob/blasedd/BST.ipp
    //reason it was not catching was because instead of just calling add(k,x,root) i meant to assign the root node to add(k,x,root).
    root = add(k,x,root);
    
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
    
    
    remove(k, root);
}

//Return the item with Key k.
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
    if (find(k,root)==NULL) {
        throw (std::string) "Key does not exist";
    }
    return find(k,root)->data;
    
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
    //Node<Key,T>* temp = find(k,root);
    
    if (find(k,root)==NULL) {
        return false;
    }
    else return true;
    
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
    if (next(k, root)==NULL) {
        return k;
    }
    else return next(k,root)->k;
    
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
    if (r==NULL) {
        return NULL;
    }
    else if (!(r->left==NULL)) {
        if (r->left->k>k) {
            return next(k, r->left);
        }
    }
    if (r->k > k) {
        return r;
    }
    else if (r->k <=k) {
        return next(k,r->right);
    }
    
    
    //    if (k<r->k) {
    //        return r;
    //    }
    //    if (k>r->k) {
    //        return next(k,r->left);
    //    }
    //TODO
    return NULL;
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
    if (prev(k, root)==NULL) {
        return k;
    }
    else return prev(k,root)->k;
    
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
    //If there is a key in the set that is < k,
    // return the first such key. If not, return k
    
    
    if (r==NULL) {
        return NULL;
    }
    else if (!(r->right==NULL)) {
        if (r->right->k < k) {
            return prev(k, r->right);
        }
    }
    if (r->k < k) {
        return r;
    }
    else if (r->k >=k) {
        return prev(k,r->left);
    }
    
    //TODO
    return NULL;
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
    //looked at https://github.com/MiamiOH-CSE274/06_BST_Lab/blob/blasedd/BST.ipp
    //because I could not get it to make a new node, which i needed to add the Node<Key,T>* before it.
    //noticed that I needed it to be r instead of root for if statements, as we did in class.
    if (r==NULL){
        
        Node<Key,T>* newNode = new Node<Key, T>;
        newNode->k=k;
        newNode->data=x;
        return newNode;
        //root=Node(k,x);
    }
    else if (r->k==k) {
        r->data = x;
        return r;
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
    //Remove the item with Key k. If there is no such item, do nothing.
    if (r==NULL)
        return NULL;
    
    else if (r->k ==k) {
        if (r-> left ==NULL && r->right==NULL) {
            delete r;
            return NULL;
        }
        if (r-> left ==NULL || r->right==NULL){
            Node<Key,T>* newR = r->left;
            if (newR==NULL) {
                newR = r->right;
            
            }
            delete r;
            return newR;

                    }
        else {
            Node<Key,T>* maxR = max(r->left);
            Key keyTemp=maxR->k;
            maxR->k = r->k;
            r->k=keyTemp;
            T tempData = maxR->data;
            maxR->data = r->data;
            r->data = tempData;
            r->left = remove(k, r->left);
            return r;
            
        }
    }
    else if(r->k<k)
                r->right = remove(r->right->k,r->right);
            else
                r->left = remove(r->left->k,r->right);
            return r;
    
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
    //mistakenly put root->left instead of r->left. small typo. Being unable to find that for a very long time, I had looked at https://github.com/MiamiOH-CSE274/06_BST_Lab/blob/blasedd/BST.ipp
    //and https://github.com/MiamiOH-CSE274/06_BST_Lab/blob/continnd/BST.ipp
    //but ultimately did not need their code. We had done the find method in class
    //and keyExists was simple enough, the typo was the problem. as keyExists was only ever to check
    //root->left and never farther left than that.
    
    if (r==NULL) {
        //needs Null for keyExists();
        return NULL;
        // throw (std::string) "key does not exist";
    }
    else if (r->k==k){
        return r;
    }
    else if (k<r->k) {
        return find(k, r->left);
    }
    else {
        return find(k,r->right);
    }
    
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
    //Find the item in the sub-tree rooted at r which has the largest key
    if (r==NULL) {
        return NULL;
    }
    else if (r->right!=NULL) {
        return max(r->right);
    }
    else return r;
    
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
    if (r==NULL) {
        return NULL;
    }
    else if (r->left!=NULL) {
        return min(r->left);
    }
    else return r;
}
