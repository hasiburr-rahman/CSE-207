#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void  CircularLinkedlist(Node* &head, int val);
void display(Node* &head);

int main(){
    int size, values;
    cout << "Enter how many values you wannna input \n";
    cin >> size;

    Node* head = NULL;

    for(int i =0; i<size; i++){
        cin >> values;
        CircularLinkedlist(head, values);
    }

    display(head);

    return 0;

}

void  CircularLinkedlist(Node* &head, int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

}

void display(Node* &head){
    if(head == NULL){
        cout << "The list is empty\n";
    }

    Node* temp = head;
    cout << "Circular LinkedList: - ";
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << endl;

}