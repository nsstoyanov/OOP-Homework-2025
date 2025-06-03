#pragma once
#include "Time.h"
class GivenReturnTime {
public:
	GivenReturnTime();
	GivenReturnTime(const char* bookName, const Time& given, const Time& toReturn);
	GivenReturnTime(const GivenReturnTime& other);
	GivenReturnTime& operator=(const GivenReturnTime& other);
	~GivenReturnTime();

	void setName(const char* name);
	void setTime(const Time& given, const Time& toReturn);

	const char* getName()const;
	Time& getGiven();
	Time& getToReturn();
	const Time& getGiven()const;
	const Time& getToReturn()const;

	void print(std::ostream& os) const;
	void read(std::istream& is);

	friend std::ostream& operator<<(std::ostream& os, const GivenReturnTime& g);
	friend std::istream& operator>>(std::istream& is, GivenReturnTime& g);
private:
	char* bookName;
	Time given;
	Time toReturn;
	bool isDateInValidState = true;
	void validate();
};