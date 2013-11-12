Author
==========
"Griffith, David", griffid5
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

1. All of the methods work in which the runtime is O(h) as we have learned in class because the height is the longest number of edges that each method will have to travel.
2. Since we have to go down both sides off the tree the runtime wouldn't be O(h) rather linear time becasuse we have to visit every node. 

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7: 
preOrderNumber(Node* r, int num) {
	r->data = num;
	while(r->left != NULL)
	preOrderNumber(r->left);
	while(r->right != NULL) 
	preOrderNumber(r->right);
}	

inOrderNumber(Node* r, int num) {
	while(r->left != NULL)
	inOrderNumber(r->left);
	r->data = num;
	while(r->right != NULL) 
	inOrderNumber(r->right);
}

postOrderNumber(Node* r, int num) {
	while(r->left != NULL)
	postOrderNumber(r->left);
	while(r->right != NULL) 
	postOrderNumber(r->right);
	r->data = num;
}

6.9:
1. I would use post order because given the node u, go through the entire tree and count the number of nodes on each side then just add 1 to get your total size. 

2. I would use in order because you could use a counter on the left side height then a counter on the right side height and which ever
is bigger take that number - 1 and you will have the depth of u.

3. I would use pre order because if you use w as current node you will go through each side
of the tree and can see if u is below it, in which it would be an ancestor of w. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The thing that most confused me about this assignment was the next/prev methods. When I orginally submitted the assignment I didn't fully understand when you are using the next method
that you have to look at the left subtree first then the right subtree, vice versa for the prev method. 