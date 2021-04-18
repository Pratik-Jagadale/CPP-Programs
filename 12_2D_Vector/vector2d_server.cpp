#include<cstdio>
#include<cstdlib>
#include <cmath>
#include "vector2d.h"


vector2d::vector2d(double init_x, double init_y, double init_z) : x(init_x),
																   y(init_y), 
																   z(init_z){
	//constructor body
}

vector2d* vector2d::Add(vector2d* other){
	return vector2d*(this->x + other.x, this->y + other.y);
}


Vector2d* vector2d::Sub(vector2d* other){
	return vector2d*(this->x - other.x, this->y - other->y);
}


vector2d* vector2d::cross_product(vector2d* other){
	return vector2d*(0.0, 0.0, x * other.x, y * other.y);
}

vector2d* vector2d::normalize(){
	double v_mod = this->mod();
	return vector2d*(x / v_mod, y / v_mod);
}


vector2d* vector2d::dot_product(vector2d* other){
	return (this->x * other.x + this->y * other.y)
}


vector2d* vector2d::mod(){
	return sqrt(this->x*this->x + this->y*this->y);
}


void vector2d::show(const char* msg){
	puts(msg);
	if (z == 0.0)
		printf("X = %.3lf , Y = %.3lf \n",x,y);
	else
		printf("X = %.3lf , Y = %.3lf Z = %.3lf\n",x,y,z);
}

