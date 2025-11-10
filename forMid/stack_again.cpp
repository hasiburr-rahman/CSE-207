#include <bits/stdc++.h>
using namespace std;

//implementaion stack using array. 
//--> Fixed size array; 
//--> Top Element

struct Stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(Stack *ptr);
int isFull(Stack *ptr);
void Push(Stack *ptr, int value);
int Pop(Stack* ptr);
int Peek(Stack* ptr, int i);
int StackTop(Stack* ptr);
void StackBottom(Stack* ptr);

int main() {
    Stack* s = new Stack; // allocate memory for Stack

    s->size = 5;
    s->top = -1;
    s->arr = new int[s->size];

    cout << "Stack created successfully!" << endl;

    if(isEmpty(s)){
      cout << "The Stack is empty\n";
    } else {
      cout << "The Stack is not empty\n";
    }

    if(isFull(s)){
      cout << "The Stack is Full --> Suiiiiii\n";
    } else {
      cout << "The Stack is not full\n";
    }

    Push(s, 10);
    Push(s, 15);
    Push(s, 20);

    int sTop = StackTop(s);
    cout << "The top element of the stack is - " << sTop << endl;
    StackBottom(s);

    for(int j=1; j <= s->top+1; j++){
      cout << "The value at postion " << j << " is "<< Peek(s, j) << endl;
    }
   

    int val = Pop(s);
    cout << val << " popeed from the stack\n";
    int val2 = Pop(s);
    cout << val2 << " popeed from the stack\n";
    int val3 = Pop(s);
    cout << val3 << " popeed from the stack\n";
    int val4 = Pop(s);
    cout << val4 << " popeed from the stack\n";

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

void Push(Stack *ptr, int value){
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

  int val = ptr->arr[ptr->top];
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
