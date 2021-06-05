#include <cstdio>

template <typename T>
T max(T *Arr,int size){

	int i = 0;
	if(Arr[i] == '\0'){
		printf("Empty Array\n");
	}
	T ret = 0;
	for(i = 0; i < size ; i++){

		if(Arr[i] > ret){
			ret = Arr[i];
		}
	}
	return (ret);
}

int main(){
	int i,size = 5;
	int arr[5]= { 2 , 25 ,622 ,852 , 144};
	float f_arr[5] = {2.4, 3.5, 3.7, 3.8, 3.9};
	
	int i_max = ::max(arr, size);
	float f_max = ::max(f_arr, size);
	printf("i_max = %d , f_max = %f\n",i_max, f_max);

	//these also work because of template argument deduction
	//also we can give template argument when some time there is
	//two types of parmeters then we need to write type of argument
	//also we can use type castig here ,when you dont wont to user
	//typr argument   


	i_max = ::max<int>(arr, size);
	f_max = ::max<float>(f_arr, size);
	printf("i_max = %d    ,   f_max = %f\n",i_max, f_max);
}