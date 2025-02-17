#include<stdio.h>
#include<stdlib.h>
void Create();
void Display();
void Insert_at_beg();
void Insert_at_end();
void Insert_at_pos();
void Delete_at_beg();
void Delete_at_end();
void Delete_at_pos();
struct node{
  int data;
  struct node*next;
    };
struct node *head =0;

int main(){
  int choice;
  while(1){
    printf("\nLinked list operation:");
    printf("\n1 for create a node \n2 for display the linked list \n3 for Insert a node at begining \n4 Insert a node at end \n5 for Insert a node at position \n6 for delete a node at beginning \n7 for delete a node at end \n8 for delete a node at position \n9 for exit \n");
    printf("\nenter your choice:\n");
	scanf("%d",&choice);
    
    switch(choice){
      case 1:Create();
      break;
      case 2:Display();
      break;
      case 3:Insert_at_beg();
      break;
      case 4:Insert_at_end();
      break;
      case 5:Insert_at_pos();
      break;
      case 6:Delete_at_beg();
      break;
      case 7:Delete_at_end();
      break;
      case 8:Delete_at_pos();
      break;
      case 9:exit(0);
      break;  
      printf("invalid input\n:");
    }
  }
  return 0;
}
void Create(){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the node data\n");
scanf("%d",&temp->data);
temp->next = 0;
if(head==0){
  head=temp;
}
else{
  struct node*ptr;
  ptr=head;
  while(ptr->next!=0){
    ptr=ptr->next;
  }
  ptr->next=temp;
    }
}
void Insert_at_beg(){
  struct node*temp;
  temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the node data\n");
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
}
void Display(){
     if(head==0)
     printf("Linked list is empty");
     else{
       printf("Linked list is:\n");
       struct node*ptr=head;
       while(ptr!=0){
         printf("%d\t",ptr->data);
         ptr=ptr->next;
    }
    printf("\n");
   }

}
void Insert_at_end(){
    struct node *temp;
    temp = (struct node*) malloc (sizeof(struct node));
    printf("Enter data of the data: ");
    scanf("%d" , &temp -> data);

    temp -> next = 0;
    struct node * ptr = head;

    while(ptr -> next != 0){
        ptr = ptr -> next;
    }
    ptr -> next = temp;
}
void Insert_at_pos(){
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n enter data of the node:");
	scanf("%d",&temp->data);
	temp->next=0;
	struct node*ptr=head;
	struct node*prevnode;
	int pos,i;
	printf("enter position\n");
	scanf("%d",&pos);
	for(i=0;i<pos;i++){
		prevnode=ptr;
		ptr=ptr->next;
	}
	temp->next=ptr;
	prevnode->next=temp;
}
void Delete_at_beg(){
	if(head==0){
		printf("linked list is empty");
		return;
	}
	else{
		struct node*ptr=head;
		head=head->next;
		free(ptr);
	}
}
void Delete_at_end(){
	if(head==0){
		printf("linked list is empty");
	}
	else if(head->next==0){
		struct node*ptr=head;
		head=ptr->next;
		free(ptr);
	}
	else{
		struct node *ptr=head, *prev_ptr = 0;
		while(ptr->next!=0){
			prev_ptr=ptr;
			ptr=ptr->next;
		}
	prev_ptr->next=0;
	free(ptr);
    }
}
void Delete_at_pos(){
	int pos,i;
	printf("enter position\n");
	scanf("%d",&pos);
	struct node*ptr=head;
	if(head==0){
		printf("linked list is empty");
	}
	else if(pos==0){
		head=ptr->next;
		head=ptr->next;
		free (ptr);
	}
	else{
	struct node *prev_ptr;
	for(i=0;i<pos;i++){
		prev_ptr=ptr;
		ptr=ptr->next;
	}
	prev_ptr->next=ptr->next;
	free(ptr);
	}
}
