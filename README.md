Author
==========
"Bickley, Daniel", bickledb
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


1. Add takes O(h) time, because it goes down the correct subtree until it finds the correct place, which takes O(h) time.
	Remove takes O(h) time for similar reasons, after the Node is found, in the worst case scenario, remove calls min(), which takes O(h) time. The rest of remove is simply altering variables.
	Next takes O(h) time, because it goes through the correct subtree once to determine the best Node to return.
	Prev takes  O(h) time for the same reason why next does.
	Max takes O(h) time because it has to check every Node along a specific path to find the largest.
	Min takes O(h) time because it also has to cycle through a specific path to find the smallest overall.

2. Size is O(n), as it finds the number of items by recursively checking each child of each parent, checking all of the Nodes in the tree, forcing size() to have O(n) time.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7 

preOrderNumber(int numToAssign, Node* cur) {
	if (cur == NULL)
	  return;
	cur->preOrder = numToAssign;
	int next = numToAssign++;
	preOrderNumber(next, cur->left);
	preOrderNumber(next, cur->right);
}

inOrderNumber(int numToAssign, Node* cur) {
	if (cur == NULL)
	  return;
	inOrderNumber(next, cur->left);
	cur->inOrder = numToAssign;
	int next = numToAssign++;
	inOrderNumber(next, cur->right);
}

postOrderNumbers(int numToAssign, Node* cur) {
	if (cur == NULL)
	  return;
	postOrderNumbers(next, cur->left);
	cur->postOrder = numToAssign;
	int next = numToAssign++;
	postOrderNumbers(next, cur->right);
}
6.9
	1. You can use postOrder numbers to deterimne the size of the subtree rooted at U, as that will be the postOrder number of U.
	2. You can use the preOrder of U to determine the depth of the tree at U.
	3.  You can use the postOrder number to determine if U is an ancesstor of W, because if W's post order number is smaller than U's then U is an ancestor of W.


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The recursive nature of the BST gave me huge amounts of problems. I do not personally like recursion, and it is very hard for me to fully implement 
recursive functions. I would spend more time trying to understand recursion before trying to complete the lab.

