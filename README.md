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

1. The running times of all methods besides size() are dependent on the height of the tree, which in an ideal balanced tree should be O(log(n)), as the recursive methods determine which side of the tree to go on, only visiting the ones it needs to.
2. Size() visits every single node in the tree, so the running time must be O(n).

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7 - 
Pre-order: Number the root node 0, then go down the left node, numbering it the next number available until reaching the final node in the left subtree, then go to the sibling of that node, continuing
down the same process until all nodes are numbered. Recursively, this would be done by numbering the first node, then calling the method on the left tree, then on the right tree.

In-order: Find the minimum value in the tree, numbering it 0, then go to the parent of that node and number it 1+(child value), then run the same method on the right subtree of that node until all nodes.
If a node is already numbered, go to the first non-numbered parent of that subtree and repeat the process.

Post-order: Go down the left tree until a leaf is found, numbering it the first avaiable number, then repeat the process on the right subtree, finally numbering yourself the next available number after
all children of that node are numbered.

6.9
1.
Pre-Order: Subtract the largest number in that tree by the number in u, and add 1.
Post-Order: Subtract the number of the sibling of that node to get the size of that subtree.
In-order: Subtract the number of the rightmost node by the number in the leftmost node and add 1.



#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Recursion is not simply a thing you have to learn to pass a class, it is an extremely useful resource that is used to solve problems simply and efficiently.