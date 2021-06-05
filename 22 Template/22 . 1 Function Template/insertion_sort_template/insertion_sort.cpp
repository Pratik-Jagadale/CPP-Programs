//////////////////////////////////////////
///insertion sort : template 
/////////////////////////////////////////
#include <cstdio>
#include <iostream>

class Date{
private:
	int day, month, year;

public:
	Date(int DAY = 0,int MONTH = 0, int YEAR = 0):day(DAY),month(MONTH),year(MONTH){

	}

	Date& operator =(const Date& other){
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}

	bool operator>(const Date& other){
		if(this->year > other.year)
		{
			return true;
		}
		else if(this->year < other.year)
		{
			return false;
		}
		else if(this->month > other.month)
		{
			return true;
		}
		else if(this->month < other.month)
		{
			return false;
		}
		else if(this->day > other.day)
		{
			return true;
		}
		else
			return false;	
		
	}
	friend std::ostream& operator<<(std::ostream& os, const Date& other);

};

std::ostream& operator<<(std::ostream& os, const Date& other)
{
	os << other.day << "-" << other.month << "-" << other.year <<std::endl;
	return os;
}

template <typename T>
T* Sort(T* Array, int size){
	if (size == 0)
	{
		printf("Array is Empty\n");
		return (reinterpret_cast<T*>(NULL) );
	}

	int i, j;
	T key;

	for(i = 0 ; i < size ; i++){
		key = Array[i];	                //assignment operatot overload 
		j = i - 1;

		while(j >= 0 && Array[j] > key){ // > operator overload
			Array[j + 1] = Array[j]; 		// assignmenet opertor overload	
			j--;
		}
		Array[j+1]= key;                   //assignemet operator overload
	}
	return Array;
}

template <typename T>
void show(T* Arr, int size,char* msg){
	
	puts(msg);
	for(int i =0 ; i < size ; i++){
		std::cout << "i[" << i << "]:" << Arr[i] << std::endl;
	}
}

int main(){

	int Arr[5] = { 5, 1, 3, 2, 4};
	float f_Arr[5] = {1.9 ,1.4 ,1.3 ,1.6 ,1.1};
	Date date_arr[5] = {
								Date(11, 1, 2021),
								Date(11, 5, 2021), 
								Date(11, 2, 2020),
								Date(10, 2, 2020), 
								Date(1, 1, 1970) 
							}; 

	show<int>(Arr,5,"integer Array before Sort :");
	show<float>(f_Arr,5,"float array before sort");

	Sort<int>(Arr,5);
	Sort<float>(f_Arr,5);

	show<int>(Arr,5,"integer Array After Sort :");
	show<float>(f_Arr,5,"float array After sort");



	show(date_arr, 5, "Date Array:Before sort:"); 
	Sort(date_arr, 5); 
	show(date_arr, 5, "Date Array:After sort:"); 
	return 0;
}
