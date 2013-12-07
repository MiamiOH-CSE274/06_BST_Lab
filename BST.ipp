#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
   deallocate(root);
}

template <class Key, class T>
void deallocate(Node<Key, T>* r){
	if(r == NULL){
		return;
	}
	deallocate(r->left);	
	deallocate(r->right);
	delete r;
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
	return size(root);
}

// This method was implemented based on the reading materia
// http://opendatastructures.org/ods-cpp/6_1_Basic_Binary_Tree.html 
template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
	if(r == NULL){
		return 0;
	}
	return 1 + size(r->left) + size(r->right);
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
  return find(k, root)->data;
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  try{
	find(k);
  }
  catch(std::string e){
	return false;
  }
  return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  if(next(k, root)->k = NULL){
	return k;
  }
  else{
	return next(k, root)->k;
  }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  if(r == NULL){
	return r;
  }
  else if(r->k > k){
	return r;
  }
  else{
	next(k, root->right);
  }
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  if(prev(k, root) == NULL){
	return k;
  }
  else{
	return prev(k, root)->k;
  }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  if(r == NULL){
	return r;
  }
  else if(r->k < k){
	return r;
  }
  else{
	return prev(k, r->left);
  }
}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
	if(r == NULL){
		Node<Key, T>* node = new Node<Key, T>();
		node->data = x;
		node->k = k;
		node->right = NULL;
		node->left = NULL;
		return node;
	}
	else if(r->k == k){
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
  if(r == NULL){
	return NULL;
  }
  else if(r->k == k){
	// if this node does not have "kids"
	if(r->left == NULL && r->right == NULL){
		delete r;
		return NULL;
	}
	// if this node has one "kid"
	else if(r->left == NULL || r->right == NULL){
		Node<Key, T>* newRode = r->left;
		// if it is the right "kid", delete it right away
		if(newRode == NULL){
			delete r;
			return newRode;
		}
		// if it is the left "kid", swap it with the maximum node of 
		// the right subtree 
		else{
			Node<Key, T>* maxNode = max(r->left);
			// swap the key and value of the maximum node of left tree
			// with those of the target node
			Key tempKey = r->k;
			T tempData = r->data;
			r->k = maxNode->k;
			r->data = maxNode->data;
			maxNode->k = tempKey;
			maxNode->data = tempData;
			
			// delete the node that has been swapped to the left subtree
			r->left = remove(k, r->left);
			return r; 
		}
	}
	// search for the left subtree
	else if(r->k > k){
		r->left = remove(k, r->left);
	}
	// search for the right subtree
	else{
		r->right = remove(k, r->right);
	}
  }
}	

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  if(r == NULL){
	throw (std::string) "No such a item in the tree.";
  }
  else if(r->k == k){
	return r;
  }
  else if(k < r->k){
	return find(k, r->left);
  }
  else{
	return find(k, r->right);
  }
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  if(r == NULL){
	return NULL;
  }
  while(r->right != NULL){
	r = r->right;
  }
  return r;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  if(r == NULL){
	return NULL;
  }
  while(r->left != NULL){
	r = r->left;
  }
  return r;
}
