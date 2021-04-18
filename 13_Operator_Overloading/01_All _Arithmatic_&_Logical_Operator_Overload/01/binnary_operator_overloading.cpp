#include <cstdio>
#include <cstdlib>

class vector2d{
private:
	double x, y;
	
public:
	vector2d(double init_x,double init_y): x(init_x), 
									       y(init_y)
	{
	
	}

	vector2d operator+(vector2d& other){
	return vector2d(x + other.x , y + other.y);
	}

	vector2d operator-(vector2d& other){
	return vector2d(x - other.x , y - other.y);
	}

	vector2d operator*(vector2d& other){
	return vector2d(x * other.x , y * other.y);
	}

	vector2d operator/(vector2d& other){
	return vector2d(x / other.x , y / other.y);
	}

	void show(const char* Arr)const{
		puts(Arr);
		printf(" X = %.3lf , Y = %.3lf \n",x,y);
	}
};

int main(){
	vector2d obj1(32.3,6.33);
	obj1.show("object one :");
	vector2d obj2(12,3.2);
	obj2.show("object Two :");

	vector2d  obj_res = obj1 + obj2;
	obj_res.show("Summation : ");

    obj_res = obj1 - obj2;
	obj_res.show("Substraction : ");

	obj_res = obj1 * obj2;
	obj_res.show("Cross Product : ");

	obj_res = obj1 / obj2;
	obj_res.show("Division : ");

	return 0;
}

