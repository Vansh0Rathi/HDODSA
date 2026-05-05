#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
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

    if(temp != NULL) {
        temp->next = head; // make circular
    }

    temp = head;
    for(int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}