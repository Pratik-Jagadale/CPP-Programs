#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

class Date{
	private:
		int day,month,year;
	public:	
		Date(){
			time_t t_current;
			struct tm* p_tm = NULL;
			t_current = time(0);
			p_tm = gmtime(&t_current);
			day = p_tm->tm_mday;
			month = p_tm->tm_mon;
			year = p_tm->tm_year + 1900;
		}

		Date(int iday,int imonth,int iyear){
			day = iday;
			month = imonth;
			year = iyear;
		}

		Date(char* date_str){
			const char* sep =(char*)"/";
			char* token = NULL;
	
			token = strtok(date_str, sep);
			day = atoi(token);
	
			token = strtok(NULL, sep);
			month = atoi(token);
		
			token = strtok(NULL, sep);
			year = atoi(token); 
		}

		void show(){
			printf("%d - %d - %d\n",day, month, year);
		}

};

int main(){
	char date_str[] = "01/6/2020";

	Date D1;
	Date D2(31,10,1999);
	Date D3(date_str);

	D1.show();
	D2.show();
	D3.show();

	return (0);
}
