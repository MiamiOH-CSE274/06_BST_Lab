Author
==========
"Monnin, Sebastian", monninse
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

1. Everything other than the destructor and size() are O(h)
2. size is O(h) because it has to go to every node in the tree (h)

#### 2. Do exercises 6.7 and 6.9 on http://opendatastructures.org/ods-cpp/6_3_Discussion_Exercises.html. Keep in mind: You do NOT need to write real working code, you may write pseudo-code. In fact, that is preferred.

6.7 - preOrder(Node* r) I would create a varible called count and set it to 0. The root would be set to zero then I would recursively call preOrder(r->left) then preOrder(r->right)
      postOrder(node* r)  I would create a variable called count and set it equal to size. I would find the max of the root then set that equal to the new root. I would then recursively call postOrder(r->right) while setting the key of each equal to count-- then I would do postOder(r->left) 
      inOrder(Node* r) I would have count=0 then I would do recursive inOrder(r->left) setting each one to count++ then I would do recursive inOrder(r->left)
      
6.9 
1. I would just use a while loop to count until there was no more left and no more right then I would add them together
2. To find your depth in a pre or post order tree you could take the key for the preodered node and subtract it from the k of the post order node
3. go down below U to the right and left and if you ever find w then u is an ancestor
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I thought next and prev were really hard. I really spent a lot of time trying to get them to work either recursively or with a loop but couldn't seem to find a way to do it until I got help with it.
