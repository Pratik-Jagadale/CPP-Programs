#include <cstdio>

static int num3 = 100;      /* DATA section*/
static int num4 ;		   /* BSS */

void test_function(void);

int main(){

	test_function();
	test_function();
	return 0;
}

void test_function(void){
	static int num = 100;	/*Data*/  /*num is 
							static local date member then its allocation 
							time is static and through out the program*/
	static int num1 ;
	int i;
	for(i = 0 ; i < 50 ; ++i)
		++num;

	printf("num = %d \n",num);

}
