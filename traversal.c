#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node *root;

void inorder(struct node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ", temp->val);
		inorder(temp->right);
	}
}


void preorder(struct node *temp){
	if(temp!=NULL){
		printf("%d ", temp->val);
		preorder(temp->left);
		preorder(temp->right);
	}
}


void postorder(struct node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ", temp->val);
	}
}

void insert(int val){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	struct node *temp = root;
	while(1){
		if(temp->val > new->val){
			if(temp->left!=NULL) temp = temp->left;
			else {temp->left = new;break;}
		} else {
			if(temp->right!=NULL) temp = temp->right;
			else {temp->right = new;break;}
		}
	}
	return;
}

main(){
	int i=0;
	root = NULL;
	printf("\nEnter a root value: ");
	scanf("%d", &i);
	root = (struct node*)malloc(sizeof(struct node));
	root->val = i;
	root->left = NULL;
	root->right = NULL;
	printf("\nEnter a node value('-1' to cancel): ");
	scanf("%d", &i);
	while(i!=-1){
		insert(i);
		printf("\nEnter a node value(-1 to cancel): ");
		scanf("%d", &i);
	}
	printf("\n");
	printf("Inorder Traversal:\n");
	inorder(root);
	printf("\n\n");
	printf("Preorder Traversal:\n");
	preorder(root);
	printf("\n\n");
	printf("Postorder Traversal:\n");
	postorder(root);
	printf("\n\n");
	exit(0);
}
