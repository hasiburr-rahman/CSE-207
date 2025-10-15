#include<bits/stdc++.h>
using namespace std;

struct node {
int data;
node* link;
};

node* head = NULL;
node* tail = NULL;

void insert_at_end(int value);
void insert_at_beginning(int a);
void delete_from_end();
void display_forward();
//void display_backward(node* temp);
node* search(int s);
void todelete();

int main() {

  int n, value;
  cout << "Enter how many values you wanna input : ";
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> value;
    insert_at_end(value);
  }
  display_forward();

  int a;
  cout << "enter the value to adding at the beginning \n";
  cin >> a;
  insert_at_beginning(a);
  display_forward();

  cout << "\n";
  cout << "-----------\n";
  cout << "\n";
  //deleting part.
  delete_from_end();

  //display part.
  display_forward();
  //cout << "display backward\n";
  //display_backward(head);

  //for searching any elements;
  cout << "\nEnter any element to find out - ";
  int s;
  cin >> s;
  node* found = search(s);
  if(found){
    cout << s << " - founded";
  } else {
  cout << "not founded";
  }

  //to delete the node.
  todelete();
  display_forward();

  return 0;
}

void insert_at_end(int value){
  node* newNode = new node;
  newNode->data = value;
  newNode->link = NULL;

  if(head == NULL){
      head = tail = newNode;
      //basically the memory is empty;
    } else {
    tail->link = newNode;
    tail = newNode;
    }

}

void insert_at_beginning(int a){
  if(head == NULL){
    head = tail;
    return;
  }

  node* newNode = new node;
  newNode->data = a; // "a" is inserted value.
  newNode->link = head;

  head = newNode;

}

void delete_from_end(){
  if(head == NULL){
    head = tail;
    return;
  }

  node* temp = head;
  while(temp->link != NULL){
    temp = temp->link;
  }
  delete temp;
  temp = NULL;
}

void display_forward(){
  node* temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->link;
  }
}

node* search(int s){
  node* temp = head;
  while(temp->link != NULL){
    if(temp->data == s){
        return temp;
  }

  return NULL;
}
}
void todelete(){
  if(head == NULL){
    head = tail;
    return;
  }

  node* temp = head;
  while(temp != NULL){
    temp = temp->link;
  }

  delete temp;
  temp = NULL;
}

/*void display_backward(node* temp){
  display_backward(temp->link);
  cout << temp->data << " ";
}*/




