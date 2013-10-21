Author
==========
"Luo, Yu", luoy6
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

1. All methods except the destructor and `size()` are O(h), where h is the height of the tree
2. `size()` is O(n)

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

Exercise 6..7  

*function void preOrderNumber(Node* r)
 *if root node is null return;
 *else
	*visit the root
	*recursively call preOrderNumber using r->left as argument
	*recursively call preOrderNumber using r->right as argument

function void inOrderNumber(Node* r)
   if root node is null, return;
   else
		recursively call preOrderNumber using r->left as argument
		visit the root
		recursively call preOrderNumber using r->right as argument
		
function void postOrderNumber(Node* r)
   if root node is null, return;
   else
		recursively call preOrderNumber using r->left as argument
		recursively call preOrderNumber using r->right as argument
		visit the root
		
Exercise 6..9   
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO
