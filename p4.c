#include<stdio.h>
#include<stdlib.h>

char infix[30],postfix[30],stack[30];
int top = -1;

void push(char item){
	top++;
	stack[top]=item;
}

char pop(){
	char item;
	item  = stack[top];
	top--;
	return item;
}

int prec(char symb){
	int p;
	switch(symb){
		case '(':
		case ')': p=0;
			  break;
		case '+':
		case '-': p=1;
			  break;
		case '*':
		case '/':
		case '%': p=2;
			  break;
		case '^':
		case '$': p=3;
			  break;
		default: p=-1;
	}
	return p;
}

void evaluate(){
	int i=0,j=0;
	char symb,temp;
	for(i =0;infix[i]!='\0';i++){
		symb=infix[i];
		switch(symb){
			case '(':push(symb);
				 break;
			case ')':temp = pop();
				 while(temp!='('){
					 postfix[j]=temp;
					 j++;
					 temp = pop();
				 }
				 break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			case '$': while(prec(stack[top]) >= prec(symb)){
					  temp = pop();
					  postfix[j] = temp;
					  j++;
				  }
				  push(symb);
				  break;
			default: postfix[j] = symb;
				 j++;
		}
	}
	while(top >= 0){
		temp = pop();
		postfix[j] = temp;
		j++;
	}
	postfix[j] = '\0';
}



void main(){
	printf("\nEnter a valid postfix expression: \t");
	scanf("%s",infix);
	evaluate();
	printf("\n The entered infix expression is : \n %s \n",infix);
	printf("\n The corresponding postfix expression is: \n %s \n",postfix);
}


