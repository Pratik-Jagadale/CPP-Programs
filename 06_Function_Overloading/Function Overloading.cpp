#include<stdio.h>
#include<stdlib.h>

class sort{
private:
//
public:

    sort()
    {

    }

	void sort(int* Arr,size_t n){
		int i, j, key;

		for(j = 1 ; j < n ; ++j){
			key	= a[j];
			i = j - 1;
			while(i > -1 ; && Arr[i] > key){
				Arr[i+1] = Arr[i];
				i--;
			}
			a[i+1] = key;
		}
	}

	void sort(double* Arr,size_t n){
		int i, j, key;
		
		for(j = 1 ; j < n ; ++j){
			key = a[j];
			i = j - 1;
			while(i > -1 && Arr[i] > key){
				Arr[i+1] = Arr[i];
				i--;
			} 
			Arr[i+1] = key;
		}
	}

	void show(int* Arr, size_t n, char* msg){
		puts(msg);
		for(int i = 0 ; i < n ; i++){
			pritnf("Arr[%d] : %d \n",i,Arr[i]);
		}
	}

	void show(double* Arr,size_t n,char* msg){
		puts(msg);
		for(int i = 0 ; i < n ; i++){
			pritnf("Arr[%d] : %lf \n", i, Arr[i]);
		}
	}


};

int main(){

	int Array[10] = {152, 25, 96, 452, 652, 32, 52, 47, 82, 863};
	double d_Array[10] = {1.2, 1.6, 1.7, 1.8, 1.9, 1.4, 1.5, 1.1, 1.3 , 1.0};

	sort* obj_sort = new sort();

	obj_sort->show(Array, 10, "Before sort");
	obj_sort->sort(Array, 10);
	obj_sort->show(Array, 10, "After sort");


	obj_sort->show(b_Array, 10, "Before sort");
	obj_sort->sort(b_Array, 10);
	obj_sort->show(b_Array, 10, "After sort");

	delete (obj_sort);
	obj_sort = NULL;
	return (0);
}
