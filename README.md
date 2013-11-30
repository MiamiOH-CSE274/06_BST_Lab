Author
==========
"Proctor, Patrick", proctopj
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

1. destructor is between O(lg(h)) and O(n*lg(h)). Since 'h' keeps decreasing, and decreasing at a faster rate as the destructor runs,
   I'm not sure saying its running time is O(n*lg(h)) is appropriate.
2. It's O(1).

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7)
Class BinaryTree(){ //all that matters is position of the payload in relation to the recursive calls.
	int i=0;
	void preOrderNumbers(Node r){
		r.prekey = i;
		i++;
		if(r.left != NULL)
			inOrderNumbers(r.left);
		if(r.right != Null)
			inOrderNumbers(r.right);
	}
	void inOrderNumbers(Node r){
		if(r.left != NULL)
			inOrderNumbers(r.left);
		r.iokey = i;
		i++;
		if(r.right != Null)
			inOrderNumbers(r.right);
	}
	void postOrderNumbers(Node r){
		if(r.left != NULL)
			inOrderNumbers(r.left);
		if(r.right != Null)
			inOrderNumbers(r.right);
		r.postkey = i;
		i++;
	}
}

6.9)
1) given node u, determine size (height?) of subtree rooted there
2) given node u, determine the depth of the node
3) given nodes u and w, determine if u is an ancestor of w.

boolean isAncestor(Node u, Node w){
	if(u.pre < w.pre){
		if(u.post>w.post)
			return true;
		return false;
	}
	return false;
}

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Advice: This Lab and Heap are easily the toughest in the class. Be diligent. If you intend to leave projects for the last week of class, don't leave
	this particular one that long.