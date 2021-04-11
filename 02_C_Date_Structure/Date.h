#ifndef _DATE_H
#define _DATE_H

struct Date{
    int Day;
    int Month;
    int Year;
};

struct Date* CreateDate(int day,int month, int year);

void DestroyDate(struct Date* p_Date);

int GetDay(struct Date* p_Date);

int GetMonth(struct Date* p_Date);

int GetYear(struct Date* p_Date);

void SetDay(struct Date* p_Date,int newDay);

void SetMonth(struct Date* p_Date, int newMonth);

void SetYear(struct Date* p_Date, int newYear);

#endif 