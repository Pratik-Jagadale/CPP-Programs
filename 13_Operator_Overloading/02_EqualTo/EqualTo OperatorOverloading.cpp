//Equal to Operator Overloading

#include <cstdio>

class vector2d{
	private: 
		double x,y; 

	public: 
		vector2d(double init_x = 0.0, double init_y = 0.0) : x(init_x), y(init_y) {}

		bool operator==(const vector2d& other){
			return (this->x == other.x && this->y == other.y); 
		}	
}; 

int main(){
	vector2d pvec1(1.1,2.2); 
	vector2d pvec2(1.1,2.2); 

	if(pvec1 == pvec2){
		printf("Equal\n"); 
	}else{
		printf("Unequal\n"); 
	}

	return (0); 
}
