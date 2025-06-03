#include "GivenReturnTime.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)
GivenReturnTime::GivenReturnTime() : given(),toReturn()
{
	setName("");
}
GivenReturnTime::GivenReturnTime(const char* bookName, const Time& given, const Time& toReturn) {
	setName(bookName);
	setTime(given, toReturn);
	if (!isDateInValidState) {
		throw std::invalid_argument("Invalid Time");
	}
}
GivenReturnTime::GivenReturnTime(const GivenReturnTime& other) {
	bookName = new char[strlen(other.bookName) + 1];
	strcpy(bookName, other.bookName);
}
GivenReturnTime& GivenReturnTime::operator=(const GivenReturnTime& other) {
	if (this != &other) {
		delete[] bookName;
		bookName = new char[strlen(other.bookName) + 1];
		strcpy(bookName, other.bookName);
		given = other.given;
		toReturn = other.toReturn;
	}
	return *this;
}
GivenReturnTime::~GivenReturnTime() {
	delete[] bookName;
}

void GivenReturnTime::setName(const char* bookName) {
	if (!bookName || bookName == this->bookName)
		return;
	delete[] this->bookName;
	size_t size = strlen(bookName);
	this->bookName = new char[size + 1];
	strcpy(this->bookName, bookName);
}

void GivenReturnTime::setTime(const Time& given, const Time& toReturn)
{
	this->given = given;
	this->toReturn = toReturn;
	validate();
}


const char* GivenReturnTime::getName()const {
	return bookName;
}
Time& GivenReturnTime::getGiven()
{
	return given;
}
Time& GivenReturnTime::getToReturn()
{
	return toReturn;
}
const Time& GivenReturnTime::getGiven()const {
	return given;
}
const Time& GivenReturnTime::getToReturn()const {
	return toReturn;
}

void GivenReturnTime::print(std::ostream& os) const
{
	os << getName() << std::endl 
	   << getGiven()
	   << getToReturn();
}

void GivenReturnTime::read(std::istream& is)
{
	char buffer[256];
	is.getline(buffer, 256);
	setName(buffer);
	Time given, toReturn;
	given.read(is);
	toReturn.read(is);

	setTime(given,toReturn);
}

void GivenReturnTime::validate()
{
	if (toReturn < given) {
		isDateInValidState = false;
	}
	else {
		isDateInValidState = true;
	}
}

std::ostream& operator<<(std::ostream& os, const GivenReturnTime& g)
{
	g.print(os);
	return os;
}

std::istream& operator>>(std::istream& is, GivenReturnTime& g)
{
	g.read(is);
	return is;
}
