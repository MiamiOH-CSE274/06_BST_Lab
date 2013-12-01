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

1. TODO
2. TODO

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.
void assignNum(node* r){         void assignNum(node* r){           void assignNum(node* r){
   if(node == NULL) return;         if(node == NULL) return;  		if(node == NULL) return;
   else{                            else{			        else{
      preOrderNumber();                assignNum(r->left);		   assignNum(r->left);
      assignNum(r->left);              inOrderNumber();			   assignNum(r->right);
      assignNum(r->right);             assignNum(r->right);		   postOrderNumber();
   }                                }			                }
}                                }				    }

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
delete() is very important and complicated. The advice I can share is to understand the logic before you start implementing it.