#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(Stack *ptr);
int isFull(Stack *ptr);
void Push(Stack *ptr, char value);
// int Pop(Stack* ptr);
// int Peek(Stack* ptr, int i);
// int StackTop(Stack* ptr);
// void StackBottom(Stack* ptr);
int parenthesisMatch(char *exp);

int main() {

  char* exp = "8*(9)";

    if(parenthesisMatch(exp)){
      cout << "The parenthesis is matching\n";
    } else {
      cout << "The parenthesis is not matching\n";
    }

    // if(isFull(s)){
    //   cout << "The Stack is Full --> Suiiiiii\n";
    // } else {
    //   cout << "The Stack is not full\n";
    // }

    return 0;
}

int isEmpty(Stack* ptr){
  if(ptr->top == -1){
    return 1;
  } else {
    return 0;
  }
}

int isFull(Stack *ptr){
  if(ptr->top == ptr->size-1){
    return 1;
  } else {
    return 0;
  }
}

void Push(Stack *ptr, char value){
  if(isFull(ptr)){
    cout << "Stack overflow\n";
    return;
  }

  ptr->top++;
  ptr->arr[ptr->top] = value;
  cout << value << " pushed successfully\n";
}

int Pop(Stack* ptr){
  if(isEmpty(ptr)){
    cout << "Stack underflow\n";
    return -1;
  }

  char val = ptr->arr[ptr->top];
  ptr->top = ptr->top-1;
  return val;
}

int Peek(Stack* ptr, int i){
  int arrayInd = ptr->top-i+1;
  if(ptr->top-i+1 < 0){
    cout << "Not a valid postion fot this stack\n";
    return -1;
  }

  return ptr->arr[arrayInd];
}

int StackTop(Stack* ptr){
  return ptr->arr[ptr->top];
}

void StackBottom(Stack* ptr){
  if(isEmpty(ptr)){
    cout << "No bottom value, stack is empty\n";
    return;
  }

  cout << "Bottom element - " << ptr->arr[0] << endl;
}

int parenthesisMatch(char *exp){
  Stack* sp;
  sp->size = 100;
  sp->top = -1;
  sp->arr = new char[sp->size]; 
  for(int i=0; exp[i] != '\0'; i++){
    if(exp[i] == '('){
      Push(sp, exp[i]);
    } else if(exp[i] == ')'){
      if(isEmpty(sp)){
        return 0;
      } else {
        Pop(sp);
      }
    }
  }

  if(isEmpty(sp)){
    return 1;
  } else {
    return 0;
  }
}
