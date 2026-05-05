#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, count = 0;
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

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    printf("\nCount: %d", count);

    return 0;
}