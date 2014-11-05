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

1. All methods will be 0(h), though I was not able to finish remove, the deconstructor, and prev in time so I will continue working on that in the future. 
2. Size is 0(n) because it goes through both branches of the tree, touching on every leaf.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

TODO

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Start early!! This data structure requires one to think a bit more critically than the other data structures thus far.