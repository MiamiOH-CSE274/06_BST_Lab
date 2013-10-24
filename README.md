Author
==========
"Bailey, Sam", baileys2
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

1. All of these methods should be in good working order.  Each of them, except for the destructor and size(), is O(h) because they go to each level of the current binary search tree only once, with the current tree being height h.
2. The size() method is working fine as well.  This method, unlike the other ones, is O(n), where n is the number of nodes in the tree, because the method goes to each node once in order to determine the overall number of nodes in the tree.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

Exercise 6.7

1. For the preOrder method, I would use one input parameter, a Node* r.  I would first use the min method to find the smallest value in the left side of the tree.  I would then use recursion to call this method again, with this input node set as the root r.  Using this node as the root point, I would be able to go through the rest of the tree and order the rest of the nodes by utilizing the next method.

2. For the inOrder method, I would use one input paramter, a Node* r.  I would first use the max method to find the largest value in the left side of the tree.  I would then use recursion to call this method again, with this input node set as the root r.  Using this node as the root point, I would be able to go through the rest of the tree and order the rest of the nodes by utilizing both the next and prev methods.

3. For the postOrder method, I would use one input parameter, a Node* r. I would first use the max method to find the largest value in the right side of the tree.  I would then use recursion to call this method again, with this input node set as the root r. Using this node as the root point, I would be able to go through the rest of the tree and order the rest of the nodes by utilizing the prev method.

Exercise 6.9

1. To determine the size of the subtree rooted at u using postOrder numbers.  

2. This problem could be solved using the inOrder numbers of the nodes.  I would take the inOrder number of u and subtract one from it to get that node's depth.

3. I would be able to determine this using the preOrder numbers of each of the nodes.  If u had a preOrder number that was less than the preOrder number of w then u would be an ancestor of w.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The two methods that confused me the most during this exercise were the next and prev methods.  The implementation of the max and min methods was a little hard to understand, and it took me a while to think my way through all of the possible situations to deal with (as well as the order in which I would have to address them).