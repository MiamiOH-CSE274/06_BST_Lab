Author
==========
"Decker, Benjamin", deckerbd
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

1. Works in required way in required time
2. ^

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7:  For all 3 of the methods, take in a Node* and return a Node*, with some int keeping track of how deep it is
Pre-order:
	If node is a leaf, return NULL
	If node has left child, run pre-order on the left
	If node has a right child, run pre-order on the right
In-order:
	If node has a left child, run in-order on the left
	If node is a leaf, return NULL
	If node has a right child, run in-order on the left
Post-order: 
	If node has a left child, run post-order on the left
	If node has a right child, run post-order on the right
	If node is a leaf, return NULL

6.9:
	1.) Assuming it means height by size, take the max and min of the node, then subtract both to get the height.
	2.) Take the pre-order number and subtract the post-order number, which will give you 
	3.) if(postorder(u)<w&&(preorder(u)>w)&&postorder(u)>w), return true;
	

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

It's a lot easier to do recursion work if you don't worry so much about getting back into recursion, but more what to do in each case of recursion. Once you start seeing the similarities between each case, it's easier to see the logic behind the recurring method.


Running Time Analysis
===========

#### 1. constructor - This is constant time (O(1)) due to the constructor just setting a local variable value to NULL

#### 2. destructor - Due to the destructor having to pass by every node within the structure in order to delete it, the running time is linear time (O(n)).

#### 3. size - For this part, size can be either linear (O(n)) or constant (O(1)). If we know that the root is null, we can instantly pass back 0 in constant time. However, if it isn't null, we'll have to visit every node in the tree in order to sum them up. Because we have to visit every node within the tree, our runtime otherwise will be linear time.

#### 4. add - For the first call of add on a node, if the node is null, the resulting code is all just assignments of values which is done in constant time (O(1)). Also if the first call, if the key matches the root's key, we'll just be changing the value, which will be constant time. However, if we at any point in recursion need to transverse down either the left or right sub-tree, our recursion will be based on how far down we go down the tree. Because of this, the height of the tree dictates our running time, leaving us with a runtime of O(h).

#### 5. find - For the same reasons of add, find is also a runtime of O(h), with h being the height of the tree. If our first call through the method returns r==NULL or the keys matching, the method will be done in constant time, just like add. However, if we do need to recurse down either side branch, the height of the tree will be the limiting factor for how long the recursion goes on. For this reason, the runtime of find, like add, is O(h).

#### 6. remove - Just like find and add, if this is our first run, if r==NULL, the method will not be depending on the height of the tree nor the amount of items in the tree, leaving us with constant time (O(1)). However, if the keys match and the node is a leaf node (defined as both its left and right child being null), we can simply delete the root and return out in constant time. However, if either of these two conditions aren't true, or its our second or more pass through via recursion, the method's runtime will be dictated by how far down the recursion path it goes, which depends on the children, being the height of the tree. For this reason, the runtime under the other circumstances is O(h).

#### 7. keyExists - For this method, if we ever have to return false, the runtime will be constant time due to it also being when find will return in constant time. Otherwise, within the method find() will be in O(h) time, meaning keyExists will also be in at least O(h) time. Since nothing else in the method relies at all on the amount of things in the tree or the height and is just returning a simple value, the runtime is O(h).

#### 8. next - For the same reason add is O(h), next is O(h). Because this method relies on the same type of logic as add and is, we're once again relying on the height of the tree. For this reason, the running time is O(h).

#### 9. prev - For the same reason next is O(h), prev is also O(h); the only difference in prev and next is a few logic changes, otherwise it still has the height of the tree as the determining factor for how long it will run. For this reason, the running time is O(h).

#### 10. max - If the root's null, max will run in constant time due to it just immediately returning null. However, if it doesn't, we'll be transversing down the tree to the right until we no longer can, showing a reliance on the height of the tree being the limiting factor for recursion. For this reason, max is O(h) if the root isn't null, otherwise constant time (O(1)).

#### 11. min - If the root's null, min will run in constant time due to it just immediately returning null. However, if it doesn't, we'll be transversing down the tree to the left until we no longer can, showing a reliance on the height of the tree being the limiting factor for recursion. For this reason, min is O(h) if the root isn't null, otherwise constant time (O(1)).