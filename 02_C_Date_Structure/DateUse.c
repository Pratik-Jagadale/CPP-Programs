#include<stdio.h>
#include"Date.h"

int main(){
    int Day, Month, Year;

    struct Date* p_Date = NULL;
    p_Date = CreateDate(31,10,1999);

    Day = GetDay(p_Date);
    Month = GetMonth(p_Date);
    Year = GetYear(p_Date);
    printf("%d - %d - %d \n",Day, Month, Year);

    SetDay(p_Date, 01);
    SetMonth(p_Date, 04);
    SetYear(p_Date, 2021);

    Day = GetDay(p_Date);
    Month = GetMonth(p_Date);
    Year = GetYear(p_Date);
    printf("%d - %d - %d \n",Day, Month, Year);

    DestroyDate(p_Date);
    p_Date = NULL;

    return (0);
}
