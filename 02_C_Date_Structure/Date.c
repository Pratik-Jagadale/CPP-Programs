#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

struct Date* CreateDate(int day,int month, int year){
        struct Date* p_Date = NULL;
        p_Date = (struct Date*)malloc(sizeof(struct Date));

       if(p_Date == NULL){
            printf("Memory Allocation Failed");
            return NULL;
        }
        memset(p_Date, 0, sizeof(struct Date)); //structure intailization #memset aat madhe pratek variable la "0" la assigne kar ass apan sanagto
        p_Date->Day = day;
        p_Date->Month = month;
        p_Date->Year = year;
s
        return(p_Date);
}

void DestroyDate(struct Date* p_Date){
    free(p_Date);
}

int GetDay(struct Date* p_Date){
    return(p_Date->Day);
}

int GetMonth(struct Date* p_Date){
    return(p_Date->Month);
}

int GetYear(struct Date* p_Date){
    return(p_Date->Year);
}

void SetDay(struct Date* p_Date,int newDay){
    p_Date->Day = newDay;
}

void SetMonth(struct Date* p_Date, int newMonth){
    p_Date->Month = newMonth;
}

void SetYear(struct Date* p_Date, int newYear){
    p_Date->Year = newYear;
}
