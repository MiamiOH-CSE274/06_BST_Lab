Author
==========
"Blase, Douglas", blasedd
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

1. All methods, except the destructor and `size()` are O(h), since they only take one path down the tree, so the method never steps back a level and takes a different path down the tree.
2. `size()` is O(n), as it only goes through the tree once, checking how many

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

For `preOrderNumber()`, I believe the method would work much like I have my `size()` working. The public method wouldn't take any parameters. The private method would take a node* and an unsigned long, with the node*`r` being the root and the unsigned long, `num` being 0. The method would return an unsigned long, as that's how it would keep track which number needs to be assigned. The method first assigns `num` to the node pointed to by `r`, which is then incremented. The method then checks to see if the node* has any left children. If it does, then `r` would be set to equal the result of the recursive method on `r->left`. This is done recursively until there are no more left children. Then the method checks for right children and follows the same process.

`inOrderNumber()` will have the same parameters as `preOrderNumer()` as well as the same return type. It will also work similarly to `preOrderNumer()` as well, the only difference being that the node does not receive it's in-order position until the node does not have a left child, so it recursively calls itself while `r->left` exists. Once it returns to a parent node, it's in-order number is assigned, and then the method assigns the positions for `r->right`.

Again, `postOrderNumber()` will have the same parameters and return types. It follows the exact same idea as `inOrderNumber()`, except the assignment of the post-order position does not happen until the method has been recursively called on all of its children, both left and right.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The question from the book (the above question) was confusing at first because it wasn't immediately clear which diagram corresponded to which type of ordering was being described in the paragraph above, since the caption and the text in the paragraph list the three types in different orders. Other than that, nothing was confusing.