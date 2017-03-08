#ifndef BINARYNODE_H
#define BINARYNODE_H
// the header for the node class that the stack class uses
#include <iostream>

using namespace std;


class BinaryNode{
 public:
  BinaryNode* getLeft();
  BinaryNode* getRight();
  BinaryNode(char d);
  BinaryNode(int d);
  ~BinaryNode();
  int getIntData();
  char getCharData();
  int getType();
  void setLeft(BinaryNode* n);
  void setRight(BinaryNode* n);
  void printData();
 private:
  BinaryNode* right;
  BinaryNode* left; //a magical type that saves like a byte of data
  union data_t{
    char c;
    int i;
  } data;
  int type;
};

#endif
