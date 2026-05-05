#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, k;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if(head == NULL || head->next == NULL) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    int len = 1;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;
    int steps = len - k;

    struct Node* newTail = head;
    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}