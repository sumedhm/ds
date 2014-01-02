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

int i=0;

int same_level = 1;		//If any leaf is found, and first node is not leaf, we will know that all leaves are not at the same level.
				//Or if first node is not leaf and a leaf is found, same_level will be false.
int first_node_is_leaf = 0;	//If first node is leaf, and some node at same level is not leaf, we will know all leaves are not at same level.

int end = 0;	//We should stop checking if any leaf is found, no need to go to next level. Just checking this level would be sufficient.

struct node *root;

void print(struct node *temp){
	if(temp!=NULL){
		print(temp->left);
		printf("%d ", temp->val);
		print(temp->right);
	}
}
struct List {
	struct node* item;
	struct List* next;
};

struct List *head;
struct List *temp;
struct List *tail;
struct List *pointer;

void dequeue(){
	temp = head;
	head = head->next;
	free(temp);
}

void enqueue(struct node* new){
	tail->next = (struct List*) malloc(sizeof(struct List));
	tail = tail->next;
	tail->item = new;
	tail->next = NULL;
}

void printlist(){				//print list of the level
	i++;
	temp = head;
	printf("\nPrinting list at level %d:\n", i);
	while(temp!=NULL){
		printf("%d->", temp->item->val);	
		temp = temp->next;
	}
	printf("null\n\n");
}

int is_leaf(struct node* item){
	if(item->left==NULL && item->right==NULL){
		return 1;
	}
	return 0;
}

void populate_and_check_list(){
	if(is_leaf(head->item)){
		first_node_is_leaf=1;
		end = 1;
	}
	while(head!=pointer){
		if(((!first_node_is_leaf) && is_leaf(head->item)) || ((first_node_is_leaf && !is_leaf(head->item)))){
			end = 1;
			same_level = 0;
		} else {
			if(head->item->left!=NULL) enqueue(head->item->left);
			if(head->item->right!=NULL) enqueue(head->item->right);
			dequeue();
		}
	}
	
	//Check for the last node.
	if(((!first_node_is_leaf) && is_leaf(head->item)) || ((first_node_is_leaf && !is_leaf(head->item)))){
                        end = 1;
                        same_level = 0;
        } else {
                        if(head->item->left!=NULL) enqueue(head->item->left);
                        if(head->item->right!=NULL) enqueue(head->item->right);
                        dequeue();
        }

	pointer = tail;
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
	//printf("\nPrinting entire tree inorder - \n");
	//print(root);
	printf("\n");
	head = (struct List*) malloc (sizeof(struct List));
	head->item = root;
	head->next = NULL;
	tail = head;
	pointer = head;

	while(!end){
		//printlist();
		populate_and_check_list();
	}
	if(same_level){
		printf("\nThe leaves are at same level..\n");
	} else {
		printf("\nThe leaves aren't at the same level..\n");
	}

	exit(0);
}
