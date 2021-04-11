#include<stdio.h>
int day,month,year;
class Date{

// [1] Default Constructor

	Addition(){
		//body
	}
	
//[2] Default Constructor with initializer list
	
	Addition():day(31),month(10),year(1999){
		//body
	}
	
//[3] Default Constructor with Assingment
	
	Date(){
	  day = 31;
	  month = 10;
	  year = 1999;
	}

//[4] Default Constructor with initializer list & Assingment
	
	Date():day(31)
	{
	  month = 10;
	  year = 1999;
	}	


//[5]Parameterised Constructor
	
	Date(int DAY,int MONTH,int YEAR){
	}


//[6] Parameterised Constructor with initailizer list
	
	Date(int DAY,int MONTH,int YEAR):day(DAY),month(MONTH),year(YEAR){
	}

//[7] Paramerterised Constructor with assigment
	
	Date(int DAY,int MONTH, int YEAR){
	  day = DAY;
	  month = MONTH;
	  year = YEAR;
	}

//[8] Parameterised Constructor with initializer list & Assingment
	
	Date(int DAY,int MONTH,int YEAR):day(DAY)
	{
	  month = MONTH;
	  year = YEAR;
	}	
}

int main(){
	day = 0;
	month = 0l;
	year = 0;l
	//All Constructor call
retrun 0;
}