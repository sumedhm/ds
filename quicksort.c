#include <stdio.h>

void quicksort(int array[], long long int left, long long int right){
	int pivot = array[(left+right)/2];
	long long int i=left, j=right;
	int temp;
	while(i<=j){
		while(array[i]<pivot) i++;
		while(array[j]>pivot) j--;
		if(i<=j){
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++; j--;
		}
	}
	if(left < j) quicksort(array, left, j);
	if(i < right) quicksort(array, i, right);
	return;
}

int main(){
	printf("Enter the size of array: ");
	long long int n, i;
	scanf("%lld", &n);
	int array[n];
	printf("\n\nPlease enter %lld elements of the array:\n", n);
	for(i=0;i<n;i++) scanf("%d", &array[i]);
	quicksort(array, 0, n-1);
	printf("\n\nThe array after sorting is :\n");
	for(i=0;i<n;i++) printf("%d ", array[i]);
	printf("\n");
	return 0;
}
