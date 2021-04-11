#include<cstdio>
#include<cstdlib>

class Test{
private:
	char c;
	int n;
	float f;

public:
	Test(char init_c,int init_n,float init_f) : c(init_c), n(init_c), f(init_f) {

	}	

	int get_n(){
		return n;
	}
	void set_n(int new_n){
		n= new_n;
	}

	static int compute(int n1, int n2, int n3){
		return (n1 + n2 + n3);
	}

};

Test t('A', 100, 2.14f);

int main(){
	int result;

	t.get_n();
	t.set_n(200);

	result = Test::compute(10, 20, 30);
	printf("result = (%d) \n",result);
	result = t.compute(11, 12, 13);
	printf("result = (%d) \n",result);

	return (0); 
}
//because of function is qualified by static keyword we can acccessed function by using 
//class name or object name static function creates on static time 