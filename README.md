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
2. I think size() is working and runs in O(n) time because it traverses the whole tree in order to count the nodes.  Since it visits every node, it will run in linear time.  If the number of nodes doubles, the running time will double since it visits all of them.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

**Exercise 6.9**
1. // Still working
2. // Still working
3. There are two ways to determine if a node u is the ancestor of node w.  First, we can use the preOrder numbers.  Since we label nodes first before their subtrees, the ancestors are labeled first.  Thus, if the preOrder number for u is less than the preOrder number for w, u is an ancestor of w. Alternatively, we can use the postOrder numbers. Since we assign numbers to the subtrees before the root nodes, the ancestors are labeled last. Thus, if the postOrder number for u is greater than the postOrder number for w, u is an ancestor of w.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO