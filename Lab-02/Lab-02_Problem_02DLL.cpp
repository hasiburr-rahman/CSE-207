#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* head = NULL;
node* tail = NULL;

void insert_at_end(int data);
void insert_at_beginning(int data);
void delete_from_end();
void delete_from_beginning();
void display_forward();
void display_backward();
node* search(int data);
void delete_data(int data);

int main() {
    int n, val;
    cout << "Enter how many values you want to input: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert_at_end(val);
    }

    display_forward();

    cout << "\nInsert at beginning (value): ";
    cin >> val;
    insert_at_beginning(val);
    display_forward();

    cout << "\nDelete from end:\n";
    delete_from_end();
    display_forward();

    cout << "\nDelete from beginning:\n";
    delete_from_beginning();
    display_forward();

    cout << "\nEnter value to search: ";
    cin >> val;
    node* found = search(val);
    if (found) cout << "Found " << val << " in list.\n";
    else cout << "Not found.\n";

    cout << "\nEnter value to delete: ";
    cin >> val;
    delete_data(val);
    display_forward();

    cout << "\nDisplay backward: ";
    display_backward();

    node* temp = head;
    while (temp != NULL) {
        node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}

void insert_at_end(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insert_at_beginning(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

void delete_from_end() {
    if (tail == NULL) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

void delete_from_beginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

void display_forward() {
    node* temp = head;
    cout << "LinkedList (forward): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void display_backward() {
    node* temp = tail;
    cout << "LinkedList (backward): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

node* search(int data) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void delete_data(int data) {
    node* temp = search(data);
    if (temp == NULL) {
        cout << "Data not found!\n";
        return;
    }

    if (temp == head)
        delete_from_beginning();
    else if (temp == tail)
        delete_from_end();
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}
