#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(Queue *q);
int isFull(Queue *q);
void Enqueue(Queue *q, int val);
int Dequeue(Queue *q);
void Display(Queue *q);


int main() {
    Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = new int[q.size];

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);

    Display(&q);

    cout << "Dequeued element: " << Dequeue(&q) << endl;
    Display(&q);

    return 0;
}

int isEmpty(Queue *q) {
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

int isFull(Queue *q) {
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}

void Enqueue(Queue *q, int val) {
    if (isFull(q)) {
        cout << "Queue is full!" << endl;
        return;
    } else {
        q->r++;
        q->arr[q->r] = val;
        cout << val << " enqueued successfully." << endl;
    }
}

int Dequeue(Queue *q) {
    int val = -1;
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
    } else {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

void Display(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = q->f + 1; i <= q->r; i++) {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}
