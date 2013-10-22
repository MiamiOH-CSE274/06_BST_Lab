Author
==========
"Zhong, Mingwei", zhongm2
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

1.All methods except the destructor and size() is O(h). I used recursion 
strategy.

2.Size() is O(n). In function size(), it calls size(Node<Key,T>* r) directly.
Running time depends on how many nodes in the BST.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

Exercises 6.7:

************************preOrder**************************

           void function preOrder(Node* r)

           int num = 0;

           if r is not NULL

           //Assign num to the node.

           r->number = 0;

           num++;

           preOrder(r->left);

           preOrder(r->right);

 

************************postOrder*****************************

          void function postOrder(Node* r)

          int num = 0;

          if r is not NULL

          postOrder(r->left);

          postOrder(r->right);

          r->number = num;

          num++;


***********************InOrder**********************************

          void function InOrder(Node* r)

          int num = 0;

          if r is not NULL

          InOrder(r->left);

          r->number = num;

          num++;

          InOrder(r->right);




****************************************************************

Exercises 6.9:


*********************QuestionOne********************************
        
	Let num1 be the number of right child of given node, u, from
        pre-order binary tree.

	Let num2 be the number of left child of given node, u, from
	pre-order binary tree.

	Let num3 be the number of right child of given node, u, from
	post-order binary tree.

	Let num4 be the number of left child of given node,u, from
	post-order binary tree.

	Therefore, the size of sub-tree of given node u is:

	(num1 - num2) + (num3 -num4) + 1.

          

*********************QuestionTwo********************************
        
	Let the num1 be the number of parent node of given node, u.

	Therefore, the depth of given node is: num1 level.
      

*********************QuestionThree*******************************

          Let the pre-order numbre of node u to be num1.

	  Let the post-order number of node u to be num2.
          
	  Let the pre-order number of node w to be num3.

	  Let the post-order number of node w to be num4.

	  if(num1 < num3 && num2 > num4)  => u is an ancestor of w. 
         





#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

In order to implement BST successfully, using recursion is the best way to go 
for. Unless the data in your BST is gigantic, which is possible to let your
program "stack overflow".



