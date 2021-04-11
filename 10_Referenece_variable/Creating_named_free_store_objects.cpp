#include <cstdio>

class Date{
private:
	int day, month, year;

public:
	Date(int init_day, int init_month, int init_year):day(init_day), 
													  month(init_month), 
													  year(init_year)
	{

	}

	Date() :day(31), month(5),  year(2020)
	{

	}

	void show(){
		printf("%d-%d-%d\n",day, month, year);
	}
};

Date& allocate_date_object(int day, int month, int year);

int main(){
	Date* p_date = new Date;
	p_date->show();
	delete(p_date);
	p_date	= 0;

	Date* p_today= new Date(11,04,2021);
	Date& ref_today = *p_today;
	ref_today.show();
	delete &ref_today;
	p_today =0;

	Date& today = allocate_date_object(11, 04, 2021);
	Date& birthday = allocate_date_object(31, 10, 199);

	today.show();
	birthday.show();

	delete &today;
	delete &birthday;

	return (0);
}

Date& allocate_date_object(int day, int month, int year){
	Date* p_date = new Date(day, month, year);

	return *p_date;
}
