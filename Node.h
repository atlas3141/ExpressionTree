#ifndef NODE_H
#define NODE_H
// the header for the node class that the stack class uses
#include <iostream>

using namespace std;


class Node{
 public:
  Node* getNext();
  Node(char d);
  Node(int d);
  ~Node();
  int getIntData();
  char getCharData();
  int getType();
  void setNext(Node* n);
 private:
  Node* next;
  union data_t{
    char c;
    int i;
  } data;
  int type;
};

#endif
