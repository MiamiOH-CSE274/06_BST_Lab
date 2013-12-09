Author
==========
"Mullins, Harrison", mullingh
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

1. Working
2. Working

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7:
```
	u->preOrderNumber is initialized to 0;
	preOrderNumber(u, count) {
		u->preOrderNumber += count;
		count++;
		while(u->left != NULL)
			preOrderNumber(u->left);
		while(u->right != NULL)
			preOrderNumber(u->right);
	}
	
	inOrderNumber(u, count) {
		while(u->left != NULL)
			inOrderNumber(u->left);
		u->inOrderNumber += count;
		while(u->right != NULL)
			inOrderNumber(u->right);
	}
	
	postOrderNumber(u, count) {
		while(u->left != NULL)
			postOrderNumber(u->left);
		while(u->right != NULL)
			postOrderNumber(u->right);
		u->postOrderNumber += count;
	}
```
6.9: 

1. Using the post order number I would take the largest item in the subtree minus the smallest item and add 1 to get the size. 

2. If U is a leaf node then you can take the preOrder number - the postOrder number to get the depth.  Otherwise I can't figure out how to get it.

3. Using the pre order number I would take u's number and compare it to w's number, if u is less than w then it is it's ancestor.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The next() and prev() methods ended up taking way more time than I would have thought, the logic was actually quite confusing. Also the questions for this homework were much more challenging than some of the previous questions in the past.