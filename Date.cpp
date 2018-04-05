
#include <sstream>
#include "Date.h"
#include <time.h>
#include <ctime>

Date::Date() {
	this->year = 2017;
	this->month = 1;
	this->day = 1;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return;
}

Date::Date(const Date &d) {
	this->year = d.getYear();
	this->month = d.getMonth();
	this->day = d.getDay();
}

Date::Date(string date) {
	istringstream dateStream(date);
	char aux;

	dateStream >> year >> aux >> month >> aux >> day;

	if (1 < month || month > 12 || 1 < day || day > 31)
		return;

}

/* get methods */
unsigned int Date::getYear() const {
	return year;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getDay() const {
	return day;
}

string Date::getDate() const {
	string syear;

	if (year < 100)
		syear = "19" + to_string(year);
	else
		syear = to_string(year);

	return (syear + "/" + to_DateString(month) + "/" + to_DateString(day));
}

Date Date::getNow() {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	return Date(now->tm_year + 1900, (now->tm_mon + 1), now->tm_mday);
}

string Date::to_DateString(unsigned int date) const {
	if (date < 10)
		return ("0" + to_string(date));

	return to_string(date);

}


/* set methods */
void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return;

	this->year = year;
	this->month = month;
	this->day = day;


}

void Date::setYear(unsigned int year) {
	this->year = year;
}

void Date::setMonth(unsigned int month) {
	if (month < 1 || month > 12)
		return;

	this->month = month;
}

void Date::setDay(unsigned int day) {
	if (day < 1 || day > 31)
		return;

	this->day = day;
}

bool Date::past(unsigned int year, unsigned int month, unsigned int day) {
	time_t t = time(0);
	struct tm * now = localtime(&t);

	if (year == now->tm_year + 1900) {

		if (month == now->tm_mon + 1) {

			return (day < now->tm_mday);
		}
		return (month < now->tm_mon + 1);
	}
	return (year < now->tm_year + 1900);
}

bool Date::operator< (const Date &d) const {
	if (getYear() == d.getYear()) {

		if (getMonth() == d.getMonth()) {

			return getDay() < d.getDay();
		}
		else {
			return getMonth() < d.getMonth();
		}
	}
	else {
		return getYear() < d.getYear();
	}
}

bool Date::operator== (const Date &d) const {
	return (getYear() == d.getYear() && getMonth() == d.getMonth() && getDay() == d.getDay());
}

Date Date::operator+(int days) const {
	unsigned int eDay = getDay() + days, eMon = getMonth(), eYea = getYear();


	if (eDay > 30) {
		eMon = eMon + eDay / 30;
		eDay = eDay % 30;
	}

	if (eMon > 12) {
		eYea = eYea + eMon / 12;
		eMon = eMon % 12;
	}

	Date sum(eYea, eMon, eDay);

	return sum;
}

float Date::operator-(const Date & d2) const
{
	int Y, m, d;
	Y = getYear() - d2.getYear();
	m = getMonth() - d2.getMonth();
	d = getDay() - d2.getDay();

	return Y * 8640 + 720 * m + d * 24;
}

ostream& operator<< (ostream &os, const Date &d) {
	os << d.getDate();

	return os;
}
