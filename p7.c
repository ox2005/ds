#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//singly linked list
//this structure node will be storing the student data
struct node{
	char usn[15];
	char name[20];
	char programme[10];
	int sem;
	int phno;
	struct node* next;
};
struct node *newnode,*head=NULL,*prevnode,*temp;


//This function will take data entry
void data_entry(){
	printf("Enter the usn: ");
	scanf("%s",newnode->usn);
	printf("Enter the name: ");
	scanf("%s",newnode->name);
	printf("Enter the programme: ");
	scanf("%s",newnode->programme);
	printf("Enter the sem: ");
	scanf("%d",&newnode->sem);
	printf("Enter the phno: ");
	scanf("%d",&newnode->phno);
}

//This function will create list of student data
void create_list(int n){
	for(int i=0;i<n;i++){
	newnode = (struct node*)malloc(sizeof(struct node));
	data_entry();
	newnode->next = head;
	head = newnode;
	}
}

void insert_front(){
	newnode = (struct node*)malloc(sizeof(struct node));
	data_entry();
	newnode->next = head;
	head = newnode;
	}


void insert_end(){
	newnode = (struct node*)malloc(sizeof(struct node));
	data_entry();
	newnode->next = NULL;
	temp = head;
	if(head==NULL){
		head = newnode;
		return;
	}
	
	while(temp->next!=NULL){
		temp = temp->next;
	}
	
	temp->next = newnode;
}
void delete_front(){
	if(head==NULL){
		printf("list is empty \n");
		return;
	}
	temp = head;
	head = head->next;
	printf("The deleted student usn is %s \n",temp->usn);
	free(temp);
}

void delete_end(){
	if(head==NULL){
		printf("list is empty \n");
		return;
	}
	temp = head;
	prevnode = NULL;
	while(temp->next!=NULL){
		prevnode = temp;
		temp=temp->next;
	}
	printf("The deleted student usn is %s \n",temp->usn);
	if(prevnode==NULL){
	head = NULL;
	}else{
	prevnode->next = NULL;
	}
	free(temp);
}

int count_node(){
	int count = 0;
	temp = head;
	while(temp!=NULL){
		temp = temp->next;
		count++;
	}
	return count;
}
void display(){
	if(head==NULL){
		printf("The list is empty \n");
		return;
	}
	temp = head;
	printf("The elements of lists are: \n");
	while(temp!=NULL){
		printf("USN: %s || Name: %s || Programme: %s || Sem: %d || phno: %d \n",temp->usn,temp->name,temp->programme,temp->sem,temp->phno);
		temp = temp->next;
	}
}

int main(){
	int ch,x;

	do{
		printf("---Menu---\n");
		printf("1.Create a SLL of student data \n");
		printf("2.Display \n");
		printf("3.Insert at front \n");
		printf("4.Insert at end \n");
		printf("5.Delete at front \n");
		printf("6.Delete at end \n");
		printf("7.Exit \n");
		printf("Enter Your Choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("Enter how many list of students you want to create: ");
				scanf("%d",&x);
				create_list(x);
				break;
			case 2:
				display();
				printf("The number of nodes are: %d \n",count_node());
				break;
			case 3:
				insert_front();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				delete_front();
				break;
			case 6:
				delete_end();
				break;
			case 7:
				printf("Code exited \n");
				break;
			default:
				printf("Invalid input \n");
				break;
		}
	}while(ch!=7);
}






