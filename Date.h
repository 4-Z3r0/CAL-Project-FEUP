#pragma once
#include <string>

using namespace std;

//Imported from my Old AEDA project avaiable at https://github.com/AntoniooCruz/AEDA_Project-/blob/master/Date.h
class Date {
	unsigned int year, month, day;

public:
	Date();
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(const Date &d);
	Date(string date);
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	virtual string getDate() const;
	static Date getNow();
	string to_DateString(unsigned int date) const;
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	static bool past(unsigned int year, unsigned int month, unsigned int day);
	float operator-(const Date &d2) const;
	Date operator+ (int days) const;
	virtual bool operator<(const Date &d) const;
	virtual bool operator==(const Date &d) const;
	friend ostream &operator<<(ostream &os, const Date &d);

};
