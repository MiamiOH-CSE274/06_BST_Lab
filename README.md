Author
==========
"Contini, Nick", continnd
06_BST_Lab
==============

Implement a binary search tree in C++

Requirements
------------

1. All methods except the destructor and `size()` should be O(h), where h is the height of the tree
2. `size()` should be O(n)

Reading
=======
"Open Data Structures," Chapter 6, the entire chapter. http://opendatastructures.org/ods-cpp/6_Binary_Trees.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Since every method only works using one of the branches of the tree, the longest of which is h, then the max number of operations in one method increases with the height of the tree.
2. size() has linear efficiency since the method essentially finds every non-NULL node and adds one. That means if you double the number of items, it will add twice as many ones and find twice as many items.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7:
  preorder(Node r){
	store number
	preorder(r->left);
	preorder(r->right;
  }
  postorder(Node r){
	preorder(r->left);
	preorder(r->right;
	store number
  }
  preorder(Node r){
	preorder(r->left);
	store number
	preorder(r->right;
  }

6.9:
  1. size(Node r){
	if(r !=NULL)
	  return 1 + size(r->left) + size(r->right);
	else
	  return 0;
     }
  2. depth(Key k, Node r){
	if(r==NULL)
	  return 0;
	if(r->k=k)
	  return 1;
	if(k>r->k)
	  return 1 + depth(k,r->right);
	if(k<r->k)
	  return 1 + depth(k,r->left);
      }
  3. ancestor(Key k, Node r, Key j){
	if(r==NULL)
	  return false;
	if(r->k == k)
	  return child(j,r->right) && child(j,r->left);
	if(r->k > k)
	  return ancestor(k,r->left,j);
	if(r->k < k)
	  return ancestor(k,r->right,j);
     }
     child(Key k, Node r){
	if(r==NULL)
	  return false;
	if(r->k==k)
	  return true;
	else
	  return child(k,r->right) || child(k,r->left);
     }
 
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The description of next and prev in the header file was not easy to understand. Also doing excercises 6.7 and 6.9 seems to be hard to do without explanation from an instructor, especially after putting so much into the programming part of the assignment itself.