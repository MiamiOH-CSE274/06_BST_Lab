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

1. All required methods should be completed in O(h) time.
2. Size takes O(n) since it has to visit every node in the tree.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

  preOrderNumber()
    give root node a number
    traverse left subtree recursively adding one each time
    traverse right subtree recursively adding one each time
  
  inOrderNumber()
    traverse left subtree recursively adding one each time
    give root node the next number
    traverse right subtree reursively adding one each time

  postOrderNumber()
    traverse left subtree recursively adding one each time
    traverse right subtree reursively adding one each time
    give root node the next number


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Remove in general I found was very complicated for this project. I would recommend students take extensive notes on the logic that happens behind the remove function.
