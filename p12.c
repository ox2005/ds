#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int a[MAX];
void display();

int create(int num){
	int key;
	key = num%100;
	return key;
}


void linear_probing(int key,int num){
	int count=0,i,j,flag=0;
	if(a[key]==-1){
		a[key] = num;
	}else{
		printf("Collision Detected \n");
		i=0;
		while(i<MAX){
			if(a[i]!=-1){
				count++;
			}
			i++;
		}
	
		if(count==MAX){
		printf("Hash table is full \n");
		display();
		exit(1);
		}
		printf("Solved by linear probing \n");
		
	for(i=key+1;i<MAX;i++){
		if(a[i]==-1){
		a[key] = num;
		flag =1;
		}
	}
		i=0;
	while((i<key) && flag==0){
		if(a[i]==-1){
		a[key]=num;
	}
		i++;
	}	
	}
}

void display(){
	int ch;
	printf("Choose what to display \n");
	printf("1.Display All \n 2.Filtering \n");
	scanf("%d",&ch);
		
		switch(ch){
		case 1:
		        printf("Displaying hash table \n");
			for(int i=0;i<MAX;i++){
				printf("%d %d \n",i,a[i]);
				}
			break;
		case 2:
	 		printf("Displaying the filtered hash table \n");
			for(int i=0;i<MAX;i++){
			if(a[i]!=-1){
			printf("%d %d \n",i,a[i]);
			}
			}
			break;
		default:
		printf("Invalid choice \n");
	}
}

void main(){
	int key,num,ch;
		for(int i=0;i<MAX;i++){
			a[i]=-1;
			}
	printf("By Linear Probing \n");
		do{
			printf("Enter the data: ");
			scanf("%4d",&num);
			key = create(num);
			linear_probing(key,num);
			printf("Do you want to continue: (1/0)\n");
			scanf("%d",&ch);
		}while(ch);
		display(a);
}

