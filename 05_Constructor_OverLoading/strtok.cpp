#include <cstdio>
#include <cstring> //for strtok
#include <cstdlib> //for atoi function

int main()
{
	char date[] = "31-10-1999";
	int day, month, year;

	char* sep =(char*)"-";
	char* token = NULL;;

	token = strtok(date, sep);
	day = atoi(token);

	token = strtok(NULL, sep);
	month = atoi(token);

	token = strtok(NULL, sep);
	year = atoi(token);


	printf("%d\n%d\n%d \n",day,month,year);


	sep = NULL;
	token = NULL;
	return 0;
}


/* 
	strtok 
	Split string into tokens
A sequence of calls to this function split str into tokens, which are sequences of contiguous characters separated by any of the characters that are part of delimiters.

On a first call, the function expects a C string as argument for str, whose first character is used as the starting location to scan for tokens. In subsequent calls, the function expects a null pointer and uses the position right after the end of the last token as the new starting location for scanning.

To determine the beginning and the end of a token, the function first scans from the starting location for the first character not contained in delimiters (which becomes the beginning of the token). And then scans starting from this beginning of the token for the first character contained in delimiters, which becomes the end of the token. The scan also stops if the terminating null character is found.

This end of the token is automatically replaced by a null-character, and the beginning of the token is returned by the function.

Once the terminating null character of str is found in a call to strtok, all subsequent calls to this function (with a null pointer as the first argument) return a null pointer.

The point where the last token was found is kept internally by the function to be used on the next call (particular library implementations are not required to avoid data races).
*/


/*  atoi 
	Convert string to integer
Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.

The function first discards as many whitespace characters (as in isspace) as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed and zero is returned.

	*/