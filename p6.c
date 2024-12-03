#include<stdio.h>
#include<stdlib.h>
#define N 5

//This program is for insertion deletion display and exit in circular queue

int front =-1, rear = -1;
int queue[N];

int insertQ(int x){
	if(front == -1 && rear == -1){
		front = rear = 0;
		queue[rear] = x;
	}else if(front == (rear+1)%N){
		printf("Queue is overflow \n");
		return 1;
	}else{
		rear = (rear+1)%N;
		queue[rear]=x;
	}
	return 0;
}
int deleteQ(){
	if(front == -1 && rear == -1){
		printf("Queue underflow \n");
		return 1;
	}else if(front==0 && rear == 0){
	printf("The element deleted is %d \n",queue[front]);
		front = rear = -1;
	}else{
		printf("The element deleted is %d \n",queue[front]);
		front = (front+1)%N;
	}
}
void display(){
	int i=front;
	if(front == -1 && rear == -1){
		printf("Queue is empty \n");
	}
	else{

	printf("The content in the queue are: \n");
	do{
		printf("%d \n",queue[i]);
		i=(i+1)%N;
		}while(i!=(rear+1)%N);
	
	}
}

int main(){
	int ch,x;
	do{
	printf("1.Insert  2.Delete \n 3.Display  4.Exit \n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d",&x);
				insertQ(x);
				break;
			case 2:
				deleteQ();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exited");
				break;
			default:
				printf("Invalid input \n");
				break;
			}
	}while(ch!=4);
	return 0;
}


