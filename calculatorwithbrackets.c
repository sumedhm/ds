#include <stdio.h>
#include <stdlib.h>

char arr[50];
char o_stack[50];
int n_stack[50];
int o_pointer, n_pointer, n; //pointers for operators stack and numbers stack.
int answer;

int power(int exp, int num){
	int i, ans=num;
	for(i=1;i<exp;i++){
		ans *= num;
	}
	return ans;
}

int execute(char c, int op1, int op2){
	//printf("\nExecute %c on %d and %d\n", c, op1,op2);
	switch(c){
		case '+': return (op2+op1);
		case '-': return (op2-op1);
		case '*': return (op2*op1);
		case '/': return (op2/op1);
		case '^': return (power(op1,op2));
		default: printf("\n\nInvalid Operator : %c\n\n", c); exit(1);
	}
}

int ipriority(char c){
	int priority;
	switch(c){
		case '*': case '/': priority = 2; break;
		case '+': case '-': priority = 1; break;
		case '^': priority = 3; break;
		case '(': priority = 0; break;
		default: priority = -1; break;
	}
	return priority;
}

int opriority(char c){
	int priority;
	switch(c){
		case '*': case '/': priority = 2; break;
		case '+': case '-': priority = 1; break;
		case '^': priority = 4; break;
		case '(': priority = 5; break;
		default: priority = -1; break;
	}
	return priority;
}

void n_push(int val){
	//printf("\nPushing %d into number stack.\n", val);
	n_stack[n_pointer] = val;
	n_pointer++;
	return;
}

int n_pop(){
	n_pointer--;
	//printf("\nPopping %d from n-stack.\n", n_stack[n_pointer]);
	return n_stack[n_pointer];
}

void o_push(char c){
	//printf("\nPushing %c into operator stack.\n", c);
	o_stack[o_pointer] = c;
	o_pointer++;
	return;
}

char o_pop(){
	o_pointer--;
	//printf("\nPopping %c from o-stack.\n", o_stack[o_pointer]);
	return o_stack[o_pointer];
}

int main(){

	printf("\nPlease enter the expression you want to evaluate:\n");
	n=0;scanf("%c", &arr[n]);
	while(arr[n]!=' ' && arr[n]!='\n') {n++;scanf("%c", &arr[n]);}
	arr[n] = 'x';arr[n+1] = '\0';
	//printf("\n");printf("%s", arr);
	int num, n1, n2; char next, top;
	o_pointer = 0; n_pointer = 0;
	int i=0;int x=0;
	o_push('#');
	while(1){
		next = arr[i];
		num = 0;
		if(next>='0' && next<='9'){
			while(next>='0' && next<='9'){
				num = num*10 + (next-'0');
				i++;
				next = arr[i];
			}
			n_push(num);
		} else if(next==')'){
			i++;
			top = o_pop();
			while(top!='('){
				n1 = n_pop();	
				n2 = n_pop();
				answer = execute(top, n1, n2);
				n_push(answer);
				top = o_pop();
			}
		} else if(!(next>='0' && next<='9')){
			if(next!='x') i++;
			top = o_pop();
			//printf("\ntop-%c, next-%c\n", top, next);
			if(opriority(next) <= ipriority(top)){
				//Execute(top)
				if(top=='#') break;
				n1 = n_pop();
				n2 = n_pop();
				answer = execute(top, n1, n2);
				n_push(answer);
				if(next!='x') o_push(next);
			} else {
				o_push(top);
				if(next!='x') o_push(next);
				if(next=='x' && top=='#') break;
			}
		}
				//printf("\n%s,,top:%c, next:%c, opriority(next):%d, ipriority(top):%d\n", arr,top, next, opriority(next), ipriority(top));x++;
	}	
	printf("\n\nValue of the expression is: %d\n\n", answer);
	
	return 0;
}
