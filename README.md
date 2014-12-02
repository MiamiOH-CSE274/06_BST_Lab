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

1. Looks good. I'm not 100% certain but I'm pretty sure.
2. This I'm sure about...size is straightforward.  Cool stuff!

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

EXERCISE 6.7
BinaryTree Subclass SuperNode
	Stores numbers for all types of Tree Traversal using three functions.

function preOrderNumber(node, num) {
	If the node is null, return.
	Set the root node.pre = num.
	Recursively call left and increment.
	preOrderNumber(node.left, num++);
	Do the same for right.
	preOrderNumber(node.right, num++);
}

function inOrderNumber(node,num) {
	If node is null, return.
	Recursively call left and increment.
	inOrderNumber(node.left,num++);
	Set the current node.ino = num
	Now do the right subtree.
	inOrderNumber(node.right,num++);	
}

function postOrderNumber(node,num) {
	Same thing: if the node is null, return.
	Recursively call left and increment.
	postOrderNumber(node.left, num++);
	Now go right.
	postOrderNumber(node.right, num++);
	Set the current node.post = num.
}

	

EXERCISE 6.9
6.9.1: Given a node u, determine the size of the subtree rooted at u. {
	The postOrderNumber associated with the root node is the size.
	return u.post; (could be u.post -1 depending on your methods)
}

6.9.2: Given a node u, determine the depth of u. {
	The preOrderNumber associated with the min node plus one is the depth.
	node v = min(u);
	return v.pre + 1; (could be +0 depending on your methods)
}

6.9.3: Given two nodes u and w, determine if u is an ancestor of w. {
	In preOrder, ancestors always come before there descendants.  In  postOrder, they always come after. If both are true for nodes u and w, they are related in this way.
	if (w.pre < u.pre && w.pre > u.pre) return true;
	else return false;
}

	

	



#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I...I'm not sure how I'm supposed to think some of this stuff up on my own.  I'm very good at looking at someone elses code and copying/implementing their processes but bad at coming up with it.