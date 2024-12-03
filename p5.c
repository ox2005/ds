#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int i,top=-1;
int op1,op2,res,s[20];
char postfix[90],symb;

void push(int item){
	if(top>=19){
		printf("Stack Overflow \n");
		exit(1);
	}else{
		top++;
		s[top] = item;
	}
}

int pop(){
	if(top==-1){
		printf("Stack Underflow \n");
		exit(1);
	}else{
	int item=s[top];
	top--;
	return item;
}
}
int main(){

		printf("Enter a valid postfix expression: ");
		scanf("%s",postfix);
		
		for(i=0;postfix[i]!='\0';i++){
			symb=postfix[i];
			if(isdigit(symb)){
				push(symb-'0');
			}else{
				op2 = pop();
				op1 = pop();
				switch(symb){
					case '+':
						push(op1+op2);
						break;
					case '-':
						push(op1-op2);
						break;
					case '*':
						push(op1*op2);
						break;
					case '/':
						if(op2==0){
							printf("Division by zero not possible \n");
							return 1;
						}
						push(op1/op2);
						break;
					case '$':
					case '^':
						push(pow(op1,op2));
						break;
					default:
						printf("invalid operator");
						return 1;
				}
			}
		}
		if(top==0){
		res = pop();
		printf("The result of the given postfix expression is: %d \n",res);
		}else{
			printf("Invalid postfix expression");
		}
		return 0;
}

		

