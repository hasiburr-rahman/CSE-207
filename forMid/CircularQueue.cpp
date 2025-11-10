#include <bits/stdc++.h>
using namespace std;

struct CircularQueue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(CircularQueue *q);
int isFull(CircularQueue *q);
void Enqueue(CircularQueue *q, int val);
int Dequeue(CircularQueue *q);
void Display(CircularQueue *q);


int main() {
    CircularQueue q;
    q.size = 8;
    q.f = q.r = 0;
    q.arr = new int[q.size];

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);

    Display(&q);

    cout << "Dequeued element: " << Dequeue(&q) << endl;
    cout << "Dequeued element: " << Dequeue(&q) << endl;
    cout << "Dequeued element: " << Dequeue(&q) << endl;
    cout << "Dequeued element: " << Dequeue(&q) << endl;
    Display(&q);

    return 0;
}

int isEmpty(CircularQueue *q) {
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

int isFull(CircularQueue *q) {
    if ((q->r+1)%q->size == q->f)
        return 1;
    else
        return 0;
}

void Enqueue(CircularQueue *q, int val) {
    if (isFull(q)) {
        cout << "CircularQueue is full!" << endl;
        return;
    } else {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        cout << val << " enqueued successfully." << endl;
    }
}

int Dequeue(CircularQueue *q) {
    int val = -1;
    if (isEmpty(q)) {
        cout << "CircularQueue is empty!" << endl;
    } else {
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

void Display(CircularQueue *q) {
    if (isEmpty(q)) {
        cout << "CircularQueue is empty!" << endl;
        return;
    }
    cout << "CircularQueue elements: ";
    for (int i = q->f + 1; i <= q->r; i++) {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}
