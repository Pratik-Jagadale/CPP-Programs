#include <cstdio>

class vector2d{
	private: 
		double x,y; 

	public: 
		vector2d(double init_x = 0.0, double init_y = 0.0) : x(init_x), y(init_y) {}

		bool operator==(const vector2d* p_other){
			return (this->x == p_other->x && this->y == p_other->y); 
		}	
}; 

int main(){
	vector2d* pvec1 = new vector2d(1.1,2.2); 
	vector2d* pvec2 = new vector2d(1.1,2.2); 

	// equality is defined for pointer type 
	// therefore, operator overloading will not come 
	// into picture 
	// as pointers are unequal, "Unequal" will be the output 
	if(pvec1 == pvec2){
		printf("Equal\n"); 
	}else{
		printf("Unequal\n"); 
	}

	delete pvec1; 
	pvec1 = 0; 

	delete pvec2; 
	pvec2 = 0; 

	return (0); 

}