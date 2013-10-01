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

  return 0;
}
