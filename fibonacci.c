#include <stdio.h>

int ifib(int n){
	int ans, a, b, i=0;
	a=0;b=1;ans=1;
	for(i=2;i<=n;i++){
		ans = a+b;
		a = b;
		b = ans;
	}
	return ans;	
}

int rfib(int n){
	if(n == 0) return 0;
	else if (n == 1) return 1;
	int ans = rfib(n-1)+rfib(n-2);
	return ans;
}

void mult(int a[2][2], int b[2][2], int c[2][2]){
	int i,j,k,d[2][2],e[2][2];
	for(i=0;i<2;i++) for(j=0;j<2;j++) {d[i][j] = a[i][j];e[i][j] = b[i][j];c[i][j] = 0;}
	for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++) c[i][j] += d[i][k] * e[k][j];
	return;
}

void power(int a[2][2], int n, int c[2][2]){
	if (n==1){
		int i,j;
		for(i=0;i<2;i++) for(j=0;j<2;j++) c[i][j] = a[i][j];
	}
	else if(n%2 ==0){
		power(a, n/2, c);mult(c, c, c);
	}
	else {
		power(a, n/2, c);mult(c, c, c);mult(a, c, c);
	}
	return;
}

int mfib(int n){
	int ans;
	int a[2][2] = {1,1,1,0};int c[2][2] = {0,0,0,0};
	if(n==0) return 0;
	if(n==1) return 1;
	power(a, n-1, c);
	ans = c[0][0];
	//printf("\n%d,%d,%d,%d\n", a[0][0],a[0][1], a[1][0],a[1][1]);
	return ans;	
}

main(){
	int n, m, ans;
	printf("\nEnter the value of n to find nth fibonacci number: ", &n);
	scanf("%d", &n);
	printf("Select the method to find fibonacci number: \n\tIterative - 1\n\tRecursive - 2\n\tUsing matrix - 3\n\tAll - 4\n\nEnter the number corresponding the method : ");
	scanf("%d", &m);
	while(!(m>0 && m<5)){
		printf("\nEnter a valid method number : \n");scanf("%d", &m);
	}
	if(m==1){
		ans = ifib(n);
	} else if(m==2){
		ans = rfib(n);
	} else if(m==3){
		ans = mfib(n);
	}
	if(m==4) printf("\n\nThe %d'th fibonacci number is :\n\tAccording to method 1 : %d,\n\tAccording to method 2 : %d,\n\tAccording to method 3 : %d. \n\n", n, ifib(n), rfib(n), mfib(n));
	else printf("\n\nThe %d'th fibonacci number is : %d\n\n", n, ans);

}
