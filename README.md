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

1. All methods function and are in O(h) time, all except for remove_all, which has a bug I'm struggling to fix
2. Size functions properly and is in O(n) time because it cycles through all Nodes

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

Pre-Order: 
	
	-if(Node == NULL) return;
	
	-Assign 0 to the root Node key
	
	-preOrder(Node->left, k+1)
	
	-preOrder(Node->right, k+1)
	
In Order:
	
	-Find minimum value in tree, assign its key to zero
	
	-inOrder(node->left, k+1)
	
	-inOrder(Node->left, k+1)

Post-Order:
	
	-if(Node == NUll) return
	
	-find min of left tree, number it lowest key value, then repeat on right side of the tree
	
	-After all children are assigned values, assign the root the next available number;

6.9

1. Subtract u->pre from max(u)->pre and add one;

2. subtract max(u)->post from u->post

3. if (w->pre > u->re && w->post < u->post) return true;

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Write every function out on a piece of paper before hand and you will save a lot of time.