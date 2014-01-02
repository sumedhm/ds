#include <stdio.h>

int n, size;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void MultiIncrement(int arr[]){
	int i,j,d;
	printf("\n\nEnter the value of i, j, delta respectively: ");
	scanf("%d %d %d", &i, &j, &d);
	if(i>j) swap(&i, &j);
	i = i+(n-1);
	j = j+(n-1);
	arr[i] += d; arr[j] += d;
	while((i-1)/2 != (j-1)/2){
		if(i%2==1) arr[i+1] += d;
		if(j%2==0) arr[j-1] += d;
		i = (i-1)/2;
		j = (j-1)/2;
	}
	printf("\n\n");
	for(i=0;i<size;i++) printf("%d ", arr[i]);
	printf("\n");
	return;
}

void Report(int arr[]){
	int i, ans=0;
	printf("\n\nEnter i for element to be reported: ");
	scanf("%d", &i);
	int j=i;
	i = i+(n-1);
	while(i>=0){
		ans += arr[i];
		if(i==0) break;
		i = (i-1)/2;
	}
	printf("\n\nThe %d th element is : %d.\n", j , ans);
	return;
}

int main(){

	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("\nEnter the %d elements of array now\n", n);
	int i=0;
	size = (2*n)-1; int arr[size];
	for(i=0;i<n;i++) arr[i]=0;
	i=0; arr[size-1]=0;
	while(i<n){
		scanf("%d", &arr[n-1+i]);
		i++;
	}
	i=0;
	//while(i<size) printf("%d:%d\n", i,arr[i++]);
	int repeat = 1;
	while(repeat){
		printf("\n\nExit-0, Multi-Increment(i,j,delta)-1, Report(i)-2.\nEnter input: ");
		scanf("%d", &repeat);
		if(repeat==1) MultiIncrement(arr);
		else if(repeat==2) Report(arr);
	}
	return 0;
}
