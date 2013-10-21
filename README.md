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

Exercise 6..7   Create a subclass of  $ \mathtt{BinaryTree}$ whose nodes have fields for storing pre-order, post-order, and in-order numbers. Write recursive methods  $ \mathtt{preOrderNumber()}$,  $ \mathtt{inOrderNumber()}$, and  $ \mathtt{postOrderNumbers()}$ that assign these numbers correctly. These methods should each run in  $ O(\ensuremath{\mathtt{n}})$ time.

Exercise 6..9   Suppose we are given a binary tree with pre-, post-, and in-order numbers assigned to the nodes. Show how these numbers can be used to answer each of the following questions in constant time:
Given a node  $ \mathtt{u}$, determine the size of the subtree rooted at  $ \mathtt{u}$.
Given a node  $ \mathtt{u}$, determine the depth of  $ \mathtt{u}$.
Given two nodes  $ \mathtt{u}$ and  $ \mathtt{w}$, determine if  $ \mathtt{u}$ is an ancestor of  $ \mathtt{w}$
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO