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

6.7

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO