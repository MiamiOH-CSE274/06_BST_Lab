#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST() {
    root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST() {
    while (root != NULL)
    {
        root = remove(root->k, root);

        //Avoid suffering from dangling pointers.
        root = NULL;
    }
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size() {
    return size(root);
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r) {
    if (r != NULL)
    {
    return 1 + size(r->left) + size(r->right);
    }
    return 0;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key, T>::add(Key k, T x) {
    root = add(k, x, root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key, T>::remove(Key k) {
    remove(k, root);
}

//Return the item with Key k.
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key, T>::find(Key k) {
    Node<Key, T> *node = find(k, root);
    if (node == NULL)
    {
        throw std :: string("No such item");
    }
    else
    {
        return node->data;
    }
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k)
{
    return find(k, root) != NULL;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k) {
    Node<Key, T> *node = next(k, root);
    if (node != NULL)
    {
        return node->k;
    }
    else
    {
        return k;
    }
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r) {
    if (r == NULL)
    {
        return NULL;

    }

    //If k is bigger than r->k.
    //Searching to the right.

    else if (k > r->k)
    {
        return next(k, r->right);
    }
    else if (k < r->k)
    {
        //If k is less than r->k and the biggest key of left branch is bigger than k.
        //Searching to the left
        if(r->left != NULL && max(r->left)->k > k)
        {
            return next(k, r->left);
        }

        //If there is no left branch, or the biggest key of the left branch is smaller than k.
        else
        {
            return r;
        }
    }
    else{
        //If k == r->k
        if(r->right != NULL)
        {
            return next(k, r->right);
        }
        else
        {
            return NULL;
        }
    }
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k) {
    Node<Key, T> *node = prev(k, root);
    if (node != NULL)
        return node->k;
    else
        return k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r) {
    if (r == NULL)
        return NULL;
    else if (k > r->k){ // search to the right
         // if the left-most on the right side has less than the key,
        // search right
        if(r->right != NULL && min(r->right)->k < k) {
            return prev(k, r->right);
        }
        // if there's no right, or the left-most on the right branch is bigger
        // than the key, we're at the successor
        else
        {
            return r;
        }
    }
    else if (k < r->k){ // search to the left
        return prev(k, r->left);
    }
    else{
        // k = r->k, so get the left-most data.
        if(r->left != NULL) {
            return prev(k, r->left);
        }
        // there is no successor.
        else {
            return NULL;
        }
    }
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r) {
    if (r == NULL) 
        {
        //Create new node.
        r = new Node<Key, T>();
        r->k = k;
        r->data = x;
        r->left = r->right = NULL;
    } else if (k < r->k) 
    {
        r->left = add(k, x, r->left);
    } else if (k > r->k) 
    {
        r->right = add(k, x, r->right);
    }
    else 
    {
     // If an item with Key k already exists, overwrite it
        r->data = x;
    }
    return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r) {

    if (r == NULL) {/*do nothing*/}
    if (k < r->k)
    {
        r->left = remove(k, r->left);
    }
    else if (k > r->k)
    {
        r->right = remove(k, r->right);
    }

    //A node has two children.
    else if (r->left != NULL && r->right != NULL)
    {
        Node<Key, T> *minNode = min(r->right);
        
        //Swap data, from class note.
        r->k = minNode->k;
        r->data = minNode->data;
        
        r->right = remove(r->k, r->right);
        delete minNode;
        minNode = NULL;
    }
    else
    {
        r = (r->left != NULL) ? r->left : r->right;
    }
    return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r) {
    if (r == NULL)
    {
        return NULL;
    }

    //If k == r->, simply return the key.
    if (k == r->k)
    {
        return r;
    }

    //If k is less than current key.
    //Searching to left.
    else if (k < r->k)
    {
        return find(k, r->left);
    }
    //If k is bigger than current key.
    //Searching to right.
    else
    {
        return find(k, r->right);
    }
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r) {

    //To find the max, keep going to the right.
    if (r == NULL)
    {
        return NULL;
    }
    if (r->right == NULL)
    {
        return r;
    }
    return max(r->right);
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r) {

    //To find the min, keep going to the left.
    if (r == NULL)
    {
        return NULL;
    }
    if (r->left == NULL)
    {
        return r;
    }
    return min(r->left);
}
