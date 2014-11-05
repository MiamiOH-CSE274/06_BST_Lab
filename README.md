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

1. All work. All methods are O(h) time except size witch is O(n) and the destructor which is also O(n).
2. works. Size is O(n) because it has to recursively count each element in the array. 

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7) 	preOrderNumber() function:
		function preOrderNumber(number, Node)
			if Node == NULL return
			
			print number first: node.number = number;
			recursively call left side: preOrderNumber(number + 1, Node->left)
			recursively call right side: preOrderNumber(number + 1, Node->right)
		end function

	inOrderNumber() function:
		function inOrderNumber(number, Node)
			if Node == NULL return
			
			 recursively call left side: preOrderNumber(number + 1, Node->left)
			 print number: Node.number = number
			 recursively call right side: preOrderNumber(number + 1, Node->right)
		end function

	postOrderNumber() function:
		function postOrderNumber(number, Node)
			if Node == NULL return

			recursively call left side: preOrderNumber(number + 1, Node->left)
			recursively call right side: preOrderNumber(number + 1, Node->right)
			print number: Node.number = number
		end function

6.9)	

1) if u.preOrderNumber = 0
	size = u.inOrderNumber + 1

2) Unsure of what you mean by depth

3) if u.inOrderNumber > w.inOrderNumber
	u is an ancestor of w
	

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

	Advice for next year: Build a BST that you don’t need to remove things from because the remove function is fairly challenging to implement. It gave me the most trouble.