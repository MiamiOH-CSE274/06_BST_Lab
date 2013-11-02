#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root=NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){
while(size()!=0){
root=remove(root->k,root);
}
root=NULL;

}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){
  //TODO
  
return size(root);
}

template <class Key, class T>
unsigned long BST<Key,T>::size(Node<Key,T>* r){
  //TODO
  
  
   if(root==NULL)
  return 0;
  
  
  return 1+size(r -> right) + size(r-> left);

}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){
  //TODO
  
  root= add(k,x,root);
  
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){
 remove(k,root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
  
  
  if(root==NULL)
  throw(std::string) "root is NULL";
  
  
  return find(k,root)->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){
 
 if(find(k,root)==NULL)
 return false;
 
 
 
 
 return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){
 
 
 if(noode==NULL){
  return k;
  }
  
  return noode->k;
}
// I was having problems with this method until I looked at Luo6's to try to get help
template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
 if(r==NULL){
   return NULL;
   
   }

   
     else if(k<r->k){
   
   if(next(k, r->left)!=NULL){
     return next(k, r->left);
     }
   
   
   else
     return r;
    }
   
   else if(r->k<k){
   return next(k, r->right);}
   
   

   else{
   
   
   if(r->right==NULL){
     return NULL;}
     
     

   else
     return  next(k, r->right);;
   }

  
 
  
    }

}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){
  Node<Key,T>* noode=prev(k,root);
  
  if(noode==NULL)
  return k;
 
  
   
     return noode->k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
 

if(r==NULL){
   return NULL;
   
   }

   
     else if(k>r->k){
   
   if(next(k, r->right)!=NULL && max(r->right)->k>k){
     return prev(k, r->right);
     }
   
   
   else
     return r;
    }
   
   else if(r->k>k){
   return prev(k, r->left);}
   
   

   else{
   
   
   if(r->left==NULL){
     return NULL;}
     
     

   else
     return  prev(k, r->left);;
   }

  
 
  
    }


     




}


template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){

if(r==NULL){
   r = new Node<Key, T>;
   r->data=x;
   r->k=k;
   
  
   r->right = NULL;
   r->left = NULL;


return r;}
else if(r->k==k){
r->data=x;
return r;
}
else if(k<r->k){
r->left=add(k,x,r->left);
}

else{
r->right=add(k,x,r->right);
}
return r;


}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){


if(r==NULL){
  return NULL;
  }
  
  
  else if(r->k==k){
  if(r->left==NULL && r->right==NULL){
  delete r;
  return NULL;
  }
  
  }

  else if(r->left==NULL || r->right==NULL){
  Node<Key,T>* newR= r->left;
 
  if(newR==NULL){
  newR=r->right;
  delete r;
  return newR;
  
  }
  
  else{
  Node<Key,T>* maxR=max(r->left);
  Key temp=maxR->k;
  maxR->k=r->k;
  r->k=temp;
  
  T tempData=maxR->data;
  maxR->k=r->k;
  r->data=tempData;
  
  
  
  r->left=remove(k,r->left);
  return r;
  }
}
else if(k < r->k)
r->left = remove(k,r->left);

else
r->right=remove(k,r->right);

return r;

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
//TODO
  if(r==NULL){
  return NULL;
  }
  
  else if(r->k==k){
  return r;
  }
 
  else if((k<r->k)){
  return find(k,r->left);
  }

  return find(k,r->right);



}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
 if(r->right==NULL)
 return NULL;

 while(r->right!=NULL){
 r=r->right;}
 return r;


}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  //TODO
  return NULL;
}
