#include "Node.h"
//The header for a stack class used for the shunting yard algorithim
using namespace std;

class Stack{
 public:
  Stack();
  Node* pop();
  Node* peek();
  void push(Node* newNode);
  ~Stack();
 private:
  Node* head;
};
