/*
	Opertor Overloading by returniung pointer of new alloacted 
	object of result.
*/
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

	//Alloacte using new and return by reference
	vector2d* operator+(vector2d other){
		vector2d* p_pvec = new vector2d(x + other.x , y + other.y);
	    return p_pvec;
	}

	vector2d* operator-(vector2d other){
		vector2d* p_pvec = new vector2d(x - other.x , y - other.y);
		return p_pvec;
	}

	vector2d* operator*(vector2d other){
		vector2d* p_pvec = new vector2d(x * other.x , y * other.y);
	    return p_pvec;
	}

	vector2d* operator/(vector2d other){
		vector2d* p_pvec = new vector2d(x / other.x , y / other.y);
		return p_pvec;
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

	vector2d*  v_sum = obj1 + obj2;
	v_sum->show("Summation : "); 

    v_sum = obj1 - obj2;
	v_sum->show("Substraction : ");

	v_sum= obj1 * obj2;
	v_sum->show("Cross Product : ");

	v_sum = obj1 / obj2;
	v_sum->show("Division : ");
	delete &v_sum; //delete object created in operator obrloading function 
				   //by using a a reference of that object.
	
	v_sum = 0;
	return 0;
}
