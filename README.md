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

1. all methods besides the constructor and size use recursion to navigate the tree to find the node it needs.  because of this, the average case for each method should be O(h).
2. size() must look at every element in the tree to determine the size, therefor it is O(n).

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7)

	function pre_order_number(node, number):
	 if node is null then return

	 node.number = number
	 pre_order_number(node.left, number + 1)
	 pre_order_number(node.right, number + 1)
	end function
	 
	function in_order_number(node, number):
	 if node is null then return

	 in_order_number(node.left, number + 1)
	 node.number = number
	 in_order_number(node.right, number + 1)
	end function

	function post_order_number(node, number):
	 if node is null then return

	 post_order_number(node.left, number + 1)
	 post_order_number(node.right, number + 1)
	 node.number = number
	end function

6.9)

1)
	given a node u
		if u.pre = 0
			size = u.post + 1
		
			

2)
	
3)

	given nodes w and u, determine if u is an ancestor of w:
	 if w.pre > u.pre and w.post < u.post
	  return true
	 return false

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO
