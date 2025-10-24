#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    int* arr;
};

bool isEmpty(Stack* ptr);
bool isFull(Stack* ptr);
void push(Stack *ptr, int val);
int pop(Stack *ptr);

int main() {
    Stack* s = new Stack;

    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    push(s, 46);
    push(s, 56);
    push(s, 66);
    cout << "Popped : " << pop(s) << "\n";

    if (isEmpty(s)) {
        cout << "The stack is empty" << endl;
    } else {
        cout << "The stack is not empty" << endl;
    }

    if (isFull(s)) {
        cout << "The stack is full" << endl;
    } else {
        cout << "The stack is not full" << endl;
    }

    delete[] s->arr;
    delete s;

    return 0;
}

bool isEmpty(Stack* ptr) {
    return (ptr->top == -1);
}

bool isFull(Stack* ptr) {
    return (ptr->top == ptr->size - 1);
}

void push(Stack *ptr, int val){
    if(isFull(ptr)){
        cout << "Stack OverFlow !!! " << val << endl;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(Stack *ptr) {
    if (isEmpty(ptr)) {
        cout << "Stack UnderFlow !!!" << endl;
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

