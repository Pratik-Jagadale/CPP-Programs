#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

void ceration(void);
void member_function(void);
void element_access(void);
void iterator_operation(void);
void Capacity(void);
void modifiers(void);
void relational_op(void);

template <typename T>
void print_vector_by_index(std::vector<T>& v,const char* msg)
{
	std::cout<<msg <<std::endl;
	for (std::vector<T>::iterator iter = v.begin() ; iter != v.end() -1 ; ++iter)
			std::cout <<"iter :" <<*iter <<std::endl;
	std::cout<<"----------END--------------" <<std::endl;
}

int main(){

	ceration();
	member_function();
	element_access();
	iterator_operation();
	Capacity();
	modifiers();
	relational_op();

	return 0;
}

template <typename T>
class point3d
{
public:
	T x,y,z;
	point3d():x(0),y(0),z(0)
	{

	}

	point3d(T X,T Y,T Z):x(X),y(Y),z(Z)
	{

	}
};

void ceration(void)
{
	std::vector<int> i_vec;
	print_vector_by_index<int>(i_vec , " i_vec :");

	std::vector<int> i_vec1{10,20,30,40,50};
	print_vector_by_index<int>(i_vec1 , "std::vector<int> i_vec1 :");

	std::vector<int> i_vec2(i_vec1);
	print_vector_by_index<int>(i_vec2 , "std::vector<int> i_vec2 :");

	std::vector<char> c_vec{'a','b','c','d'};
	print_vector_by_index<char>(c_vec , "char vector : c_vec :");

	//std::std::vector<point3d> v_p3d({ 1, 2, 3},
	//								{ 3, 3, 6}, 
	//								{ 6, 5, 12});
	//print_vector_by_index<point3d>(v_p3d , "vector point 3d :");

}

void member_function(void)
{

}
void element_access(void)
{

}
void iterator_operation(void)
{

}
void Capacity(void){

}

void modifiers(void)
{

}
void relational_op(void){

}
