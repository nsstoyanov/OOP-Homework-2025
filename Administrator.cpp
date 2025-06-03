#include "Administrator.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)
Administrator::Administrator() :Consumer("","",Time(),Time())
{
	setEmail("");
}
Administrator::Administrator(const char* consumerName, const char* password,
	const Time& registration, const Time& lastAccess, const char* email) : Consumer(consumerName,password,registration,lastAccess)
{
	setEmail(email);
}

Administrator::Administrator(const Administrator& other) : Consumer(other)
{
	email = new char[strlen(other.email) + 1];
	strcpy(email, other.email);
}

Administrator& Administrator::operator=(const Administrator& other)
{
	if (this != &other) {
		delete[] email;
		email = new char[strlen(other.email) + 1];
		strcpy(email, other.email);
		Consumer::operator=(other);
	}
	return *this;
}

Administrator::~Administrator()
{
	delete[] email;
}

void Administrator::setEmail(const char* email)
{
	if (!email || email == this->email)
		return;
	delete[] this->email;
	size_t size = strlen(email);
	this->email = new char[size + 1];
	strcpy(this->email, email);
}

const char* Administrator::getEmail() const
{
	return email;
}

Consumer* Administrator::clone() const
{
	return new Administrator(*this);
}

void Administrator::print(std::ostream& os) const
{
	os << getConsumerName() << std::endl
	   << getPassword() << std::endl
	   << getRegistration() << std::endl
	   << getLastAccess() << std::endl
	   << getEmail() << std::endl;
}

void Administrator::read(std::istream& is)
{
	char buffer[256];
	is.getline(buffer, 256);
	setConsumerName(buffer);

	is.getline(buffer, 256);
	setPassword(buffer);

	getRegistration().read(is); 
	getLastAccess().read(is);

	is.getline(buffer, 256);
	setEmail(buffer);
}

