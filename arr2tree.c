#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node *root;

int n;

void printtree(struct node *root){/*Inorder*/
	if(root==NULL) return;
	if(root->left!=NULL) printtree(root->left);
	printf(" %d ", root->val);
	if(root->right!=NULL) printtree(root->right);
	//Test tree here.
	/*if(root->left!=NULL) printf(" %d ", root->left->val);printf(" %d ", root->val);
	if(root->right!=NULL) printf(" %d ", root->right->val);printf("\n");*/
}

void createtree(struct node *temp, int left, int right, int arr[n]){
	temp->val = arr[(left+right)/2];
	temp->left = NULL;
	temp->right = NULL;
	if(left!=right){
		if(left !=(left+right)/2){
			temp->left = (struct node *) malloc (sizeof(struct node));
			createtree(temp->left, left, ((left+right)/2), arr);
		}
		if(right !=((left+right)/2)+1){
			temp->right = (struct node *) malloc (sizeof(struct node));
			createtree(temp->right, ((left+right)/2)+1, right, arr);
		}
	}
	return;
}

int main(){

	printf("\nPlease enter the value of n - ");
	scanf("%d", &n);

	int arr[n], i=0;
	printf("\n\nPlease enter the elements of sorted array:\n");
	while(i<n){
		scanf("%d", &arr[i]);i++;
	}

	root = (struct node *) malloc (sizeof(struct node));
	root->left = NULL;
	root->right = NULL;
	createtree(root, 0, n, arr);printf("\n\nPrinting tree\n");
	printtree(root);
	printf("\n\n-----------------------------------------\n");
	
	return 0;
}
