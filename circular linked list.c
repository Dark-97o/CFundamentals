# include<stdio.h>
# include<stdlib.h>

void create();
void display();
void insert_at_end();
void delete_at_beg();
void delete_at_end();

struct node {
	int data;
	struct node* next;
};

struct node *head = NULL;

void create() {
	struct node *ptr, *temp;
	ptr = (struct node *) malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &ptr->data);
	if (head == NULL) {
		head = ptr;
		ptr->next = head;
	} else {
		temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = head;
	}
}

void display() {
	if (head == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct node *ptr = head;
	printf("Linked list: ");
	do {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	} while (ptr != head);
	printf("\n");
}

void insert_at_end() {
	struct node *ptr, *temp = head;
	ptr = (struct node *) malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &ptr->data);
	if (head == NULL) {
		head = ptr;
		ptr->next = head;
	} else {
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = head;
	}
}

void delete_at_beg() {
	if (head == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct node *temp = head, *last = head;
	while (last->next != head) {
		last = last->next;
	}
	if (head == last) {
		free(head);
		head = NULL;
	} else {
		last->next = head->next;
		free(head);
		head = last->next;
	}
}

void delete_at_end() {
	if (head == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct node *temp = head, *prev = NULL;
	while (temp->next != head) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == head) {
		free(head);
		head = NULL;
	} else {
		prev->next = head;
		free(temp);
	}
}

int main() {
	int choice;
	while (1) {
		printf("Linked List Operations:\n");
		printf("1 for create\n2 for display\n3 for insert at end\n4 for delete at beginning\n5 for delete at end\n7 for exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insert_at_end();
			break;
		case 4:
			delete_at_beg();
			break;
		case 5:
			delete_at_end();
			break;
		case 7:
			exit(0);
		default:
			printf("Invalid choice!\n");
		}
	}
	return 0;
}

