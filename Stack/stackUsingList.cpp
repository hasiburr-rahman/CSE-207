#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node* top = NULL;

bool isEmpty(node* tp);
bool isFull(node* tp);
node* push(node* tp, int val);
int pop(node* tp);
void display(node* tp);

int main(){
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        top = push(top, val);
    }

    cout << "\nStack elements are: ";
    display(top);

    int element = pop(top);
    cout << "\nPopped element: " << element << endl;

    cout << "\nStack after popping: ";
    display(top);

    return 0;
}

bool isEmpty(node* tp){
    return (tp == NULL);
}

bool isFull(node* tp){
    node* p = new(nothrow) node;
    if(p == NULL){
        return 1;
    } else {
        delete p;
        return 0;
    }
}

node* push(node* tp, int val){
    node* n = new node;
    n->data = val;
    n->next = tp;
    tp = n;
    return tp;
}

int pop(node* tp){
    if(isEmpty(tp)){
        return -1;
    }
    node* n = tp;
    tp = tp->next;
    int x = n->data;
    delete n;
    top = tp;
    return x;
}

void display(node* tp){
    node* temp = tp;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
