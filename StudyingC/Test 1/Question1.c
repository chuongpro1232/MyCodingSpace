
/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2022A
  Lab Assessment: 1
  Author: Tran Thanh Tu
  ID: 3957386
  Compiler used: Compiler version 8.1.0
  Created  date: 25/03/2022
  Acknowledgement: None
*/

#include <stdio.h>

int main()
{
  int hour, day_hour, intday;
  float day;
  printf("Enter total hours: ");
  scanf("%d", &hour);

  day = hour / 24.0;
  intday = hour / 24.0;
  day_hour = hour % 24;

  printf("\nIt's %f days", day);
  printf("\nwhich is %d days and %d hours", intday, day_hour);

  return 0;
}