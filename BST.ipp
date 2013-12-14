#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
	root = NULL;
	numItems=0;
}

template <class Key, class T>
BST<Key,T>::~BST(){//this calls remove(root->k) as long as size() > 0. Assume remove and size work.
	for(numItems; numItems>0;){ //Only want to call size() once if possible. 
		remove(root->k);
	}
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){ //public, got rid of need to call private method.
	return numItems;
}

//this is the only function which cannot be done entirely with iteration (unless I use an explicit stack)
template <class Key, class T> /*Got rid of the need to call this method :)*/
unsigned long BST<Key,T>::size(Node<Key,T>* r){ //private. Also, no size variable this time. Really gonna force us to use recursion? Bah...
    unsigned long total = 0;					//Check if root is NULL, then add up left children and right children... Simple?

    if (r==NULL){
        return total;
    }

	total++; //each recursive step adds 1 for the node and an additional maximum of 2 for its children + maximum 2log(h-subtree).
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
  Node<Key,T>* myNode = next(k, root);
  if(myNode->k < k)
	  return k;
  return myNode->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	Node<Key,T>* cur = r;
	Node<Key,T>* above = r;
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
	Node<Key,T>* toReturn = prev(k, root);
	if(toReturn->k > k)
		return k;
	return toReturn->k; //can return k or the key less than k found by the private version.
}

//return the first key < k, or return k if no smaller key exists.
template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
	Node<Key,T>* cur = r;
	Node<Key,T>* above = r;
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
    Node<Key,T>* toAdd = new Node<Key, T>; toAdd->k = k; toAdd->data = x; //return r if r is not NULL
	if(r==NULL){
		numItems=1;
        return toAdd;
    }

	Node<Key,T>* cur = r;
	while(true){ //using infinite loops for good ;)
		while(k < cur->k){
			if(cur->left == NULL){
				cur->left = toAdd;
				numItems++;
				return r;
			}
			cur = cur->left;
		}
		while(k > cur->k){
			if(cur->right == NULL){
				cur->right = toAdd;
				numItems++;
				return r;
			}
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
	Node<Key,T> *toDelete = find(k,r), *toSwap, *above;
	if(toDelete==NULL)
		return r;
	
	
	if(toDelete->right == NULL){ //the idea here is to swap k and t between two nodes. the original, to be deleted, is actually saved
		if(toDelete->left == NULL){ //and the one it takes values from, is deleted in its place. Using the minimum of the right subtree or the maximum
			toSwap = toDelete;      //of the left subtree maintains BST order.
		} else{
			above = toDelete->left;
			toSwap = max(toDelete->left);
			while(above->right->k < toSwap->k){
				above = above->right;
			}
			if(toSwap->left != NULL)
				above->right = toSwap->left; //makes sure no child gets left behind
		}
			
	} else{
		above = toDelete->right;
		toSwap = min(toDelete->right);
		while(above->left->k > toSwap->k){
				above = above->left;
		}
		if(toSwap->right != NULL)
			above->left = toSwap->right; //makes sure no child gets left behind
	}

	toDelete->data = toSwap->data;
	toDelete->k = toSwap->k;
	toSwap = NULL;//necessary? Yes
	delete toSwap; //because deleting an integer doesn't reset it to NULL. 
	numItems--;
	return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
	if (r==NULL) {
		return NULL;
    }
	Node<Key,T>* cur = r;
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
