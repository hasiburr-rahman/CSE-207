#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int isEmpty(Node* top);
int isFull(Node* top);
struct Node* Push(Node* top, int val);
void display(Node* top);
int Pop(Node* &top);
int Peek(Node* &top, int pos);



int main(){
    Node* top = NULL;

    int val = 5;
    top = Push(top, val);
    top = Push(top, 6);
    top = Push(top, 7);
    top = Push(top, 8);

    int element = Pop(top);
    cout << "Poppped element is - " << element << endl;


    display(top);

    cout << "Enter a postion ofr peek" << endl;
    int pos = 3;
    int pek = Peek(top, pos);
    return 0;
}



int isEmpty(Node* top){
    if(top == NULL){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Node* top){
    Node* p = new Node;
    if(p == NULL){
        return 1;
    } else {
        return 0;
    }
}

struct Node* Push(Node* top, int val){
    if(isFull(top)){
        cout << "StackOverflow\n";
    } else {
        Node* n = new Node;
        n->data = val;
        n->next = top;
        top = n;
        return top;
    }
}

void display(Node* top){
    int count = 1;
    while(top != NULL){
        cout << "Element " << count << " is " << top->data << endl;
        count++;
        top = top->next;
    }
}

int Pop(Node* &top){
    if(isFull(top)){
        cout << "The Stack is overflow\n";
        return -1;
    } else {
        Node* n = top;
        top = top->next;
        int x = n->data;
        delete n;
        return x; 
    }
}

int Peek(Node* &top, int pos){
    if(isEmpty(top)){
        cout << "The stack is empty\n";
        return -1;
    }

    Node* temp = top;
    int count = 1;

    while(temp != NULL && count < pos){
        temp = temp-> next;
        count++;
    }

    if (temp != NULL)
        return temp->data;
    else {
        cout << "Invalid position! Stack has fewer elements.\n";
        return -1;
    }
}