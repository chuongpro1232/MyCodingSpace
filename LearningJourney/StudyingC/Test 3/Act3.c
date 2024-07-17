/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 3
  Author: Tran Thanh Tu
  ID: 3957386
  Compiler used: 8.1.0
  Created  date: 20/5/2022
  Acknowledgement: None
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    char month;
    int year;

} date;

int main()
{
    enum months
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };
    date d1, d2, d3;
    printf("Enter Day:");
    scanf("%d:%s:%d", &d1.day, &d1.month, &d1.year);
    printf("Enter Day:");
    scanf("%d:%s:%d", &d2.day, &d2.month, &d2.year);
    printf("Enter Day:");
    scanf("%d:%s:%d", &d3.day, &d3.month, &d3.year);
}
