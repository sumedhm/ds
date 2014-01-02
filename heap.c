#include <stdio.h>

int n, size=0, next=1;

int min(int heap[], int a, int b){ //return index of smaller element.
	if(heap[a]>heap[b] && b<size) return b;
	else return a;
}

void swap(int heap[], int x){  //x will be child, to swap with parent.
	int temp;
	temp = heap[x];
	heap[x] = heap[(x-1)/2];
	heap[(x-1)/2] = temp;
	return;
}

void swap2(int heap[], int x, int y){  //x will be parent, to swap with child y.
	int temp;
	temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
	return;
}

void Insert(int heap[]){
	int x;
	printf("\nEnter value to insert into the heap : ");
	scanf("%d", &x);
	if(size<n) heap[size++] = x;
	else printf("\n\nCannot insert, heap full.\n");
	x=size-1;
	while(x>0 && heap[x]<heap[(x-1)/2]){
		swap(heap, x);
		x = (x-1)/2;
	}
	printf("\n\nHeap after insertion:\n");for(x=0;x<size;x++) printf("%d ", heap[x]);printf("\n\n");
}

void Heapify(int i, int heap[]){
	int flag=1, j;
	while(i<=((size-1)/2) && flag){
		j= min(heap, (2*i)+1, (2*i)+2);
		if(heap[i]>heap[j] && j<size) swap2(heap, i, j);
		else flag=0;
		i = j;
	}
}

void Extract_Min(int heap[]){
	int x;
	x = heap[0];
	heap[0] = heap[size-1];
	heap[size-1] = 0; size--;
	Heapify(0, heap);
	printf("\n\nMin : %d", x);
	printf("\nHeap after extracting min:\n");for(x=0;x<size;x++) printf("%d ", heap[x]);printf("\n\n");
}

void Decrease_Key(int heap[]){
	int p, d;
	printf("Enter key and decrement value: ");
	scanf("%d %d", &p, &d);
	heap[p] -= d;
	p = (p-1)/2;
	while(p>=0 && heap[p] > heap[min(heap, (2*p)+1, (2*p)+2)]){
		swap2(heap, p, min(heap, (2*p)+1, (2*p)+2));
		p = (p-1)/2;
	}
	printf("\n\nHeap after insertion:\n");for(p=0;p<size;p++) printf("%d ", heap[p]);printf("\n\n");
}

void Create_Heap(int heap[]){
	size=0;int x=0;
	printf("\n\nEnter number of elements(<%d), followed by elements in next line to heapify :", n);
	scanf("%d", &size);
	while(x<size) scanf("%d", &heap[x++]);
	x = ((size-1)-1)/2;
	while(x >= 0) Heapify(x--, heap);
	printf("\n\nHeap after heapifying:\n");for(x=0;x<size;x++) printf("%d ", heap[x]);printf("\n\n");
}

int main(){
	printf("Enter the value of n: ");
	scanf("%d", &n);
	int heap[n];
	while(next){
		printf("\n\nExit : 0, Insert : 1, Extract min : 2, Decrease Key : 3, Heapify(O(n)) : 4\nEnter input : ");
		scanf("%d", &next);
		if(next==1) Insert(heap);
		else if(next==2) Extract_Min(heap);
		else if(next==3) Decrease_Key(heap);
		else if(next==4) Create_Heap(heap);
	}
	return 0;
}
