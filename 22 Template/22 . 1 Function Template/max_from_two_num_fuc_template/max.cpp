#include <cstdio>

template <typename T>
T max(T num1 , T num2){
	if(num1 < num2)
		return num2;
	return num1;
} 

int main(){
	int n1 = 12 , n2 = 30;
	float f1 = 1.2 , f2 = 36.1;

	int i_ret = ::max(n1,n2);
	float f_ret = ::max(f1,f2);

	printf("intger max : %d ",i_ret);
	printf("float max : %f\n",f_ret);

	return 0;
}
