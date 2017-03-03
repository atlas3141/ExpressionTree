#include <iostream>
#include "BinaryNode.h"
//A Node for a stack that holds either a char or int and a pointer to the next node

using namespace std;

BinaryNode::BinaryNode(char d){
  left = NULL;
  right = NULL;
  data.c = d;
  type = 1;
}
BinaryNode::BinaryNode(int d){
  left = NULL;
  right = NULL;
  data.i = d;
  type = 2;
}
//deconstructor, clear memory
BinaryNode::~BinaryNode(){

}
//returns a pointer to the next node
BinaryNode* BinaryNode::getLeft(){
  return left;
}
BinaryNode* BinaryNode::getRight(){
  return right;
}
//sets the pointer to the next node
void BinaryNode::setLeft(BinaryNode* n){
  left = n;
}
void BinaryNode::setRight(BinaryNode* n){
  right = n;
}
//returns a pointer to the Student class
int BinaryNode::getIntData(){
  return data.i;
}
char BinaryNode::getCharData(){
  if (type == 1){
    return data.c;
  }
  else return 0;
}
int BinaryNode::getType(){
  return type;
}
void BinaryNode::printData(){
  if (type == 1)
    cout << data.c << endl;
  else
    cout << data.i << endl;
}


