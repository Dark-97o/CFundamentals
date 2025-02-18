#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

void Create();
void Display();
void Insert_at_beg();
void Insert_at_end();
void Insert_at_pos();
void Delete_at_beg();
void Delete_at_end();
void Delete_at_pos();

int main() {
    int choice;
    while (1) {
        printf("1 for Create \n2 for Display \n3 for Insert at beg \n4 for Insert at end \n5 for Insert at pos \n6 for Delete at beg \n7 for Delete at end \n8 for Delete at pos \n9 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Create(); break;
            case 2: Display(); break;
            case 3: Insert_at_beg(); break;
            case 4: Insert_at_end(); break;
            case 5: Insert_at_pos(); break;
            case 6: Delete_at_beg(); break;
            case 7: Delete_at_end(); break;
            case 8: Delete_at_pos(); break;
            case 9: exit(0);
            default: printf("Invalid Input\n");
        }
    }
}

void Create() {
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &ptr->data);
    ptr->prev = ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void Display() {
    struct node *ptr = head;
    printf("Linked list: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void Insert_at_beg() {
    struct node ptr = (struct node)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &ptr->data);
    ptr->prev = ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void Insert_at_end() {
    struct node ptr = (struct node)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Enter node data: ");
    scanf("%d", &ptr->data);
    ptr->prev = ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void Insert_at_pos() {
    int pos, i;
    struct node *ptr, *temp = head;
    printf("Enter position: ");
    scanf("%d", &pos);
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &ptr->data);
    ptr->prev = ptr->next = NULL;

    if (pos == 0) { // Insert at beginning if position is 0
        Insert_at_beg();
        return;
    }

    for (i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
    } else {
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
    }
}

void Delete_at_beg() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(ptr);
}

void Delete_at_end() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *ptr = head;
    if (ptr->next == NULL) {
        head = NULL;
        free(ptr);
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
}

void Delete_at_pos() {
    int pos, i;
    struct node *ptr = head;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if (pos == 0) { // Delete at beginning if position is 0
        Delete_at_beg();
        return;
    }

    for (i = 0; i < pos && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position out of bounds\n");
    } else {
        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }
        if (ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        }
        free(ptr);
    }
}
