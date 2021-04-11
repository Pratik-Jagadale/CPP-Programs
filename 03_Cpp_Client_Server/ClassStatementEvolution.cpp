#include <cstdio>
#include <cstdlib>

class Date{
private:
	int day;
	int month;
	int year;
public:
	Date(int iday, int imonth, int iyear): day(iday), month(imonth), year(iyear){

	}

	int get_day(){
		return(this->day);
	}

	int get_month(){
		return(this->month);
	}

	int get_year(){
		return(this->year);
	}

	void set_day(int new_day){
		this->month = new_day;
	}

	void set_month(int new_month){
		this->month = new_month;
	}

	void set_year(int new_year){
		this->year = new_year;
	}
};

int main(void){
	Date* p_date = new Date(1, 1 , 2020);

	int day , month , year;
	day = p_date->get_day();
	month = p_date->get_month();
	year = p_date->get_year();

	printf("%d - %d - %d\n",day, month, year);
	p_date->set_day(31);
	p_date->set_month(10);
	p_date->set_year(1999);

	day = p_date->get_day();
	month = p_date->get_month();
	year = p_date->get_year();

	printf("%d - %d - %d\n",day, month, year);

	delete p_date;
	p_date = NULL;
	return (0);
}
