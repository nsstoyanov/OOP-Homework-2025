#include "Time.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
Time::Time() : day(1), month(1), year(1), isDateInValidState(true) {}

Time::Time(unsigned day, unsigned month, unsigned year) {
    setDate(day, month, year);
    if (!isDateInValidState) {
        throw std::invalid_argument("Invalid Time");
    }
}

void Time::setDate(unsigned day, unsigned month, unsigned year) {
    this->day = day;
    this->month = month;
    this->year = year;
    validateDate();
}

unsigned Time::getDay() const {
    return day;
}

unsigned Time::getMonth() const {
    return month;
}

unsigned Time::getYear() const {
    return year;
}

bool Time::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned Time::getMaxDayForMonth(unsigned month) const {
    static const unsigned daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeapYear())
        return 29;
    return daysInMonth[month - 1];
}

void Time::validateDate() {
    if (month < 1 || month > 12 || year == 0) {
        isDateInValidState = false;
        return;
    }

    unsigned maxDay = getMaxDayForMonth(month);
    isDateInValidState = (day >= 1 && day <= maxDay);
}
void Time::print(std::ostream& os) const
{
    os << getDay() << '/' << getMonth() << '/' << getYear() << std::endl;
}

void Time::read(std::istream& is)
{
    char separator;
    is >> day >> separator >> month >> separator >> year;
    validateDate();
}
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    t.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Time& t)
{
    t.read(is);
    return is;
}
bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.getDay() == rhs.getDay() &&
        lhs.getMonth() == rhs.getMonth() &&
        lhs.getYear() == rhs.getYear();
}

bool operator!=(const Time& lhs, const Time& rhs) {
    return !(lhs == rhs);
}
bool operator<(const Time& lhs, const Time& rhs)
{
    if (lhs.getYear() != rhs.getYear())
        return lhs.getYear() < rhs.getYear();
    if (lhs.getMonth() != rhs.getMonth())
        return lhs.getMonth() < rhs.getMonth();
    return lhs.getDay() < rhs.getDay();
}
bool operator>(const Time& lhs, const Time& rhs)
{
    return !(lhs < rhs);
}


