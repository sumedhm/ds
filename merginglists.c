#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
	int val;
	struct list_ *next;
} list;

list *list1_head, *list1_tail, *list2_head, *list2_tail;

list *reverse_list(list *head){
	list *temp1 = head;
	head = head->next;
	list *temp2 = head->next;
	temp1->next = NULL;
	while(temp2!=NULL){
		head->next = temp1;					//reverse pointer
		temp1 = head; head = temp2; temp2 = temp2->next;	//increment pointers.
	}
	head->next = temp1;
	return head;
}

void printlist(list *head){
	list *temp = head;
	printf("\n\nPrinting list:\n");
	while(temp!=NULL){
		printf("%d->", temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
}

void comparemergingpoint(list *head1, list *head2, int *merge){
	while(head1!=NULL && head2!=NULL){
		if(head1->val == head2->val) *merge = *merge + 1;
		else break;
		head1 = head1->next; head2 = head2->next;
	}
	return;
}

int main(){
	list *temp;
	printf("Enter size followed by elements for list 1: ");
	int k, n, i=0;
	scanf("%d", &k);
	while(i<k){
		scanf("%d", &n);		
		if(list1_head==NULL){
			list1_head = (list *) malloc (sizeof(list));
			list1_tail = list1_head;
		} else {
			list1_tail->next = (list *) malloc (sizeof(list));
			list1_tail = list1_tail->next;
		}
		list1_tail->val = n;
		list1_tail->next = NULL;
		i++;
	}
	printf("\nEnter size followed by elements for list 2: ");
	scanf("%d", &k);
	i=0;
	while(i<k){
		scanf("%d", &n);
		if(list2_head==NULL){
			list2_head = (list *) malloc (sizeof(list));
			list2_tail = list2_head;
		} else {
			list2_tail->next = (list *) malloc (sizeof(list));
			list2_tail = list2_tail->next;
		}
		list2_tail->val = n;
		list2_tail->next = NULL;
		i++;
	}
	//printlist(list1_head); printlist(list2_head);
	list1_head = reverse_list(list1_head);
	list2_head = reverse_list(list2_head);
	//printlist(list1_head); printlist(list2_head);
	int merge = 0;
	comparemergingpoint(list1_head, list2_head, &merge);
	if(merge>0) printf("\n\nThe lists merge upto %d elements from tails.\n", merge);
	else printf("\n\nThe lists do not merge.\n");

	return 0;
}
