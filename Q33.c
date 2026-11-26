
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp, *prev;
    int n, count = 0, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Enter N: ");
    scanf("%d", &n);

    count = 0;
    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (n <= 0 || n > count) {
        printf("Invalid N");
        return 0;
    }

    if (n == count) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        temp = head;

        for (i = 1; i < count - n; i++)
            temp = temp->next;

        prev = temp->next;
        temp->next = prev->next;
        free(prev);
    }

    printf("Updated Linked List: ");

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
