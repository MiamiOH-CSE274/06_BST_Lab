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

1. All methods should be working in O(h) time.  All function calls are dependent upon the height h of the tree.
2. Size appears to be operating in O(n), since it must recurse for each node in the tree.

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7
class OrderedNode {
public:
  int preO;
  int postO;
  int inO;
}

Node preOrderNumber(int i, Node r) {
r -> preO = i; //presumably 0 for the initial call
i++;
if (r has no children)
  return NULL;
if (r has left child)
  return preOrderNumber(i, r -> left)
if (r has right child)
  return preOrderNumber(i, r -> right)
}

Node inOrderNumber(int i, Node r) {
if (r has left)
  return inOrderNumber(i, r -> left)
r -> inO = i;
i++;
if (r has right)
  return inOrderNumber(, r -> left);
}

Node postOrderNumber(int i, Node r){
if (r has left)
  return postOrderNumber(i, r -> left)
if (r has right)
  return postOrderNumber(i, r -> right)
r -> postO = i;
i++;
}

6.8
Node nextPreOrder(Node r){
if (r has left)
  return r -> left;
else if (r has right)
  return r -> right;
else return NULL;
}

Node nextInOrder(Node r){
if (r has no children && r > parent)
  return root
if (r has no children || (r has left && r has NO right))
  return r -> parent;
if (r -> right != NULL)
  return min(r -> right -> left)
}

Node nextPostOrder(Node r){
if (r has no parent)
  return r;
if (r > r -> parent || r -> parent -> right == NULL)
  return r -> parent;
if ( r -> parent has right)
  return min(r -> parent -> right);
}

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Writing the pseudo code for the pre/in/post order traversals was tricky.  It helped me most to follow the order of each traversal, and create cases to handle each one individually, instead of generalizing at first.  Then you can shrink your statements down to handle all nodes in the tree.