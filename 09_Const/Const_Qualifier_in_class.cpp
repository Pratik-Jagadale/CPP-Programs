#include <cstdio> 
#include <cstdlib> 

class Test1{
		private: 
				const int n; 
				int m; 
				static const int p; 
		public: 
				Test1(int init_n, int init_m) : n(init_n){
					// n = init_n;  //CTE
					m = init_m; 
				}

				void modify(){
					m = 500; 
					// n = 1000; 	// CTE 
				}
}; 

class Test2{
private: 
	int n1; 
	int n2; 
public: 
	Test2(int init_n1, int init_n2) : n1(init_n1), n2(init_n2) { }
	
	int get_n1() const {
		// n2 = 300; 	// CTE
		return n1; 
	}

	int get_n2() const {
		return n2; 
	}

	void set_n1(int new_n1){
		n1 = new_n1; 
	}

	void set_n2(int new_n2){
		n2 = new_n2; 
	}
}; 

// const int Test1::p;  // CTE

const int Test1::p = 0; 	// Ok. Correct

int main(){
	int n1,n2;
	Test1 t1(100, 200); 
	Test2 t2(100, 200); 
	Test2 *pT2 = &t2; 

	n1 = pT2->get_n1(); 
	n2 = pT2->get_n2(); 
	printf("n1 = %d  , n2 = %d\n",n1,n2);


	pT2->set_n1(31); 
	pT2->set_n2(1999); 


	n1 = pT2->get_n1(); 
	n2 = pT2->get_n2(); 
	printf("n1 = %d  , n2 = %d\n",n1,n2);

	
	return 0; 
}
