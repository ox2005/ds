#include<stdio.h>
#include<math.h>
void tower(int n,int source,int temp,int destination){
	if(n==0)
		return;
	tower(n-1,source,destination,temp);
	printf("\n Move disc %d from %c to %c \n",n,source,destination);
	tower(n-1,temp,source,destination);
}
void main(){
	int n;
	printf("\n Enter the no of discs: ");
	scanf("%d",&n);
	printf("\n The sequence of moves involved in the tower of hand are \n");
	tower(n,'A','B','C');
	printf("\n \n Total number of moves are: %d \n",(int)pow(2,n)-1);
}
