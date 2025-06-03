#pragma once
#include <fstream> 
class Time {
public:
	Time();
	Time(unsigned day, unsigned month, unsigned year);
	void setDate(unsigned day, unsigned month, unsigned year);

	unsigned getDay()const;
	unsigned getMonth()const;
	unsigned getYear()const;

	void print(std::ostream& os) const ;
	void read(std::istream& is) ;

	friend std::ostream& operator<<(std::ostream& os, const Time& t);
	friend std::istream& operator>>(std::istream& is, Time& t);


private:
	unsigned day ;
	unsigned month ;
	unsigned year ;
	bool isDateInValidState = true;

	void validateDate();
	bool isLeapYear() const;
	unsigned getMaxDayForMonth(unsigned month) const;

};
bool operator==(const Time& lhs, const Time& rhs);
bool operator!=(const Time& lhs, const Time& rhs);
bool operator<(const Time& lhs, const Time& rhs);
bool operator>(const Time& lhs, const Time& rhs);
