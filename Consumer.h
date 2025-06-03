#pragma once
#include <fstream> 
#include "Time.h"
class Consumer {
public:
	Consumer(const char* consumerName, const char* password, const Time& registration,const Time& lastAccess);
	Consumer(const Consumer& other);
	Consumer& operator=(const Consumer& other);
	virtual ~Consumer();

	void setConsumerName(const char* consumerName);
	void setPassword(const char* password);

	const char* getConsumerName()const;
	const char* getPassword()const;
	Time& getRegistration();
	Time& getLastAccess();
	const Time& getRegistration() const;
	const Time& getLastAccess() const;

	virtual Consumer* clone() const = 0;
	virtual void print(std::ostream& is) const = 0;
	virtual void read(std::istream& in) = 0;

	friend std::ostream& operator<<(std::ostream& os,const Consumer& c);
	friend std::istream& operator>>(std::istream& is,Consumer& c);
private:
	char* consumerName = nullptr;
	char* password = nullptr;
	Time registration;
	Time lastAccess;

	void copyDynamic(const Consumer& other);
	void freeDynamic();

};