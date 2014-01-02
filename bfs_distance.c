#include <stdio.h>
#include <stdlib.h>

int n, m;

struct bfsqueue{
	int vertex;
	struct bfsqueue *next;
};

struct bfsqueue *queue_head, *queue_tail;


struct node{
	int visited;
	int distance;
	int label;
	int parent;
	struct adjency_list *head;
	struct adjency_list *tail;
};

struct adjency_list {
	int vertex;
	struct adjency_list *next;
};

struct component{
	int vertex;			//Vertex V.
	int label;			//Label for connected component.
	struct component *sibling;  	//Belongs to the same component(same label).
	struct component *next; 	//Belongs to different component(different label).
};

struct component * comp_head, *comp_tail_h, *comp_tail_v; //comp_tail_horizontal for same conn component. comp_tail_vertical for different conn component.
/*
void PrintAdjencyList(int n, struct node vertex[]){
	printf("\nAdjency list of %d: ", n);
	struct adjency_list *temp = vertex[n].head;
	while(temp!=NULL){
		printf("%d->", temp->vertex);
		temp = temp->next;
	}
	printf("\n");
}
*/
void enqueue(int temp){
	if(queue_head==NULL){
		queue_head = (struct bfsqueue *) malloc (sizeof(struct bfsqueue));
		queue_tail = queue_head;
	} else {
		queue_tail->next = (struct bfsqueue *) malloc (sizeof(struct bfsqueue));
		queue_tail = queue_tail->next;
	}
	queue_tail->vertex = temp;
	queue_tail->next = NULL;
	return;
}

int dequeue(){
	int k;
	struct bfsqueue *temp;
	temp = queue_head;
	queue_head = queue_head->next;
	k = temp->vertex;
	free(temp);
	return k;
}

int empty_queue(){
	if(queue_head==NULL) return 1;
	return 0;
}

void BFS(int temp, struct node vertex[]){
	vertex[temp].visited = 1;
	vertex[temp].parent = temp;
	vertex[temp].label = temp;
	enqueue(temp);int k;
	struct adjency_list * temp1;
	while(!empty_queue()){
		k = dequeue();
		//printf("%d:k\n",k);
		if(!vertex[k].visited){
			vertex[k].visited = 1;
			comp_tail_h->sibling = (struct component *) malloc (sizeof(struct component));
			comp_tail_h = comp_tail_h->sibling;
			comp_tail_h->vertex = k; comp_tail_h->label = temp; comp_tail_h->sibling = NULL; comp_tail_h->next = NULL;
			vertex[k].label = vertex[vertex[k].parent].label;
			vertex[k].distance = vertex[vertex[k].parent].distance+1;
		}
		temp1 = vertex[k].head;
		while(temp1 != NULL){
			if(!vertex[temp1->vertex].visited) enqueue(temp1->vertex);
			vertex[temp1->vertex].parent = k;
			temp1 = temp1->next;
		}
	}
}

int main(){

	printf("Enter number of vertices(n) and edges(m): ");
	scanf("%d %d", &n, &m);
	printf("\nEnter %d edges now: \n", m);
	int i=0, j, k;
	struct node vertex[n];
	for(j=0;j<n;j++){
		vertex[j].distance = -1;
		vertex[j].parent = -1;
		vertex[j].label = -1;
		vertex[j].visited = 0;
		vertex[j].head = NULL;
		vertex[j].tail = NULL;
	}
	while(i<m){				//Preparing adjency lists.
		scanf("%d %d", &j, &k);
		if(j>=n || k>=n){printf("\nError::Invalid index of vertex. Should be 0 to %d.\n", n-1);exit(1);}
		if(vertex[j].head == NULL){
			vertex[j].head = (struct adjency_list *) malloc (sizeof(struct adjency_list));
			vertex[j].tail = vertex[j].head;
		} else {
			vertex[j].tail->next = (struct adjency_list *) malloc (sizeof(struct adjency_list));
			vertex[j].tail = vertex[j].tail->next;
		}
		if(vertex[k].head == NULL){
			vertex[k].head = (struct adjency_list *) malloc (sizeof(struct adjency_list));
			vertex[k].tail = vertex[k].head;
		} else {
			vertex[k].tail->next = (struct adjency_list *) malloc (sizeof(struct adjency_list));
			vertex[k].tail = vertex[k].tail->next;
		}
		vertex[j].tail->next = NULL;
		vertex[j].tail->vertex = k;
		vertex[k].tail->next = NULL;
		vertex[k].tail->vertex = j;
		i++;
	}
	//for(i=0;i<n;i++) PrintAdjencyList(i, vertex);

	printf("\n\nFind distance from which vertex? - ");
	scanf("%d", &k);
	queue_head = NULL; queue_tail = NULL; comp_head = NULL; comp_tail_h = NULL; comp_tail_v = NULL;
	vertex[k].distance = 0;
	comp_head = (struct component *) malloc (sizeof(struct component));
	comp_tail_h = comp_head;
	comp_tail_v = comp_head;
	comp_head->vertex = k; comp_head->label = k; comp_head->sibling = NULL; comp_head->next = NULL;
	vertex[k].distance = 0;
	BFS(k, vertex);
	for(i=0;i<n;i++){
		if(!vertex[i].visited){
			comp_tail_v->next = (struct component *) malloc (sizeof(struct component));
			comp_tail_v = comp_tail_v->next;
			comp_tail_h = comp_tail_v;
			comp_tail_h->vertex = i; comp_tail_h->label = i; comp_tail_h->sibling = NULL; comp_tail_h->next = NULL;
			BFS(i, vertex);
		}
	}
	//for(i=0;i<n;i++) printf("%d: %d,%d,%d,%d\n", i, vertex[i].distance, vertex[i].label, vertex[i].parent, vertex[i].visited);

	printf("\n\nDistances of vertices from vertex %d:\n", k);
	struct adjency_list *temp1, *temp2;
	for(i=0;i<n;i++){
		if(vertex[i].label!=vertex[k].label) printf("%d - Infinite(belongs to different component)\n", i);
		else printf("%d - %d\n", i, vertex[i].distance);
		temp1 = vertex[i].head;
		while(temp1!=NULL){
			temp2 = temp1;
			temp1 = temp1->next;
			free(temp2);
		}
	}
	comp_tail_h = comp_head; comp_tail_v = comp_head;
	struct component *temp3 = comp_head, *temp4;
	printf("\n\nConnected Components:\n");
	while(comp_tail_v!=NULL){
		temp3 = comp_tail_v;
		comp_tail_v = comp_tail_v->next;
		printf("{");
		while(comp_tail_h->sibling!=NULL){
			printf("%d,", comp_tail_h->vertex);
			temp4 = comp_tail_h;
			comp_tail_h = comp_tail_h->sibling;
			free(temp4);
		}
		printf("%d}\n", comp_tail_h->vertex);
		comp_tail_h = comp_tail_v;
		free(temp3);
	}

	return 0;
}


