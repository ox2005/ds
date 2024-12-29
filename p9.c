#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(x,y)((x==y)?0:(x>y)?1:-1)

struct node{
	int coef;
	int xexp,yexp,zexp;
	struct node *link;
};

typedef struct node NODE;

NODE *getnode(){
	NODE *x=NULL;
	x = (NODE*)malloc(sizeof(NODE));
	if(x==NULL){
		printf("memory allocation failed \n");
		return NULL;
	}
	return x;
}


NODE *attach(int coef,int xexp,int yexp,int zexp,NODE *head){

	NODE *temp,*cur;
	temp = getnode();
	temp->coef=coef;
	temp->xexp=xexp;
	temp->yexp=yexp;
	temp->zexp=zexp;
	cur=head->link;
	while(cur->link!=head){
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=head;
	return head;
}

NODE *read_poly(NODE *head){
	int coef,xexp,yexp,zexp,i,n;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter coefficent: ");
		scanf("%d",&coef);
		printf("Enter the pow(x) pow(y) and pow(z): ");
		scanf("%d %d %d",&xexp,&yexp,&zexp);
		head = attach(coef,xexp,yexp,zexp,head);
	}
	return head;
}


void display(NODE *head){
	NODE *temp;
	if(head==NULL){
		printf("Polynomial is empty \n");
		return;
	}
	temp=head->link;
	while(temp!=head){
		printf("%dx^%dy^%dz^%d",temp->coef,temp->xexp,temp->yexp,temp->zexp);
		temp=temp->link;
		if(temp!=head)
			printf(" + ");
	}
}

int polyevaluate(NODE *head){
	NODE *poly;
	int x,y,z,sum=0;
	printf("Enter the value of x y and z: ");
	scanf("%d %d %d",&x,&y,&z);
	poly = head->link;
	while(poly!=head){
		sum += poly->coef*(pow(x,poly->xexp)*pow(y,poly->yexp)*pow(z,poly->zexp));
		poly=poly->link;
	}
	return sum;
}

NODE *poly_sum(NODE *head1,NODE *head2,NODE *head3){
	NODE *a,*b;

	a = head1->link;
	b = head2->link;
	while(a!=head1 && b!=head2){
	if(a->xexp==b->xexp && a->yexp==b->yexp && a->zexp==b->zexp){
		head3 = attach(a->coef + b->coef,a->xexp,a->yexp,a->zexp,head3);
		a=a->link;
		b=b->link;
}else if((COMPARE(a->xexp,b->xexp)>0) || a->xexp==b->xexp && (COMPARE(a->yexp,b->yexp)>0) || a->xexp==b->xexp && a->yexp==b->yexp && (COMPARE(a->zexp,b->zexp)>0)){
	head3 = attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
	a=a->link;
}else{
	head3 = attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
	b=b->link;
}
	while(a!=head1){
		head3 = attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
		a = a->link;
	}
	while(b!=head2){
		head3 = attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
		b=b->link;
	}
}
return  head3;
}

void main(){
	int ch,sum;
	NODE *head,*head1,*head2,*head3;
	head=getnode();
	head1=getnode();
	head2=getnode();
	head3=getnode();
	head->link=head;
	head1->link=head1;
	head2->link=head2;
	head3->link=head3;
	
	while(1){
		printf("\n 1.Represent and evaluate a polynomial \n");
		printf("\n 2.Addition of two polynomial \n");
		printf("\n 3.Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the polynomial \n");
				read_poly(head);
				printf("Representation of polynomial \n");
				display(head);
				printf("\n Evaluation of the given polynomial \n");
				sum = polyevaluate(head);
				printf("%d ",sum);
				break;
			case 2:
				printf("Enter poly1: \n");
				read_poly(head1);
				printf("representaion of poly1: \n");
				display(head1);
				printf("\nEnter poly2: \n");
                                read_poly(head2);
                                printf("representaion of poly2: \n");
                                display(head2);
				poly_sum(head1,head2,head3);
				printf("\n Result of sum of two polynomial: \n");
				display(head3);
				break;
			case 3:
				printf("Code exited\n");
				exit(0);
				break;
			defautl: 
				printf("Invalid choice \n");
			}
	}
}







