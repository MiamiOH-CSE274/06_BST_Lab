#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  //TODO
  
  // Initialize our tree with nothing in it	

  root = NULL;

}

template <class Key, class T>
BST<Key,T>::~BST(){
  //TODO

  // Delete all the nodes from the tree
  while(size(root)!=0){
	remove(root->k);
  }

}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  //TODO
  return 0;

  // returns size(Node<Key,T>* r) for the root, r.

}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  //TODO
  return 0;

  // Cancel out of recursion if the node is null, otherwise
  //   - Add one
  //   - Sum the left side
  //   - Sum the right side
  //   - return the sums of the above 3

}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  //TODO
  
  // Adds the node to the root, setting the root equal to the possible new root
  root = add(k, x, root);

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){
  //TODO
  return NULL;

  // First, make sure the root isn't null
  //	- If null, make a new node with the info, left and rights null, 
  //       and return the new node
  // Otherwise check to see if we're at the right node
  //	- If so, change the data in the node 
  //	- If not, then compare the keys
  //		- If the key is less than the node's key, add it to the node's left child
  //		- Otherwise, add it to the node's right child

  if(r==NULL){ //Creating a root or new node
	Node<Key,T>* node = new Node<Key,T>;
	node->k=k;
	node->data=x;
	return node;
  }
  else if(k==r->k){
	r->data=x;
	return r;
  }
  else if(k<r->k)
	add(k,x,r->left);
  else
	add(k,x,r->right);

}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
  //TODO

  // Call the other remove with k as the key on the root,
  //  setting the root equal to the new possible root.
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){
  //TODO
  return NULL;

  // First, check to see if the node is null
  //	- If so, return null
  // Next, compare our keys
  //	- If our key is less than the node's, call remove on the left child
  //	- Otherwise if our key is greater than the node's, call remove on the right child
  //	- If the keys are equal, check to see if it's a leaf, otherwise we'll have to fix the tree
  //		- If the node is a leaf (both left and right children are null), then
  //		   delete the node and return null
  //		- Otherwise, since the node isn't a leaf, check the children
  //			- if the node has a right child but no left,
  //			   hold onto the location of the right child, delete the current node, then return right child
  //			- Otherwise (node has a left child)
  //				- get the max node of the left child
  //				- swap the max node's keys and data with the root
  //				- remove the root's left child, setting  that equal to the root's left child
  //				- return the root

}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  //TODO
  T fakeT;
  return fakeT;

  if(find(k,root)==NULL){
	throw (std::string) "Your keys ain't here.";
  }else{
	return find(k,root)->data;
  }
  // If the root's null, throw an error, otherwise
  // call find on the root with the key

}




template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
  //TODO
  //return NULL;

  if(r==NULL)
	return NULL;
  else{
	if(r->k==k)
		return r;
	else if(r->k>k){
		find(k,r->left);
		}else{
			find(k,r->right);
			}

	return NULL;
  }

  // If the node is null, return null
  // If the node and the key are equal, return the node
  // If the node's key is larger, do find on the node's left child
  // Otherwise do find on the node's right child

}


//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
  //TODO
  return false;

  // As long as find doesn't return null, return true

}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
  //TODO
  Key fakeKey;
  return fakeKey;

  // Perform next on the root and return that key unless that's null
  //	- If it is null, return the key

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
  //TODO
  return NULL;

  // If the node's null, return null
  // Otherwise, check the key
  //	- If the node's key matches our key, return the node
  //	- If the key is larger than the node's
  //		- return next on the node's right child
  //	- If the key is less than the node's
  //		- If the left one is null or the node's left child's key is 
  //		   less than or equal return the node, return the node
  //		- Otherwise return next on the left child
  // Return null to catch anything that may get through

}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  //TODO
  return NULL;

  // Perform prev on the root and return that key unless that's null
  //	- If it is null, return the key

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  //TODO
  return NULL;

  // If the node's null, return null
  // Otherwise, check the key
  //	- If the node's key matches our key, return the node
  //	- If the node has a right node and its right node's key is less than k,
  //		return prev on the right child
  //	- If the key is greater than the node's
  //		- return the node
  //	- If the key is less than or equal to the node's
  //		- return prev on the left node
  // Return null to catch anything that may get through

}




template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  //TODO
  return NULL;

  // If the root's null, return null
  // If the right child isn't null, return max on right child
  // Otherwise return our node

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  //TODO
  return NULL;

  // If the root's null, return null
  // If the left child isn't null, return min on left child
  // Otherwise return our node

}
