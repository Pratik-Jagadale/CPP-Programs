#pragma once

class vector2d{ 
private:
	double x, y, z;
public:
	vector2d(double init_x, double init_y, double init_z = 0.0);
	
	vector2d* Add(vector2d* other);
	
	vector2d* Sub(vector2d* other);
	
	vector2d* cross_product(vector2d* other);
	
	vector2d* normalize();
	
	vector2d* dot_product(vector2d* other);
	
	vector2d* mod();
	
	void show(const char* msg);
};
