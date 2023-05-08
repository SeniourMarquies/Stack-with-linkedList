#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// Remember Stack is Lifo

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node* temp = top;
    int popped_data = temp->data;
    top = top->next;
    free(temp);
    return popped_data;
}

void print_stack() {
    printf("Stack: ");
    if (top == NULL) {
        printf("empty");
    }
    else {
        Node* current = top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    printf("\n");
}

int main() {
    int choice, data;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("Popped data: %d\n", pop());
            break;
        case 3:
            print_stack();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}
