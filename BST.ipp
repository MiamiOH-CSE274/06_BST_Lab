#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){//this calls remove(root->k) as long as size() > 0. Assume remove and size work.
	for(numItems; numItems>0; numItems--){ //Only want to call size() once if possible. 
		remove(root->k);
	}
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){ //public, got rid of need to call private method.
  return numItems;
}

template <class Key, class T> /*Got rid of the need to call this method :)*/
unsigned long BST<Key,T>::size(Node<Key,T>* r){ //private. Also, no size variable this time. Really gonna force us to use recursion? Bah...
    unsigned long total = 0;					//Check if root is NULL, then add up left children and right children... Simple?

    if (r==NULL){
        return total;
    }
	total++; //each recursive step adds 1 for the node and maximum of 2 for its children + maximum 2log(h-subtree).
    total += size(r->right);
    total += size(r->left);
   
    return total;
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
	remove(k, root); //I decided to not deal with relinking roots, so there is no need to rename the root Node
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
   Node<Key, T>* myNode = find(k, root);
    if (myNode==NULL) {
        throw std::string("Your desired key is not in the tree.");
    }
    return myNode->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){//calls private version
	Node<Key,T>* myNode = find(k, root);
	
    if (myNode==NULL) {
        return false;
    } else 
		return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){//calls private version
  Node<Key,T> myNode = next(k, root);
  if(myNode->k > k)
	  return myNode->k;
  return k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	Node<Key,T>* cur = r, above = r;
	while(true){
		while(cur->k > k){
			if(cur->left == NULL)
				return cur; //you found a minimum greater than k, below k
			above = cur; //ensures a lesser value remains above cur, whether or not cur becomes greater than k.
			cur = cur->left;
		}
		while(cur->k <= k){
			if(cur->right == NULL) 
				return above; //we have proven a greater key than k does not exist below our "above" pointer
			cur = cur->right;
		}
	}
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){//calls private version
	Node<Key,T>* toReturn= prev(k, root);
	if(toReturn->k > k)
		return k;
	return toReturn->k;
}

//return the first key < k, or return k if no smaller key exists.
template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	Node<Key,T>* cur = r, above = r;
	while(true){
		while(cur->k < k){
			if(cur->right == NULL)
				return cur; //you found a maximum
			above = cur; //ensures a lesser value remains above cur, whether or not cur becomes greater than or equal to k.
			cur = cur->right;
		}
		while(cur->k >= k){
			if(cur->left == NULL) 
				return above; //we have proven a lesser key than k does not exist below our "above" pointer
			cur = cur->left;
		}
	}
}


//Recursion when building is for stupid people...
template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){ //must check if r is null, if the key of root is the same, 
    if(r==NULL){										  //return r if r is not NULL
        Node<Key,T>* myNode = new Node<Key, T>;
        myNode->k = k;
        myNode->data = x;
		numItems++;
        return myNode;
    } //else if(keyExists) -- no need to call this method. I can just take care of it in add()
		//return r;

	Node<Key,T>* cur = r;
	Node<Key,T>* toAdd = new Node<Key, T>; toAdd->k = k; toAdd->data = x;
	while(true){ //using infinite loops for good ;)
		while(k < cur->k){
			if(cur->left == NULL){
				cur->left = toAdd;
				numItems++;
				return r;
			} else
				cur = cur->left;
		}
		while(k > cur->k){
			if(cur->right == NULL){
				cur->right = toAdd;
				numItems++;
				return r;
			} else
				cur = cur->right;
		}
		if(k == cur->k){
			cur->data = x;
			delete toAdd;
			return r;
		}
	}//end while(true)
}//end private version of add

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){//private version, switches keys and Ts instead of dealing with relinking the root.
	Node<Key,T>* toDelete = find(k,r);
	if(toDelete==NULL)
		return NULL;
	bool leftPtr = true, rightPtr = true;
	while(leftPtr || rightPtr){
		leftPtr = false; rightPtr = false;
		while(toDelete->right != Null){
			rightPtr = true;
			toDelete->k = toDelete->right->k;
			toDelete->data = toDelete->right->data;
			toDelete = toDelete->right;
		}
		while(toDelete->left != Null){
			leftPtr = true;
			toDelete->k = toDelete->left->k;
			toDelete->data = toDelete->left->data;
			toDelete = toDelete->left;
		}
	}
	delete toDelete;
	return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
	if (r==NULL) {
		return NULL;
    }
	node<Key,T>* cur = r;
    while(true){ //using infinite loops for good ;)
		while(k < cur->k){
			if(cur->left == NULL){
				return NULL;
			} else
				cur = cur->left;
		}
		while(k > cur->k){
			if(cur->right == NULL){
				return NULL;
			} else
				cur = cur->right;
		}
		if(k == cur->k)
			return cur;
	}//end while(true)
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
	Node<Key,T>* cur = r;
	while(cur->right != NULL){
		cur = cur->right;
	}
	return cur;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
	Node<Key,T>* cur = r;
	while(cur->left != NULL){
		cur = cur->left;
	}
	return cur;
}
