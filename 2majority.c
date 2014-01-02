
#include <stdio.h>
#include <stdlib.h>


main(){
	int n;
	int i=0;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int array[n];
	printf("\n\nEnter %d elements of array now - \n", n);
	while(i<n){
		scanf(" %d", &array[i]);
		i++;
	}
	
	printf("\n\nArray scanned..looking for 2 majority element..\n\n");
	
	int count=1, element=array[0];

	for(i=1;i<n;i++){
		if(array[i]==element){
			count++;
		} else {
			if(count==0){
				count++;
				element = array[i];
			} else {
				count--;
			}
		}
	}
	count=0;
	for(i=0;i<n;i++){
		if(array[i]==element) count++;
	}

	if(count>(n/2)){
		printf("The array has 2-majority element - %d, occurs %d/%d times\n\n", element, count, n);
	}
	else {
		printf("The array doesn't have any 2-majority element\n\n", element, count, n);
	}

}
