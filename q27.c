#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

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
    return head;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* t1 = list1;

    while(t1 != NULL) {
        struct Node* t2 = list2;

        while(t2 != NULL) {
            if(t1->data == t2->data) {
                printf("%d", t1->data);
                return 0;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    printf("No Intersection");

    return 0;
}