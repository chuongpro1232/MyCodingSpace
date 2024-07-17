
#if 0 ////members in our group could not agree on 1 style of coding, each code in a different way. So we have trouble in combine our code, this lead to some part like this file neglected
#ifndef __DATE_H__
#define __DATE_H__
/* make sure that this file will be included only once in compilation process
   (when the keyword __USER_H__ is not defined before)
*/
#include <iostream>
#include<string>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

public: 
  	Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

	  void setDate(int day, int month, int year);

	  int getDay();

	  void setDay(int day);

	  int getMonth();

	  void setMonth(int month);

	  int getYear();

	  void setYear(int year);

	  void display();

	  string toString();
	  
      friend class House;
	  friend class System;
};

#endif
#endif