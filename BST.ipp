#define NULL 0
#include <string>
    
    template <class Key, class T>
    BST<Key,T>::BST(){
// We don't need to declare a pointer to the root just need to make a new Node for the root
// since we already declared the pointer in BST.h
    root = new Node<Key, T>;
    //root->left = NULL; // Not sure if we need these two lines or not. 
    //root->right = NULL;
}
// TODO
template <class Key, class T>
    BST<Key,T>::~BST(){
}

//Return the number of items currently in the SSet
template <class Key, class T>
    unsigned long BST<Key,T>::size(){
// Call the private root method which takes the root as the parameter.
    return size(root);
}

template <class Key, class T>
    unsigned long BST<Key,T>::size(Node<Key,T>* r){
    unsigned long numNodes = 0;
    if (r == NULL) {
        return 0;
    } else {
        // Count the number of nodes to the left and right of the root
        // node and add 1 to make sure you include the root node in the total.
        numNodes = 1 + size(r->left) + size(r->right);
        return numNodes;
    }
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
    Node<Key, T>* rtnNode = find(k, root);
    
    if (root == NULL || rtnNode->k != k) {
        throw std::string("No item found!");
    }
    else {
        return rtnNode->data;
    }
    
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
    bool BST<Key,T>::keyExists(Key k){
    if (root == NULL) 
		return false;
	else if (root->k == k) 
		return true;
	else if (k < root->k)
		return keyExists(root->left->k); 
	else 
		return keyExists(root->right->k);		 
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
 Key BST<Key,T>::next(Key k){
	Node<Key, T>* rtnNode = next(k, root);
	if (rtnNode == NULL) 
		return k;
	else 
		return rtnNode->k;
}

template <class Key, class T>
    Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
    if (r == NULL) 
		return NULL;
	else if (k > r->k) 
		return next(k, r->right); // Check all right nodes
	else {
		Node<Key, T>* temp = next(k, r->left); // Check all left nodes
	if (temp == NULL) 
		return r;
	else 
		return temp;
	}
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
    Key BST<Key,T>::prev(Key k){
    Node<Key, T>* rtnNode = prev(k, root);
	if (rtnNode == NULL) 
		return k;
	else 
		return rtnNode->k;
}

template <class Key, class T>
    Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
    if (r == NULL) 
		return NULL;
	else if (k < r->k) 
		return next(k, r->left); // Check all left nodes
	else {
		Node<Key, T>* temp = next(k, r->right); // Check all right nodes
	if (temp == NULL) 
		return r;
	else 
		return temp;
	}
}

// This add method has been used from Dr. Brinkman's class notes 
template <class Key, class T>
    Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
    if (r == NULL) {
        // If there is no node then create a new one and assign correct values.
        Node<Key, T>* newNode = new Node<Key, T>;
        newNode->k = k;
        newNode->data = x;
        return newNode;
    } else if (r->k == k) { // If the key is already in the tree then overwrite its data.
        r->data = x;
        return r;
    } else if (k < r->k) { // Try to add to the left side of the current node
        r->left = add(k, x, r->left);
    } else { // Try to add to the right side of the current node
        r->right = add(k, x, r->right);
    }
    return r;
}

// This remove method has been used from Dr. Brinkman's class notes 
template <class Key, class T>
    Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
    if (r == NULL) {
        return NULL;
    } else if (r->k == k) {
        if (r->left == NULL && r->right == NULL) {
            delete r;
            return NULL;
        }
        else if (r->left == NULL || r->right == NULL) {
            Node<Key, T>* newR = r->left;
            if (newR == NULL) {
                newR = r->right;
            }
            delete r;
            return newR;
        } else {
            Node<Key, T>* maxR = max(r->left);
            
            Key tempKey = maxR->k;
            maxR->k = r->k;
            r->k = tempKey;
            
            T tempData = r->data;
            r->data = maxR->data;
            maxR->data = tempData;
            
            r->left = remove(k, r->left);
            return r;
        } 
    } else if (k < r->k) {
        r->left = remove(k, r->left);
    } else {
        r->right = remove(k, r->right);
    }
    return r;
}

// This find method is based off of Dr. Brinkman's class notes. 
template <class Key, class T>
    Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
    if (r == NULL) 
        return NULL;
    else if (r->k == k) {
        return r;
    } else if (k < r->k) {
        return find(k, r->left);
    } else {
        return find(k, r->right);
    }
}

template <class Key, class T>
    Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
    if(r == NULL || r->right == NULL) {
        return r;
    }
    else 
        return max(r->right); 
}

template <class Key, class T>
    Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
    if(r == NULL || r->left == NULL) { 
        return r; 
    }
    else 
        return min(r->left);
}
