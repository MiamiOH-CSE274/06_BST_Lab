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

1. All methods listed are 0(h)
2. size() is recursive and runs depending on how many items are in the tree so it is O(n)

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7

preOrderNumber()
assign root 0
traverse left subtree assigning 1
traverse back up right subtree assigning 2
Traverse recursively until all nodes assigned

inOrderNumber()
traverse left subtree and assign 0 to childless node
assign root (parent) 1
traverse right subtree assign 2
Traverse recursively until all nodes assigned

postOrderNumber()
traverse left subtree and assign 0 to childless node
traverse right subtree and assign 1
assign root 2
Traverse recursively until all nodes assigned

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Something that really helped me in this lab was to draw pictures for the harder methods, especially add and remove. It made it much easier to write the code.