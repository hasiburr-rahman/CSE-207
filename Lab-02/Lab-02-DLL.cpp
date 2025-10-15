#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* head = NULL;
node* tail = NULL;

int main () {
    int n;
    cout << "Enter how many values you wanna input : ";
    cin >> n;

    for(int i=0; i<n; i++){
        node* newNode = new node;
        cin >> newNode->data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if( head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "Forward way - ";
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
    cout << "Backward way - ";
    temp = tail;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }

    temp = head;
    while(temp != NULL){
        node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}