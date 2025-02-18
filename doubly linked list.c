#include <stdio.h>
#include <stdlib.h>
struct node {
	int data ;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
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
void create(){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter node data:\n");
    scanf("%d",&ptr->data);
    ptr->prev=ptr->next=NULL;
    if(head==NULL){
        head=temp=ptr;
    }
    else{
        temp->next=ptr;
        ptr->prev=temp;
        temp=ptr;
    }
}
void display(){
    struct node *ptr=head;
    if(head==NULL){
        printf("Linked List is Empty!!");
    }
    else{
        printf("Linked List is :\n");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
void insert_at_beg(){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter node data:\n");
    scanf("%d",&ptr->data);
    ptr->prev=ptr->next=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        ptr->prev=NULL;
        ptr->next=head;
        head=ptr;
    }
}


void insert_at_end(){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter node data:\n");
    scanf("%d",&ptr->data);
    ptr->prev=ptr->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
}
void insert_at_pos(){
    struct node *ptr,*temp;
    int pos,i;
    printf("Enter the position:\n");
    scanf("%d",&pos);
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter node data:\n");
    scanf("%d",&ptr->data);
    ptr->prev=ptr->next=NULL;
    temp=head;
    for(i=0;i<pos;i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next->prev=ptr;
    temp->next=ptr;
}
