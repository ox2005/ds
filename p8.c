#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char ssn[10];
	char name[20];
	char dept[20];
	char designation[20];
	int sal;
	char phno[20];
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*tail=NULL,*temp,*newnode;

void dataentry(){
	printf("Enter ssn: ");
	scanf("%s",newnode->ssn);
	printf("Enter name: ");
	scanf("%s",newnode->name);
	printf("Enter department: ");
	scanf("%s",newnode->dept);
	printf("Enter designation: ");
	scanf("%s",newnode->designation);
	printf("Enter salary: ");
	scanf("%d",&newnode->sal);
	printf("Enter phone number: ");
	scanf("%s",newnode->phno);
}

void create(){
	newnode = (struct node*)malloc(sizeof(struct node));
	dataentry();
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=tail=newnode;
	}else{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
}
void insertatbeg(){
	newnode = (struct node*)malloc(sizeof(struct node));
	dataentry();
	head->prev=newnode;
	newnode->next=head;
	newnode->prev=NULL;
	head=newnode;
}
void insertatend(){
	newnode = (struct node*)malloc(sizeof(struct node));
	dataentry();
	tail->next=newnode;
	newnode->prev=tail;
	newnode->next=NULL;
	tail=newnode;
}
void deleteatend(){
	if(head==NULL){
		printf("The DLL is empty \n");
		return;
	}
	temp=tail;
	tail=tail->prev;
	tail->next=NULL;
	free(temp);
}
void deleteatbeg(){
	if(head==NULL){
		printf("The DLL is empty \n");
		return;
	}
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}
void display(){
	if(head==NULL){
		printf("List is empty \n");
		return;
	}
	printf("-------MENU------ \n");
	temp=head;
	int count=0;
	while(temp!=NULL){
		printf("|SSN: %s||Name: %s||Dept: %s||Designation: %s||Salary: %d||PhoneNo: %s \n",temp->ssn,temp->name,temp->dept,temp->designation,temp->sal,temp->phno); 
		temp=temp->next;
		count++;
		}
	printf("The number of nodes are: %d \n",count);
}

void deqque(){
	int ch;
	do{
                printf("Demo Double Ended Queue Operation \n");
                printf("1.Display status \n");
                printf("2.InsertQueueRear \n");
                printf("3.InsertQueueFront \n");
                printf("4.DeleteQueueRear \n");
                printf("5.DeleteQueueFront \n");
                printf("6.Exit \n");
                printf("Enter Your Choice: ");
                scanf("%d",&ch);

	switch(ch){
                        case 1:
                                display();
                                break;
                        case 2:
                                insertatbeg();
                                break;
                        case 3:
                                insertatend();
                                break;
                        case 4:
                                deleteatend();
                                break;
                        case 5:
                                deleteatbeg();
                                break;
                        case 6:
                                printf("Code Exited \n");
                                break;

                        default:
                                printf("Invalid Choice \n");
                }
        }while(ch!=6);

}
void main(){
	
	int ch;
	do{
		printf("1.Create a doubly linked list of employee data \n");
		printf("2.Display status \n");
		printf("3.Insert_at_end \n");
		printf("4.Insert_at_beg \n");
		printf("5.Delete_at_end \n");
		printf("6.Delete_at_beg \n");
		printf("7.Demo Double ended Queue \n");
		printf("8.Exit \n");
		printf("Enter Your Choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insertatend();
				break;
			case 4:
				insertatbeg();
				break;
			case 5:
				deleteatend();
				break;
			case 6:
				deleteatbeg();
				break;
			case 7:
				deqque();
				break;
			case 8:
				printf("Code exited \n");
				break;

			default:
				printf("Invalid Choice \n");
		}
	}while(ch!=8);
}


