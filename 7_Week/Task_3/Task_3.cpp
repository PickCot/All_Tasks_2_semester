#include <iostream>
#include <time.h>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};
bool isLeap(int);
Date today(void);
int numberOfDays(Date, Date);
int monthLength(int year, int month);

int main()
{
    Date today1 = today();
    time_t t = time(NULL);
    tm tl = *localtime(&t);

    cout << today1.year << "\n";
    cout << today1.month << "\n";
    cout << today1.day << "\n";

    Date myBDay;
    cout << "Enter your BD date via Enter key in format YYYY M D: \n";
    cin >> myBDay.year >> myBDay.month >> myBDay.day;
    cout << numberOfDays(myBDay, today1);

}

Date today()
{
    Date today;
    time_t t = time(NULL);
    tm tl = *localtime(&t);

    today.year = tl.tm_year + 1900;
    today.month = tl.tm_mon + 1;
    today.day = tl.tm_mday;
    return today;
}
bool isLeap(int year) {
    return year % 4;
}
int numberOfDays(Date bdate, Date today)
{
    int sum = 0;

    for (int i = bdate.year; i < today.year; i++)
    {
        if (isLeap(i))
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }

    }
    if (today.month - bdate.month < 0)
    {
        for (int i = today.month; i < bdate.month; i++)
        {
            sum -= monthLength(today.year, i);
        }
    }
    else
    {
        for (int i = bdate.month; i < today.month; i++)
        {
            sum += monthLength(today.year, i);
        }
    }

    sum += today.day - bdate.day;
    return sum;
}
int monthLength(int year, int month)
{
    switch (month)
    {
    case 1:
        if (isLeap(year))
        {
            return 30;
        }
        else
        {
            return 31;
        }
        break;
    case 2:
        if (isLeap(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10:return 31;
    case 11:return 30;
    case 12:return 31;
    }
}