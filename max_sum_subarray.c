
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

main(){
	int n;
	int i=0;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int array[n], sum[n];
	printf("\n\nEnter %d elements of array now - \n", n);
	while(i<n){
		scanf(" %d", &array[i]);
		sum[i]=0;
		i++;
	}
	printf("\n\nArray scanned..looking for max sum subarray..\n\n");
	sum[0]=array[0];
	int left=0, right=0, maximum=sum[0];
	for(i=1;i<n;i++){
		sum[i] = max(sum[i-1]+array[i], array[i]);
		if(maximum<sum[i]){
			maximum = sum[i];
			right = i;
			if(sum[i]==array[i]){
				left = i;
			}
		}
		if(maximum==sum[i])
			right = i;
	}
	
	printf("\nMax Sum: %d,\nRange: (%d-%d)\n\n", maximum, left, right);	
}
