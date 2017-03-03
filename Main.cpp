//Expression Tree converts infix to postfix
//Josh Howell, Feb 2017

#include "Node.h"
#include "Stack.h"
#include "BinaryNode.h"
#include <cstdlib>
#include <cstring>


using namespace std;

bool isOperator(char c);
int precedence(char c);
Stack* shuntingYard(char* input);
BinaryNode* makeTree(Stack* stack);
void print (BinaryNode* node, int indent = 0);



int main(){
  char input[50];
  cin.get(input, 50); //get the input and start the algorithim
  Stack* stack = shuntingYard(input);
  BinaryNode* head = makeTree(stack);
  print(head);
}

void print(BinaryNode* node, int indent){
  
  if (node->getLeft())
    print(node->getLeft(),indent+1);
  for(int j = 0; j <= indent; j++){
    cout << "   ";
  }
  node->printData();
  if (node->getRight()) 
    print(node->getRight(),indent+1);
}



BinaryNode* makeTree(Stack* stack){
  BinaryNode* binaryNode;
  if (stack->peek()->getType() == 1){
    binaryNode = new BinaryNode(stack->pop()->getCharData());
    binaryNode->setLeft(makeTree(stack));
    binaryNode->setRight(makeTree(stack));
  }
  else{
    binaryNode = new BinaryNode(stack->pop()->getIntData());
  
  }
  return binaryNode;
}




Stack* shuntingYard(char* input){ // the actuall shunting yard thing
  int i = 0;
  Stack* operatorStack = new Stack(); 
  Stack* outputStack = new Stack();
  while (input[i]){ //run through the string and pick it apart
    if(isdigit(input[i])){ // if its a number, put it on the output stack
      outputStack->push(new Node(atoi(&input[i])));
      while(isdigit(input[i+1])){ //move it off the number
	i++;
      }
    }
    else if (isOperator(input[i])){ //if its a * / + =
      while(operatorStack->peek()){ 
	if (precedence(input[i]) >= precedence(operatorStack->peek()->getCharData())){
	    break;
	  }
	outputStack->push(operatorStack->pop()); //add the current operator to the operatorStack
	  }
      operatorStack->push(new Node(input[i]));
      }
    else if (input[i] == '('){ //simply add the ( to the operator stack
      operatorStack->push(new Node(input[i]));
    }
    else if (input[i] == ')'){ //if its a ) add all the operators in the stack to the output
      while(operatorStack->peek()->getCharData() != '('){ //until theres a (
	outputStack->push(operatorStack->pop());
      }
      delete operatorStack->pop();
    }
    i++;
  }
  while(operatorStack->peek()){ //put the operator stack on the output stack
    outputStack->push(operatorStack->pop());
  }
  delete operatorStack;
  return outputStack;
}
bool isOperator(char c){
  if (c == '-' ||
      c == '+' ||
      c == '^' ||
      c == '*' ||
      c == '/'){
    return true;
  }
  return false;
}
int precedence(char c){ // gives things piority pemdos and all that
  int precedence[256];
  precedence['-'] = 1;
  precedence['+'] = 1;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['^'] = 3;
  precedence['('] = -1;
  return precedence[c];
}
