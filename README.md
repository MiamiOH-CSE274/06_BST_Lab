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

1. The next and previous methods both invoke either max or min methods which may cause the tree to be searched more times than necessary.
2. Size was written using the recursive algorithm discussed in class.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7
preOrderNumber(int n, Node r){
if (r==NULL) {return NULL}

r.number = n
preOrderNumber(n+1, r->left)
preOrderNumber(n+1, r->right)
}

inOrderNumber(int n, Node r){
if (r==NULL) {return NULL}

inOrderNumber(n+1, r->left)
r.number = n
inOrderNumber(n+1, r->right)
}

postOrderNumber(int n, Node r){
if (r==NULL) {return NULL}
postOrderNumber(n+1, r->left)
postOrderNumber(n+1, r->right)
r.number = n;
}
 
6.9
1) Use to postOrderNumber function to find the number associated with the root node and that is the size.
2) Use the inOrderNumber function then go as far right as possible.  The number of steps will represent the size of the tree.
3) Use postOrderNumber to assign numbers to each node.  If the value of u is higher than w it is not an ancestor.  Next recursively check the subtree at w to see if u is contained and if so it is an ancestor.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Learning how to recursively call and use return in each function was a difficult process and the next and prev functions are very tricky.  