Author
==========
"Zirkle, Andrew", zirkleac
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

1. I don't know how to get the 
2. I'm not sure size even works it seems like it doesn't want to take the 2 things I had it take

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7: 


inOrder(){
if(root!=null)
 then 
   //preorder print
   inOrder(root);
   //inorder print
   inOrder(root)
   //post order
}

6.9:
1. number of inorder calls left+ number of inorder right.
2. pre order number - post order number
3. if preorder and in order u are greater than w and w is greater than u in post order then u is an ancestor



#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

R==null never works unless initialized to null
