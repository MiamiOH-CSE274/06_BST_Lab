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

1. the destructor works by finding the end of a branch and then deleting it until there is just the root which then gets deleted. It works but efficiency isnt the best.
2. size works by adding one for each child then checking children for more children. recursion allows it to work for a tree of any size. It should run in O(N) time.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7
pre-order
Steps:
Fill in self.
Fill in left.
Fill in right.
Recursively call until all data has a node.

post-order
Steps:
Fill in left.
Fill in right.
Fill in self.
Recursively call until all data has a node.

in-order
Steps:
Fill in left.
Fill in self.
Fill in right.
Recursively call until all data has a node.
6.9
1.post order add both children and add 1.
2.in pre order tree go left until you reach null and the value of that leaf is your answer.
3.if U>W in a pre order tree then it is an ancestor.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Transversals and sorting through the tree still confuse me a bit. Advice would be have lots of paper with you to write it all out.
6.9 also gave me great difficulty in particular.