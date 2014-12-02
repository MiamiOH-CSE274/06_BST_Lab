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

1. All methods except the destructor and 'size()' iterate through one side of the tree, so it only has to go through h items, therefore running O(h) time.
2. Size traverses through the entire tree, so it is easily O(n).

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7: An in-order BinaryTree would act the same as the BST we made in this program. Therefore, the inOrderNumber() method would simply call the add(Key k, Node* r) method we have in this program, which is O(h). A pre-order would make the root node the first value, then the second value on the left, with the middle or median value on the right. For each node, the next value would be on the left, while the median value would be on the right of the new tree. This would take O(n). The postOrderNumbers() method would add new trees with quartiles. The first node would hold the median value, and following trees would contain a node value of the first and third quartiles on left and right, respectively. This way, the leftmost value would be the lowest, and the rightmost the highest. Again, this could take an add method O(n) time to add each and every node.

6.9: An in-order binary tree would be easy to recursively iterate through, traversing down the left of each node before the right, so that each node with children would check its left and right, incrementing for each node found. A A pre-order tree could find the rightmost node, giving it the depth of the tree with each new node found. A post-order tree could determine ancestry by finding the node's quartile and dividing each resulting list of nodes into thirds. If node u is the corresponding quartile while w is still in the list, u is an ancestor of w.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
I didn't understand 6.9, specifically what pre-, post-, and in-order mean.
