#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

void push_front(int x) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if(isEmpty()) {
        front = rear = 0;
    } else if(front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    dq[front] = x;
}

void push_back(int x) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if(isEmpty()) {
        front = rear = 0;
    } else if(rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

void pop_front() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else if(front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else if(rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void printDeque() {
    if(isEmpty()) return;

    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if(strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if(strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if(strcmp(op, "pop_back") == 0) {
            pop_back();
        }
    }

    printDeque();

    return 0;
}