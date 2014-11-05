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

1. Overall I think I met this; however, my remove is not working completely for the third case, where the node to be removed has two children. It shows that the key no longer exists, but the size did not change.
2. I think size() is working and runs in O(n) time because it traverses the whole tree in order to count the nodes.  Since it visits every node, it will run in linear time.  If the number of nodes doubles, the running time will double since it visits all of them.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

#####Exercise 6.7
1. For the in order numbers, we can implement a recursive function called inOrderNumber with the following function declaration: `void inOrderNumber(Node* r)`. r is the root of the tree being passed. The base case will be if the root of the subtree (r) is NULL, return. Otherwise, call inOrderNumber on the left subtree, then assign a number to r, then call inOrderNumber on the right subtree.
2. In order to assing the pre-order numbers, we can implement a recursive function: `void preOrderNumber(Node* r)`. The base case will be if r is NULL, return. Otherwise, assign a number to r, call preOrderNumber on the left subtree of r, then call preOrderNumber on the right subtree.
3. To assign post-order numbers, implement a recursive function with declaration: `void postOrderNumber(Node* r)`. The base case will also be if r is NULL, return. Else, call postOrderNumber on the left subtree of r, then call it on the right subtree of r, then assign a number to r.

#####Exercise 6.9
1. // Still working
2. // Still working
3. There are two ways to determine if a node u is the ancestor of node w.  First, we can use the preOrder numbers.  Since we label nodes first before their subtrees, the ancestors are labeled first.  Thus, if the preOrder number for u is less than the preOrder number for w, u is an ancestor of w. Alternatively, we can use the postOrder numbers. Since we assign numbers to the subtrees before the root nodes, the ancestors are labeled last. Thus, if the postOrder number for u is greater than the postOrder number for w, u is an ancestor of w.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Advice for students: What helped me the most was to draw out pictures on a whiteboard or chalkboard of what happens during recursive methods. I drew a tree, then made a chart of what happens on the way down the call chain (which methods call which) and then what happens on the way back "up" - what does each call return, and what does the caller do with the returned value.