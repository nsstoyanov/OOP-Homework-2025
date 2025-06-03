#include "Consumer.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)
void Consumer::copyDynamic(const Consumer& other) {
	consumerName = new char[strlen(other.consumerName) + 1];
	strcpy(consumerName, other.consumerName);

	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);

}
void Consumer::freeDynamic() {
	delete[] consumerName;
	delete[] password;
	consumerName = nullptr;
	password = nullptr;
}
Consumer::Consumer(const char* consumerName, const char* password,const  Time& registration,const Time& lastAccess) : registration(registration),lastAccess(lastAccess)
{
	setConsumerName(consumerName);
	setPassword(password);
}
Consumer::Consumer(const Consumer& other)
{
	copyDynamic(other);
}
Consumer& Consumer::operator=(const Consumer& other)
{
	if (this != &other) {
		freeDynamic();
		copyDynamic(other);
		registration = other.registration;
		lastAccess = other.lastAccess;
	}
	return *this;
}
Consumer::~Consumer()
{
	freeDynamic();
}

void Consumer::setConsumerName(const char* consumerName)
{
	if (!consumerName || consumerName == this->consumerName)
		return;
	delete[] this->consumerName;
	size_t size = strlen(consumerName);
	this->consumerName = new char[size + 1];
	strcpy(this->consumerName, consumerName);
}

void Consumer::setPassword(const char* password)
{
	if (!password || password == this->password)
		return;
	delete[] this->password;
	size_t size = strlen(password);
	this->password = new char[size + 1];
	strcpy(this->password, password);
}

const char* Consumer::getConsumerName() const
{
	return consumerName;
}

const char* Consumer::getPassword() const
{
	return password;
}
Time& Consumer::getRegistration()
{
	return registration;
}
Time& Consumer::getLastAccess()
{
	return lastAccess;
}
const Time& Consumer::getRegistration() const {
	return registration;
}

const Time& Consumer::getLastAccess() const {
	return lastAccess;
}

std::ostream& operator<<(std::ostream& os, const Consumer& c)
{
	c.print(os);
	return os;
}

std::istream& operator>>(std::istream& is, Consumer& c)
{
	c.read(is);
	return is;
}
