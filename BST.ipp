#define NULL 0
#include <string>

//find will take O(lgn)
//add & remove will be O(n)
//next & prev will be O(lgn)
//hash is O(1) for everything except next/prev which is O(n)

template <class Key, class T>
BST<Key, T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	//TODO
}

//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key, T>::size(){
	//TODO
	return 0;
}

template <class Key, class T>
unsigned long BST<Key, T>::size(Node<Key, T>* r){
	//TODO
	return 0;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key, T>::add(Key k, T x){
	root = add(k, x, root); //WHAT DO I DO HERE?!

}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key, T>::remove(Key k){
	//TODO
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key, T>::find(Key k){
	Node<Key, T>* temp = find(k, root);
	if (find(k, root) == NULL)	{
		throw std::string("Couldn't find key in find()");
	}
	else
	{
		return temp->data;
	}

}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key, T>::keyExists(Key k){
	if (find(k, root) == NULL)	{
		return false;
	}
	else
	{
		return true;
	}

}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::next(Key k){
	Node<Key, T>* tempNode = next(k, root);
	return tempNode->k;
	
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
	return r->right;
	
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	Node<Key, T>* tempNode = prev(k, root);
	return tempNode->k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	return r->left;
	
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL)	{
		//didn't find node, so add it
		r = new Node < Key, T > ;
		r->k = k;
		r->data = x;
		r->left = NULL;
		r->right = NULL;

		return r;
	}
	else if (r->k == k)	{
		//We gotta' overwrite this puppy
		r->data = x;
	}
	else if (k > r->k)	{
		r->right = add(k, x, r->right);
	}
	else {
		r->left = add(k, x, r->left);
	}
	return r;

	//return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	//TODO
	return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r == NULL)	{
		return NULL;
	}
	else if (r->k == k)	{
		return r;
	}
	else if (k < r->k)	{
		return find(k, r->left);
	}
	else{
		return find(k, r->right);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if(r == null)	{
		throw std::string("I goofed");
	}
	else if (r->right == NULL)	{
		return r;
	}
	else {
		return max(r->right);
	}
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if(r == null)	{
		throw std::string("I goofed");
	}
	else if (r->left == NULL)	{
		return r;
	}
	else {
		return max(r->left);
	}
}
