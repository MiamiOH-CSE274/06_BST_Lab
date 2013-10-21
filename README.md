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

1. TODO
2. TODO

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7: 


Explanation: inOrder checks to see if it is null, 
inOrder(){
if(root!=null)
 then 
 int num=0
 root->inOrder=num
 
	num=inOrder(num, root->left)
	inOrder(num,root->right)
}

preoder(){
if(root!=null)
 then 
 int num=0
	num=inOrder(num, root->left)
	root->preOrder=num
	inOrder(num,root->right)
}
}



6.9:

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

R==null never works
