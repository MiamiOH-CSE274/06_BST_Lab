Author
==========
"Gardner, Daniel", gardnedn
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

1. all methods work O(h)...delete does not decrement size so the destructor is commented out for now.
2. size is O(n) as it has to loop through all the nodes.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7 --
traverse (Node r) {
//pre order
traverse (r->left);
//in order payload
traverse(r->right);
//post order payload.
}

6.9
1. Since post order is going down the tree and then doing something, the post order number here for u will be the size of the subtree rooted at u.
2. The preorder number would be able to be used for the depth of u as we are doing something before we work down the tree.
3. We can use the post order number of w and u, if u has a higher post order number than w than it is its ancestor, as we go through and then add up. If it has a smaller post order number than it is farther down.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
It took me a lot of read throughs to understand what exactly the next and prev were looking for. Just a little ambigious.
