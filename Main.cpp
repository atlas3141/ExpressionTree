//Expression Tree converts infix to postfix
//Josh Howell, Feb 2017

#include "Node.h"
#include "Stack.h"
#include "BinaryNode.h"
#include <cstdlib>
#include <cstring>


using namespace std;

bool isOperator(char c); //Checks if its a +-/*^
int precedence(char c); //Pemdos 
Stack* shuntingYard(char* input); //converts an equation string into a stack
BinaryNode* makeTree(Stack* stack); //Converts an equation stack 
void print (BinaryNode* node, int indent = 0); //prints the stack out as a tree
void printPostfix (BinaryNode* node);//prints the tree out as a postfix equation
void printPrefix (BinaryNode* node);//prints the tree out as a prefix equation
void printInfix(BinaryNode* nodes);;//prints the tree out as an infix without ()


int main(){
  char input[50];
  cin.get(input, 50); //get the input and start the algorithim
  Stack* stack = shuntingYard(input); //convets the input into a stack
  BinaryNode* head = makeTree(stack);// convets the stack into a tree
 
  //print everything out 
  cout << "Tree:" << endl;
  print(head);
  cout << "\nPostfix:  " << endl;
  printPostfix(head);
  cout << endl << "\nPrefix:" << endl;
  printPrefix(head);
  cout << endl << "\nInfix:" << endl;
  printInfix(head);
  cout << endl;
}
//print tree
void print(BinaryNode* node, int indent){ 
  
  if (node->getLeft())
    print(node->getLeft(),indent+1);
  for(int j = 0; j <= indent; j++){
    cout << "   ";
  }
  node->printData();
  cout << endl;
  if (node->getRight()) 
    print(node->getRight(),indent+1);
}
//print the equation types
void printPostfix (BinaryNode* node){
  if (node->getType() == 1){
    printPostfix(node->getLeft());
    printPostfix(node->getRight());
  }
  node->printData();
}
void printPrefix (BinaryNode* node){
  node->printData();
  if (node->getType() == 1){
    printPrefix(node->getLeft());
    printPrefix(node->getRight());
  }
}
void printInfix(BinaryNode* node){
  if (node->getType() == 1){
    printInfix(node->getLeft());
    node->printData();
    printInfix(node->getRight());
  }
  else{
    node->printData();
  }
  
}
//title
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

//Turns input into a stack
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
