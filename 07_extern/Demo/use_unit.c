extern void cpa_sort(int* a, int n); 

int main(){
	int a[] = {10, 9, 8, 7, 6}; 
	cpa_sort(a, 5); 
	return (0); 
}

/* Why compiler will not emit a warning in the absence of keyword extern? 
 * because function definition and function declaration are distinguishable 
 * despite the absebce of extern! 
 *
 * But data definition and data declaration are not distinguishable in the absence 
 * of extern. Rather to aggrevate the scenario, dropping extern in data declaration 
 * statement makes it data definition statement 
 *
 * This is not the case with function. Dropping extern from function declaration 
 * will still be be a function declaration */ 

