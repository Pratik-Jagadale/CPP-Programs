#include <cstdio>

class Demo{
private:
	int n1;
	int n2;
	mutable int n3;

public:
	Demo():n1(100), n2(200){}

	int get_n1() const{
		//n1 = 200; //CTE because get_n1 is const function member 
		const_cast<Demo*>(this)->n1 = 400;
		//n3 is qualified by mutable hence we can assigment on direct n3
		//we dont need to use const cast for assignment in const function

		n3 = 400l;
		return 0; 
	}

};

int main(){
	Demo D1;

	return 0;
}
