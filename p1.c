#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct days {
	char *name;
	int date;
	char *activity;
};
struct days week[7];

void create(){
	for(int i=0;i<7;i++){
		week[i].name = (char*)malloc(20*sizeof(char));
		week[i].activity = (char*)malloc(20*sizeof(char));
	}
}
void read(){
	for(int i=0;i<7;i++){
		printf("Enter the name of day %d: ",i+1);
		scanf("%s",week[i].name);
		printf("Enter the date of day %d: ",i+1);
		scanf("%d",&week[i].date);
		printf("Enter the activity of day %d: ",i+1);
		getchar();
		fgets(week[i].activity,100,stdin);
	}
}
void display(){
	printf("Day\tDate\tActivity \n");
	for(int i=0;i<7;i++){
		printf("%s\t%d\t%s\n",week[i].name,week[i].date,week[i].activity);
	}
}
int main(){
	printf("Creating the calendar \n");
	create();
	read();
	printf("Displaying the calendar \n");
	display();
	return 0;
}
