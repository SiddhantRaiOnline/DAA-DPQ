#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int hasCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main(void) {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    Node *head = NULL;
    Node *tail = NULL;
    Node *cycleNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;

        if (i == 0) {
            cycleNode = newNode;
        }
    }

    int cyclePosition;
    printf("Enter cycle position (0-based, or -1 for no cycle): ");
    scanf("%d", &cyclePosition);

    if (cyclePosition >= 0 && cyclePosition < n) {
        Node *current = head;
        for (int i = 0; i < cyclePosition; i++) {
            current = current->next;
        }
        tail->next = current;
    }

    if (hasCycle(head)) {
        printf("Cycle detected.\n");
        tail->next = NULL;
    } else {
        printf("No cycle detected.\n");
    }

    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
