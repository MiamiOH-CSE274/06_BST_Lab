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

1. I truly believe that I know how to logically make these methods the right runtime but trying to code them just isn't going as planned
2. same here

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7
void preOrderNumber()
	label root
	preOrderNumber() left tree
	preOrderNumber() right tree

void inOrderNumber()
	inOrderNumber() left tree
	label root
	inOrderNumber() right tree

void preOrderNumber()
	preOrderNumber() left tree
	preOrderNumber() right tree
	label root

6.9
1)pre- 
  in- 
  post- 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
I think I'm mainly confused about how certain things are accessed in each method. maybe also, what happens when you try to access the root.