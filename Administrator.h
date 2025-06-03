#pragma once
#include "Consumer.h"
class Administrator : public Consumer {
public:
	Administrator();
	Administrator(const char* consumerName, const char* password, const Time& registration, 
		const Time& lastAccess, const char* email);
	Administrator(const Administrator& other);
	Administrator& operator=(const Administrator& other);
	~Administrator();

	void setEmail(const char* email);
	const char* getEmail()const;

	Consumer* clone() const override;
	void print(std::ostream& os) const override;
	void read(std::istream& is)override;


private:
	char* email = nullptr;
};