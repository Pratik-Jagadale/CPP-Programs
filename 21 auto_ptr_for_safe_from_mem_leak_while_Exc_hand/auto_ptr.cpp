#include<cstdio>
#include<cassert>
//#include <unistd.h>
#include<stdexcept>
#include<memory>

class T{

	private:
		int a;
		char b;
		float c;
		int* p;

	public:
		T():a(100),b('A'),c(3.14f), p(new int(500)){
		}

		~T(){
			printf("destructor of T:p = %p\n", p);
			delete p;
		}
};

void f(void);
void g(void);

void h(void);

int main(){

	std::auto_ptr<T> pT(new T); //it will destroy automatically

	h();

	try{
		f();
	}catch(std::runtime_error& e){

	}

	while(1){
		puts("gonna do work for 1 hr");
		//sleep(1);
	}

	return (0);
}

void f(void){
	std::auto_ptr<T>pT(new T);

	g();
	for(int i = 0 ; i < 10000000 ; i++){
		puts("hi");
	}

}

void g(void){
	throw std::runtime_error("Exception triggered");
}

void h(void){
	std::auto_ptr<T>pT(new T);

	puts("returning from h()");
}