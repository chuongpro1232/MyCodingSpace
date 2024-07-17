
#if 0 ////members in our group could not agree on 1 style of coding, each code in a different way. So we have trouble in combine our code, this lead to some part like this file neglected
#include<iostream>
#include<string>
#include "Date.h"
#include <sstream>
using namespace std;








	  void Date :: setDate(int day, int month, int year) {
		  this->day = day;
		  this->month = month;
		  this->year = year;
	  }

	  int Date :: getDay() {
		  return day;
	  }

	  void Date :: setDay(int day) {
		  this->day = day;
	  }

	  int Date :: getMonth() {
		  return month;
	  }

	  void Date :: setMonth(int month) {
		  this->month = month;
	  }

	  int Date :: getYear() {
		  return year;
	  }

	  void Date :: setYear(int year) {
		  this->year = year;
	  }

	  void Date :: display() {
		  string day = to_string(this->day);
		  string month = to_string(this->month);
		  string year = to_string(this->year);
		  if (day.length() == 1) {
			  day = "0" + day;
		  }
		  if (month.length() == 1) {
			  month = "0" + month;
		  }
		  cout << day + "/" + month + "/" + year << endl;
	  }
	string Date :: toString() {
        std::stringstream info;
          string day = to_string(this->day);
		  string month = to_string(this->month);
		  string year = to_string(this->year);
		  if (day.length() == 1) {
			  day = "0" + day;
		  }
		  if (month.length() == 1) {
			  month = "0" + month;
		  }
          info << day << "/" + month << "/" << year;
		  return info.str();
          
      }
#endif