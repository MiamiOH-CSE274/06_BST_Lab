#include "BST.h"
#include <iostream>
#include <string>

void tests(){
  BST<int,std::string> myTree;
  myTree.add(1,"hi");
  myTree.add(0,"there");
  myTree.add(-1,"Friend");

  if(myTree.keyExists(1) != true){
    std::cout << "ERROR: Key 1 does not exist" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key 1 was found" << std::endl;
  }
  if(myTree.keyExists(-1) != true){
    std::cout << "ERROR: Key -1 does not exist" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key -1 was found" << std::endl;
  }
  if(myTree.keyExists(0) != true){
    std::cout << "ERROR: Key 0 does not exist" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key 0 was found" << std::endl;
  }

  if(myTree.keyExists(2) == true){
    std::cout << "ERROR: Key 2 exists" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key 2 was not found" << std::endl;
  }

  if(myTree.find(1) != "hi"){
    std::cout << "ERROR: Key 1 value incorrect" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key 1 value correct" << std::endl;
  }
  if(myTree.find(-1) != "Friend"){
    std::cout << "ERROR: Key -1 value incorrect" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key -1 value correct" << std::endl;
  }
  if(myTree.find(0) != "there"){
    std::cout << "ERROR: Key 0 value incorrect" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Key 0 value correct" << std::endl;
  }

  if(myTree.next(0) != 1){
    std::cout << "ERROR: next(0) should be 1" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: next(0) is fine" << std::endl;
  }
  if(myTree.next(2) != 2){
    std::cout << "ERROR: next(2) should be 2" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: next(2) is fine" << std::endl;
  }
  if(myTree.next(-2) != -1){
    std::cout << "ERROR: next(-2) should be -1" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: next(-2) is fine" << std::endl;
  }


  if(myTree.prev(0) != -1){
    std::cout << "ERROR: prev(0) should be -1" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: prev(0) is fine" << std::endl;
  }
  if(myTree.prev(2) != 1){
    std::cout << "ERROR: prev(2) should be 1" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: prev(2) is fine" << std::endl;
  }
  if(myTree.prev(-2) != -2){
    std::cout << "ERROR: prev(-2) should be -2" << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: prev(-2) is fine" << std::endl;
  }


}

int main(){
  tests();

  // Create a new tree for other tests and add several items
  BST<int, std::string> testTree;
  testTree.add(10, "ten");
  testTree.add(8, "Christy");
  testTree.add(12, "twelve");
  testTree.add(14, "fourteen");
  testTree.add(9, "nine");
  testTree.add(6, "six");
  testTree.add(5, "five");
  testTree.add(8, "eight");

  // Print out the size of the tree - it should be 5, since
  // key 8 was used twice
  std::cout << "Size of the tree: " << testTree.size() << std::endl;

  testTree.remove(5);
  std::cout << "Size of tree after case 1 remove: " << testTree.size();
  std::cout << " Does the removed key exist? " << testTree.keyExists(5) << std::endl;

  testTree.remove(12);
  std::cout << "Size of tree after case 2 remove: " << testTree.size();
  std::cout << " Does the removed key exist? " << testTree.keyExists(12) << std::endl;

  testTree.remove(8);
  std::cout << "Size of tree after case 3 remove: " << testTree.size();
  std::cout << " Does the removed key exist? " << testTree.keyExists(8) << std::endl;

  // Create an empty tree and test find's exception throwing
  BST<int, std::string>* aTree = new BST<int,std::string>();
  try{
	  (*aTree).find(45);
  }
  catch(std::string e){
	  std::cout << "Caught exception: " << e << std::endl;
  }

  return 0;
}
