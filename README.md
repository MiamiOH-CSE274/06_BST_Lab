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

1. Using recursion my methods are able to achieve a running time of O(h). The running time depends on the height of the tree because the methods work by running down the different levels starting from the root.
2. The size() method is O(n) because it has to visit every single node and therefore must run n amount of times.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

Exercise 6.7: 
preOrderNumber(){ number the root node as 0, the left child of the root becomes 1, any left children will continue to be numbered until there are no longer any left children nodes, travelling back up the tree any right child will be numbered until the root node is reached, travel down the root node's right child subtree the same way the left child subtree was traversed}
postOrderNumber(){ travel down the left child node as far as you can go and then label the first node that doesn't have a left child 0, travelling back up the tree go to the right child node numbering it 1, once all children are numbered the root of the subtree is numbered 2, continue going up the tree, when the root node is reach go down the right child subtree, follow the subtree path left until no more left children exist, then going back up number the right children, continue going up the tree until the root node is reached which will be the last node to be numbered}
inOrderNumber(){ travel down the left child node subtree as far left as you can go and number the last child 0, travelling back up the tree number the parent node 1, travel down the right child if there is one and number it 2, continue to go up the tree until the root node is reached and number it, go down the right child's subtree}

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

When does using recursion become not practical in real world situations? I didn't think that using recursion in this lab was weird, it seems to make more sense than using a loop but I know that using recursion can quickly create running times that are not suited for real world applications.