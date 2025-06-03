#include "Reader.h"
#include "Consumer.h"
#include <iostream>
void Reader::copyDynamic(const Reader& other)
{
	listOrders = new GivenReturnTime*[other.capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		listOrders[i] = new GivenReturnTime(*other.listOrders[i]);
	}
	capacity = other.capacity;
	count = other.count;
}

void Reader::freeDynamic()
{
	for (size_t i = 0; i < count; i++)
	{
		delete listOrders[i];
	}
	delete[] listOrders;
	listOrders = nullptr;
	capacity = 0;
	count = 0;
}

void Reader::resize()
{
	size_t newCap = capacity * MULTY;
	GivenReturnTime** newListOrder = new GivenReturnTime * [newCap];
	for (size_t i = 0; i < count; i++){
		newListOrder[i] = new GivenReturnTime(*listOrders[i]);
	}
	for (size_t i = count; i < capacity; i++)
	{
		newListOrder[i] = nullptr;
	}
	listOrders = newListOrder;
	capacity = newCap;
}

Reader::Reader(const char* consumerName, const char* password, const Time& registration, const Time& lastAccess) 
	: Consumer(consumerName,password,registration,lastAccess),capacity(DEFAULT_CAP),count(0)
{
	listOrders = new GivenReturnTime * [capacity];
	for (size_t i = 0; i < capacity; ++i)
		listOrders[i] = nullptr;
}

Reader::Reader(const Reader& other) : Consumer(other)
{
	copyDynamic(other);
}

Reader& Reader::operator=(const Reader& other)
{
	if (this != &other) {
		freeDynamic();
		Consumer::operator=(other);
		copyDynamic(other);
	}
	return *this;
}

Reader::~Reader()
{
	freeDynamic();
}

size_t Reader::getCapacity() const
{
	return capacity;
}

size_t Reader::getCount() const
{
	return count;
}

void Reader::addItem(const GivenReturnTime* item)
{
	if (capacity >= count) {
		resize();
	}
	listOrders[count++] = new GivenReturnTime(*item);
	std::cout << "True" << std::endl;
}

Consumer* Reader::clone() const
{
	return new Reader(*this);
}

void Reader::print(std::ostream& os) const
{
	os << getConsumerName() << std::endl
		<< getPassword() << std::endl
		<< getRegistration()
		<< getLastAccess();
	    os << count << std::endl;

	for (size_t i = 0; i < count; i++)
	{
		os << *listOrders[i];
	}
}

void Reader::read(std::istream& is)
{
	char buffer[256];
	is.getline(buffer, 256);
	setConsumerName(buffer);

	is.getline(buffer, 256);
	setPassword(buffer);

	getRegistration().read(is);
	getLastAccess().read(is);
	freeDynamic(); 
	is >> count;
	is.ignore();
	capacity = count;
	listOrders = new GivenReturnTime * [capacity];

	for (size_t i = 0; i < count; ++i) {
		listOrders[i] = new GivenReturnTime();
		listOrders[i]->read(is);
		is.ignore();
	}
}


