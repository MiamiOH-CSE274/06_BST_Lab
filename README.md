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

1. All methods will be 0(h) because once they operate on the root node, they eliminate one half of the tree as those values are either too high or too low.  
2. Size is 0(n) because it goes through both branches of the tree, touching on every leaf.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

For 6.7:
	Pre-Order: The size function of the BST lab already visits the nodes in pre-order fashion, in that it indexes the root node, then traverses through the left subtree and then the right subtree. I would fashion 
		a pre-order function after the construction of the size function.
	In-Order: For this order, I would start from the min of the left subtree and use the next function until arriving at the root, then find the min of the right subtree and traverse through that subtree using 
		the next function again.
	Post-Order: This function requires the nodes to visited first in the left subtree, then the right subtree, then the root. I would probably fashion this after the find function again, repeatedly calling the 
		function to the next node in each subtree, and then add on the root node at the very end. 

For 9.9:
	A) If a node is given with the index of where it is in pre, post, or in order, you can find the depth of the tree in constant time by getting the min (and the count it takes to get there) of that subtree and then 
		adding one. 
	B) To get depth in these tree traversals, one can get the min of sub tree starting at u return the a count variable in a second function that returns the count.
	C) To find this, one can compare the w node to a the other nodes key and see if it is higher or lower in order to figure out if it is a ancestor or not.
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Start early!! This data structure requires one to think a bit more critically than the other data structures thus far.