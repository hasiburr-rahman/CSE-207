#include<bits/stdc++.h>
using namespace std;

struct node {
int data;
node* link;
};

node* head = NULL;
node* tail = NULL;

int main() {

  int n;
  cout << "Enter how many values you want to input : ";
  cin >> n;

  for(int i=0; i<n; i++){
    node* newNode = new node;
    cin >> newNode->data;
    newNode->link = NULL;

    if(head == NULL){
      head = tail = newNode;
      //basically the memory is empty;
    } else {
    tail->link = newNode;
    tail = newNode;
    }
  }

  cout << "Linked List : ";

  node* temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->link;
  }

  // to free the memory ->

  temp = head;
  while(temp != head){
    node* toDelete = temp;
    temp = temp->link;
    delete toDelete;
  }

  return 0;

}
