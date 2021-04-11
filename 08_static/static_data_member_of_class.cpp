#include<cstdio>

class Test{
private:
	static int n;
	int x;

public:
	Test():x(100){

	}	

	int get_n(){
		x = 500;
		return n;
	}

	static int getn_static(){
		//x = 500 //compile time error
		return (n);
	}

};

int Test::n = 200;
Test t;

int main(){
	printf("n = (%d) \n",Test::getn_static() );
	printf("n = (%d) \n",t.get_n() );

	return (0); 
}
