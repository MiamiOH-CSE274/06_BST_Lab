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
preOrderNumber(Node* r): If root node is null, then return. If root node is not null, first visit the root node, then recursively call preOrderNumber using r->left as argument, finally,recursively call preOrderNumber using r->right as argument

inOrderNumber(Node* r): If root node is null, then return. If root node is not null, first, recursively call preOrderNumber using r->left as argument, then visit the root node, finally, recursively call preOrderNumber using r->right as argument

postOrderNumber(Node* r): If root node is null, then return. If root node is not null, first, recursively call preOrderNumber using r->left as argument, then, recursively call preOrderNumber using r->right as argument, finally, visit the root node. 

Exercise 6..9   
1. 


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I was confused with the next and prev method. 
