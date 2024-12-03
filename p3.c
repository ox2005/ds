#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(){
	if(top==MAX-1){
		printf("Stack Overflow \n");
	}else{
		printf("Enter the Element to be pushed: ");
		int x;
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
	}
void pop(){
	if(top==-1){
		printf("Stack Underflow \n");
	}else{
		int item;
		item = stack[top];
		top--;
		printf("The popped element is %d",item);
		}
}
void display(){
	printf("The contents are: \n");
	for(int i=top;i>=0;i--){
		printf("%d \n",stack[i]);
	}
}
void palindrome(){
	printf("The contents are: \n");
	for(int i=top;i>=0;i--){
                printf("%d \n",stack[i]);
        }
	printf("The Reverse contents are: \n");
		for(int i=0;i<=top;i++){
			printf("%d \n",stack[i]);
		}
	int flag=0;
	for(int i=0;i<=top/2;i++){
		if(stack[i]!=stack[top-i]){
			flag=1;
		}
	}
	if(flag==1){
		printf("The given stack is not a palindrome \n");
	}else{
		printf("The given stack is palindrome \n");
	}
	}

void main(){
	int ch;
	do{
	printf("1.push \n 2.pop \n 3.display \n 4.palindrome \n 5.exit \n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			palindrome();
			break;
		case 5:
			printf("Exited \n");
			break;
		default:
			printf("Invalid Choice \n");
		}
	}while(ch!=5);
}

