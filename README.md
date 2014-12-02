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

1. Worst case running time for the other methods will be O(h). This is because the tree is most likely not balanced (it would be between a tall & skinny tree, and a short &
 wide one). The shorter and wider it is, the better the running time (since it would be searching through
less "levels.") Best case running time is O(lg n), but we would need a self balancing tree, or to put the data in random order before adding it to a tree.
2. Size has to be O(n), because it adds 1 for every node it reaches, and it has to reach all the nodes, making it linear time. 

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7
inOrderNumber() we did in class ~ if the root is null, do nothing. Otherwise, inOrderNumber(root->left), assign ascending numbers, print the "self" node, and do the same
thing for the right side (inOderNumber(root->right);
postOrderNumber()~ the main root calls to the left subtree first, assigns numbers, heads to the right subtree, assigns numbers, then assigns whatever is the root a number. (so left child, right child, then root)
preOrderNumber() ~ assign the root a value, go down the left tree and assign the new root a number, and go to the right tree and that root a number (after left subtree is done). 

6.9
To determine the size, in preOrder, you could subtract the root number from the rightmost value of the tree.
Mod u's assigned number by the root number (-shot in the dark. i have no idea)
In postOrder you can see if w is greater than u's left child. If it is, then it is an ancestor. (?)

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

It helped me to write it out on paper before I coded it (drawing trees, going through case scenarios, etc).