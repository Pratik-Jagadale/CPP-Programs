/*when we first compile use_unit.c and then def_unit.c then some compiler 
gives us error(compile time error) beacuse data member num and test_funtion() 
are used before decl ,compile needs only date type of that used data member or 
member function then use extern keyword   
*/
#include <stdio.h>
extern int num;
extern void test_function(void);

int main(){
	int tmp;
	tmp = num - 10;    /*tmp will be 90 */
	printf("%d\n",tmp);

	test_function(); //use before declartion hence we declaring function type using extern key word
	
	return(0);
}
