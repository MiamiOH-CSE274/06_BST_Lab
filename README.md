Author
==========
"Emrick, Garrett", emrickgj
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

1. All of the methods should be O(h), except for of course the destructor and size.
2. Size is O(n) as instructed.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

Excercise 6.7

  preOrder(Node* r) find the min of the left subtree, then assign that as the root node, and go through data from there.

  postOrder(Node* r) find the max of the right subtree, then assign that as the root node, and go through the data from there.

  in-order(Node* r) find the max of the left subtree, then assign that as the root node, and go through the data from there.

Excercise 6.9

  1. If they are in order, you could subtract the max and the min and that will be the size of the subtree
  2. take the post and in order and then determine the depth.
  3. Search the pre nodes and search for the node w.


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The one thing I found confusing at first was just getting the thing to complile. I had a bunch of issues, and at one point a "Linker" error of some kind,
and had a very hard time figuring out why.

As for the BST, it wasn't too difficult as we discuessed methods in class, and I've had prior experience as well. The next/prev functions were the most difficult
of what we were assigned to do though.
