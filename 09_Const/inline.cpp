#include <cstdio>

class T{
	private: 
			int n; 
	public: 
			T() : n(100) {} 
			inline int get() const {
				return (n); 
			}//result we can see in assmbly language
}; 


T t; 

int main(){

	int k = t.get(); 
	printf("k = %d\n", k); 

	return (0); 
}
