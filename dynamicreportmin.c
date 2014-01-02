#include <stdio.h>

int n, size;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int min(int a, int b){
	if(a<b) return a;
	else return b;
}

void ReportMin(int arr[]){
	int i,j;
	printf("\n\nEnter the value of i, j respectively: ");
	scanf("%d %d", &i, &j);
	if(i>j) swap(&i, &j);
	i = i+(n-1);
	j = j+(n-1);
	int ans = min(arr[i],arr[j]);
	while((i-1)/2 != (j-1)/2){
		if(i%2==1) ans = min(ans, arr[i+1]);
		if(j%2==0) ans = min(ans, arr[j-1]);
		i = (i-1)/2;
		j = (j-1)/2;
	}
	printf("\n\nMinimum in the given range is %d\n", ans);
	return;
}

void Update(int arr[]){
	int i, a;
	printf("\n\nEnter index and new value for element to be updated: ");
	scanf("%d %d", &i, &a);
	i = i+(n-1);
	arr[i] = a;
	while(i>0){
		if(i%2==1) arr[(i-1)/2] = min(arr[i], arr[i+1]);
		else arr[(i-1)/2] = min(arr[i], arr[i-1]);
		i = (i-1)/2;
	}
	/*printf("\n\nThe array is : ");
	for(i=0;i<size;i++) printf("%d ", arr[i]);
	printf("\n");*/
	return;
}

int main(){

	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("\nEnter the %d elements of array now\n", n);
	int i=0, j;
	size = (2*n)-1; int arr[size];
	for(i=0;i<n;i++) arr[i]=0;
	i=0; arr[size-1]=0;
	while(i<n){
		scanf("%d", &arr[n-1+i]);
		i++;
	}
	i=0;
	j= n-1;
	while(j>0){
		i = j;
		while(i<(2*j)){
			arr[(i-1)/2] = min(arr[i], arr[i+1]);
			i += 2;
		}
		j = (j-1)/2;
	}
	i=0;
	//while(i<size){ printf("%d:%d\n", i,arr[i]);i++;}
	int repeat = 1;
	while(repeat){
		printf("\n\nExit-0, Report-Min(i,j)-1, Update(i, a)-2.\nEnter input: ");
		scanf("%d", &repeat);
		if(repeat==1) ReportMin(arr);
		else if(repeat==2) Update(arr);
	}
	return 0;
}
