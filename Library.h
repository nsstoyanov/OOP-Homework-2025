#pragma once
#include "EditionInfo.h"

class Library {
public:
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

	size_t getCapacity()const;
	size_t getCount()const;
	void addItem(const EditionInfo* item, unsigned numCopies);
	void print() const;

private:
	EditionInfo** library;
	size_t capacity;
	size_t count;
	
	unsigned* copies;

	void copyDynamic(const Library& other);
	void freeDynamic();
	void resize();

	static constexpr unsigned MULTY = 2;
	static constexpr unsigned DEFAULT_CAP = 8;
};