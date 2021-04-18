#include "vector2d.h"

int main(){
	vector2d* obj1 = new vector2d(100,200);
	vector2d* obj2 = new vector2d(400,500);
	
	obj1->Add(obj2);
	obj1->show("vector sum");

	obj1->Sub(obj2);
	obj1->show("vector sub");

	obj1->cross_product(obj2);
	obj1->show("cross product");

	obj1->normalize(obj2);
	obj1->show("normalize");
	
	obj1->dot_product(obj2);
	obj1->show("dot product");

	delete(obj1);
	delete(obj2);
	obj1 = 0;
	obj2 = 0;
	
	return 0;
}

