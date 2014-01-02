#include <stdio.h>

void merge(int arr[], int left1, int right1, int left2, int right2){
	int temp[right2-left1+1];
	int i=left1,j=left2,k=0;
	while(i<=right1 && j<=right2){
		if(arr[i]<=arr[j]){
			temp[k] = arr[i];i++;
		} else {
			temp[k] = arr[j];j++;
		}
		k++;
	}
	while(i<=right1) {temp[k] = arr[i];i++;k++;}
	while(j<=right2) {temp[k] = arr[j];j++;k++;}
	for(i=left1,k=0;i<=right2;i++,k++) arr[i] = temp[k];

	return;
}

void msort(int arr[], int left, int right){
	if(left==right) return;
	msort(arr, left, (left+right)/2);
	msort(arr, ((left+right)/2)+1, right);
	merge(arr, left, (left+right)/2, ((left+right)/2)+1, right);
	return;
}

int main(){
	int n;
	printf("\nEnter size of array to sort: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nPlease enter %d elements of array\n", n);
	int i=0;
	while(i<n){
		scanf("%d", &arr[i]);
		i++;
	}
	msort(arr, 0, n-1);

	printf("\n\n");
	for(i=0;i<n;i++) printf("%d ", arr[i]);
	printf("\n\n");

	return 0;
}
