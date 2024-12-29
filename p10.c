#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};

typedef struct bst NODE;

NODE *createtree(NODE *node,int data){
	if(node==NULL){
		NODE *temp;
		temp=(NODE*)malloc(sizeof(NODE));
		temp->data = data;
		temp->right=temp->left=NULL;
		return temp;
	}else if(data < node->data){
		node->left = createtree(node->left,data);
	}else if(data > node->data){
		node->right = createtree(node->right,data);
	}
	return node;
}
NODE *search(NODE *node,int data){
	if(node==NULL){
		printf("Elemenet not found \n");
	}else if(data < node->data){
		node->left = search(node->left,data);
	}else if(data > node->data){
		node->right = search(node->right,data);
	}else{
		printf("Element found is %d \n",node->data);
	}
	return node;
}

void preorder(NODE *node){
	if(node!=NULL){
    	 	printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(NODE *node){
        if(node!=NULL){
                inorder(node->left);
                printf("%d ",node->data);
                inorder(node->right);
        }
 }

void postorder(NODE *node){
	        if(node!=NULL){
                postorder(node->left);
                postorder(node->right);
		    printf("%d ",node->data);

        }
 }

void main(){
	int ch,data,n;
		NODE *root = NULL;
		while(1){
			printf("1.Create a bst \n");
			printf("2.search \n");
			printf("3.preorder \t 4.inorder \t 5.postorder \n");
			printf("6.Exit \n");
			printf("Enter your choice: ");
			scanf("%d",&ch);
			switch(ch){
				case 1:printf("Enter the number of data to be inserted \n");
				       scanf("%d",&n);
				       printf("Enter the bst \n");
				       for(int i=0;i<n;i++){
					       scanf("%d",&data);
					       root = createtree(root,data);
				       }
				       break;
				case 2:printf("Enter the data to be searched \n");
				       scanf("%d",&data);
				       root = search(root,data);
				       break;
				case 3:printf("preorder traversal \n");
				       preorder(root);
				         printf("\n");

				       break;
				case 4:printf("inorder traversal \n");
				       inorder(root);
				         printf("\n");

				       break;
				case 5:printf("postorder traversal \n");
				       postorder(root);
				     printf("\n");

				       break;
				case 6:printf("Code Exited \n");
				       exit(0);
				       break;
				default:printf("Wrong choice \n");
					break;
			}				      	      
			}
}





