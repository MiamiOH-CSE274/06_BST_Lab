06_BST_Lab sdsds
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

2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7 
preOrderNumber()
	start by giving the root node a number
	slide recursively down the left subtree until there is nothing to the left
	count up when it gets to the bottom
	slide recursively down the right subtree until there is nothing to the right
	count up when it gets to the bottom

inOrderNumber()
	slide recursively down the left subtree until there is nothing to the left
	count up when it gets to the bottom
	add one to the current number of nodes, and give this to the root node
	slide recursively down the right subtree until there is nothing to the right
	count up when it gets to the bottom

postOrderNumber()
	slide recursively down the left subtree until there is nothing to the left
	count up when it gets to the bottom
	slide recursively down the right subtree until there is nothing to the right
	count up when it gets to the bottom
	add one to the current number of nodes, and give this to the root node

6.9
6.9.1
	

3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Recursion seems to be something that is never going to go away. It's probably time to buckle down and just learn how it works if you don't understand it currently.