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

1. All methods run times scale with the height of the tree except for size() and the destructor.
2. Size is O(n) and traverses the entire tree.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7
The method of pre order would have a sorted set of the numbers and would put them into the tree in ascending order, the post order would be sorted in descending order, and the in order would start at the middle of a sorted array of numbers to place them in the tree. The methods could simply use the arrays of sorted numbers to determine a number's place in that certain order using a find algorithm that fits with the function such as looping through for pre order, looping backwards for post order and a binary search for in order. The pre-order function would be something like preOrder(root->left), then preOrder(root->right), then look at itself. postOrder would be self first, then postOrder(root->left), and then postOrder(root->right). The inOrder would be inOrder(root->left), then itself, then inOrder(root->right).

6.9
While the methods finding the order numbers are assuming that the tree is balanced, they can find the subtree at some index with some accuracy. with the sorted array of values, and knowing the way the tree will be arranged, the methods can find the depth somewhat easily by determining what the root in that case would be and using the size of the array of values to determine the depth. The subtree at a certain index can be found with the depth calculation and simply determining whether children will be assigned to that node based on the depth in the tree. Ancestry can be found by using the depth for each of the two nodes and comparing which side of the tree they would be placed from the root node.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Don't forget about recursion, it is important to know and not difficult to understand.