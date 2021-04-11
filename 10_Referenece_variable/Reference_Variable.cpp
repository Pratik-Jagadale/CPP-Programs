#include<cstdio>
#include<cstdlib>

int swap1(int*, int*);  
int swap2(int&, int&);
void show(int num1,int num2,char* string);

int main(){
	int n = 10;
	int& n_ref = n; // new aliase for varible n (m is reference varibale for n)
	printf("n : %d & n_ref : %d\n",n,n_ref);

	int i=200, j=100;
	
	show(i,j,"before swap1\n");
	swap1(&i,&j);
	show(i,j,"After swap1 \n");
	
	show(i,j,"Before swap2 \n");
	swap2(i,j);
	show(i,j,"After swap2 \n");
	
	return(0);
}

int swap1(int* num1,int* num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return(0);
}

int swap2(int& num1,int& num2){
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
	return (0);
}

void show(int num1,int num2,char* string){
	puts(string);
	printf("i : %d\n",num1);
	printf("j : %d\n\n",num2);
	return ;
}
