Author
==========
"Kojs, Michelle", kojsmn
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

1. This requirement works. All methods except the destructor and size() are 0(h), where h is the height of the binary search tree. All these methods visit each level of the binary search tree once so this results in a running time of 0(h).
2. This requirement works. size() is 0(n), where n is the number of nodes, since each node is visited once in order to determine the size of the binary search tree.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7 - 	In order to write the method preOrderNumber() recursively I would keep a counter that would add 1 everytime that a new recursive call is made. This would allow me to assign the preOrderNumber of the r node. r is the parameter value for this method. Then I would recursively call preOrderNumber() on r's left tree and on r's right tree.  Each node would then be assigned a number in the order that that node was visited.
	In order to write the method inOrderNumber() recursively I would keep a counter that would add 1 everytime that a new recursive call is made. I would call inOrderNumber() on r's left tree. Then I would assign the counter to be the node r's inOrderNumber.  r is the parameter value for this method. Then I would recursively call inOrderNumber() on r's right tree. Each node would then be assigned a number in the order that that node was visited.
	In order to write the method postOrderNumber() recursively I would keep a counter that would add 1 everytime that a new recursive call is made. I would call postOrderNumber() on r's left tree and r's right tree. Then I would assign r's postOrderNumber to be the current counter. r is the parameter valud for this method. Each node would then be assigned a number in the order that that node was visited.

6.9 - 	1. In order to determine the size of the subtree rooted at u, I would use the postOrderNumber of the node u and add 1.  The postOrderNumber() method visits the starting root last so the starting root will have the highest post order number.
	2. In order to determine the depth of the u, I would use the inOrderNumber of the node u and subtract 1.  The inOrderNumber() method visits the starting root node in the middle of the method calls so it assigns the starting root node the number after the depth. To find the depth, 1 has to be subtracted.
	3. In order to determine if u is the ancestor of w, I would use the preOrderNumber of each node and if u's preOrderNumber is less than w's preOrderNumber, then u is an ancestor of w.


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

One question that confused me about this exercise was Question 2 part 6.7. I was confused about assigning a number to the node.