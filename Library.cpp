#include "Library.h"
#include <iostream>
using namespace std;
void Library::copyDynamic(const Library& other)
{
	library = new EditionInfo * [other.capacity]; 
	copies = new unsigned[other.capacity];
	for (size_t i = 0; i < other.count; i++) {
		library[i] = other.library[i]->clone();
		copies[i] = other.copies[i];
	}
	count = other.count;
	capacity = other.capacity;
}

void Library::freeDynamic()
{
	for (size_t i = 0; i < count; i++)
	{
		delete library[i];
	}
	delete[]library;
	delete[]copies;
	count = 0;
	copies = nullptr;
	capacity = 0;
	library = nullptr;
}
void Library::resize()
{
	size_t newCapacity = capacity * MULTY;
	EditionInfo** newLibrary = new EditionInfo * [newCapacity];
	unsigned* newCopies = new unsigned[newCapacity] {};
	for (size_t i = 0; i < count; ++i) {
		newLibrary[i] = library[i];
		newCopies[i] = copies[i];
	}
	for (size_t i = count; i < newCapacity; ++i) {
		newLibrary[i] = nullptr;
	}
	delete[] library; 
	delete[] copies;
	library = newLibrary;
	copies = newCopies;
	capacity = newCapacity;
}
Library::Library() : capacity(DEFAULT_CAP),count(0)
{
	copies = new unsigned[DEFAULT_CAP] {};
	library = new EditionInfo * [capacity];
	for (size_t i = 0; i < capacity; ++i)
		library[i] = nullptr;
}

Library::Library(const Library& other)
{
	copyDynamic(other);
}

Library& Library::operator=(const Library& other)
{
	if (this != &other) {
		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}

Library::~Library()
{
	freeDynamic();
}

size_t Library::getCapacity() const
{
	return capacity;
}

size_t Library::getCount() const
{
	return count;
}

void Library::addItem(const EditionInfo* item, unsigned numCopies) {
	if (count >= capacity)
		resize();

	library[count] = item->clone(); 
	copies[count] = numCopies;
	++count;
}
void Library::print() const {
	for (size_t i = 0; i < count; ++i) {
		if (library[i]) {
			std::cout << "Item " << i + 1 << ":\n";
			std::cout << " Title: " << library[i]->getTitle() << "\n";
			std::cout << " Publisher: " << library[i]->getPublisher() << "\n";
			std::cout << " Genre: " << library[i]->getGenre() << "\n";
			std::cout << " Description: " << library[i]->getDescription() << "\n";
			std::cout << " Year: " << library[i]->getYearPublished() << "\n";
			std::cout << " Month: " << library[i]->getMontPublished() << "\n";
			std::cout << " Rating: " << library[i]->getRating() << "\n";
			std::cout << " Library ID: " << library[i]->getLibraryID() << "\n";
			std::cout << "----- Item " << i + 1 << " (" << copies[i] << " copies) -----\n";
			std::cout << "------------------------------\n";
		}
	}
}