/**
*
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int val;
	struct node *left;
	struct node *right;
};

void checkbstornot(struct node *temp, int *bst, int *prev){   //same as inorder.
	if(temp!=NULL){
		checkbstornot(temp->left, bst, prev);
		if(temp->val < *prev) *bst = 0;
		*prev = temp->val;
		printf("%d ", temp->val);		
		checkbstornot(temp->right, bst, prev);
	}
	return;
}

struct List{
	struct node *content;
	struct List *next;
};

struct List *head, *tail;

void Enqueue(struct node *temp){
	if(head==NULL){
		head = (struct List *) malloc (sizeof(struct List));
		tail = head;
	} else {
		tail->next = (struct List *) malloc (sizeof(struct List));
		tail = tail->next;
	}
	tail->content = temp;
	tail->next = NULL;
	return;
}

struct node *Dequeue(){
	struct node *ans;
	struct List *temp;
	if(head!=NULL) temp = head;
	else return NULL;
	ans = head->content;
	head = head->next;
	free(temp);
	return ans;
}

int IsEmpty(){
	if (head==NULL) return 1;
	else return 0;
}

void printlist(){
	printf("\nPrinting list contents:\n");
	struct List *temp = head;
	while(temp!=NULL){
		printf("%d->", temp->content->val);
		temp = temp->next;
	}
	printf("NULL\n");
	return;
}

main(){
	int i, j, n=0;
	struct node *temp;
	head = NULL;
	struct node *root = (struct node *) malloc (sizeof(struct node));
	printf("Enter a root value: ");
	scanf("%d", &i);
	root->val = i;
	root->left = NULL; root->right = NULL;
	Enqueue(root);
	while(!IsEmpty()){
		temp = Dequeue();
		printf("\nEnter left and right child respectively for %d(-1 for NULL): ", temp->val);
		scanf("%d %d", &i, &j);
		if(i!=-1){
			temp->left = (struct node *) malloc (sizeof(struct node));
			temp->left->val = i;
			temp->left->left = NULL;temp->left->right = NULL;
			Enqueue(temp->left);
		}
		if(j!=-1){
			temp->right = (struct node *) malloc (sizeof(struct node));
			temp->right->val = j;
			temp->right->left = NULL;temp->right->right = NULL;
			Enqueue(temp->right);
		}
		//printlist();	//To debug.
	}
	printf("\n\nInorder Traversal of Tree:\n");
	int bst = 1, prev = -1;
	checkbstornot(root, &bst, &prev);
	printf("\n");
	if(bst==1) printf("The tree is a BST.\n");
	else printf("The tree is not a BST.\n");
	return;
}
