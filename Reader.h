#pragma once
#include "Consumer.h"
#include "GivenReturnTime.h"
#include "fstream"
class Reader : public Consumer {
public:
	Reader(const char* consumerName, const char* password, const Time& registration, const Time& lastAccess);
	Reader(const Reader& other);
	Reader& operator=(const Reader& other);
	~Reader();

	size_t getCapacity()const;
	size_t getCount()const;
	void addItem(const GivenReturnTime* item);

	Consumer* clone() const override;
	void print(std::ostream& os) const override;
	void read(std::istream& is)override;

private:
	GivenReturnTime** listOrders = nullptr;
	size_t count = 0;
	size_t capacity = 0;

	void copyDynamic(const Reader& other);
	void freeDynamic();
	void resize();

	static constexpr unsigned MULTY = 2;
	static constexpr unsigned DEFAULT_CAP = 8;
};