#include "Stack.h"
#include "Node.h"
//A stack class that has the basic stack commands to be used for a shunting yard algorithim
using namespace std;

Stack::Stack(){
  head = NULL;
}
Stack::~Stack(){
  Node* nextNode = head;
  while (head){
    nextNode = head->getNext();
    delete head;
    head = nextNode;
  }
}
Node* Stack::pop(){
  Node* toReturn = head;
  head = toReturn->getNext();
  return toReturn;
}
Node* Stack::peek(){
  return head;
}
void Stack::push(Node* newNode){
  newNode->setNext(head);
  head = newNode;
}
