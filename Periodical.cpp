#include "Periodical.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)
void Periodical::copyDynamic(const Periodical& other) {
	size = other.size;
	capacity = other.capacity;

	contentList = new Content * [capacity];
	for (int i = 0; i < capacity; i++)
	{
		if (other.contentList[i] == nullptr)
			contentList[i] = nullptr;
		else
			contentList[i] = new Content(*other.contentList[i]); 
	}
	issn = new char[strlen(other.issn) + 1];
	strcpy(issn, other.issn);
}
void  Periodical::freeDynamic() {
	for (size_t i = 0; i < size; i++)
	{
		delete contentList[i];
	}
	delete[] contentList;
	size = capacity = 0;
	delete[]issn;
	issn = nullptr;
}
void Periodical::resize()
{
	unsigned newCapacity = capacity * MULTY;
	Content** newContent = new Content * [newCapacity] {nullptr};
	for (int i = 0; i < size; i++) {
		if (contentList[i])
			newContent[i] = new Content(*contentList[i]);
		else
			newContent[i] = nullptr;
	}
	delete[]contentList;
	contentList = newContent;
	capacity = newCapacity;
}
Periodical::Periodical(const char* title, const char* publisher, const char* genre, const char* description,
	unsigned year, unsigned month, double rating, const Content** contentList, unsigned capacity,
	unsigned size, const char* issn, unsigned countIssue):
	EditionInfo(title, publisher, genre, description, year, month, rating) , countIssue(countIssue)

{
	setContentList(contentList, capacity, size);
	setIssn(issn);
}
Periodical::Periodical(const Periodical& other) :EditionInfo(other) {
	copyDynamic(other);
	countIssue = other.countIssue;
}
Periodical& Periodical:: operator=(const Periodical& other) {
	if (this != &other) {
		EditionInfo::operator=(other);
		freeDynamic();
		copyDynamic(other);
		countIssue = other.countIssue;
	}
	return *this;
}
Periodical::~Periodical() {
	freeDynamic();
}

void Periodical::setContentList(const Content** contentList, unsigned capacity, unsigned size)
{
	if (this->contentList != nullptr) {
		for (unsigned i = 0; i < this->size; ++i) {
			delete this->contentList[i];
		}
		delete[] this->contentList;
	}
	this->capacity = capacity;
	this->size = size;
	this->contentList = new Content * [capacity];
	for (unsigned i = 0; i < size; ++i) {
		this->contentList[i] = new Content(*contentList[i]); 
	}
	for (unsigned i = size; i < capacity; ++i) {
		this->contentList[i] = nullptr;
	}
}

void  Periodical::setIssn(const char* issn) {
	if (!issn || issn == this->issn)
		return;
	delete[] this->issn;
	size_t size = strlen(issn);
	this->issn = new char[size + 1];
	strcpy(this->issn, issn);
}

const char* Periodical::getIssn()const {
	return issn;
}
unsigned Periodical::getCountIssue()const {
	return countIssue;
}
Content** Periodical::getContent()const {
	return contentList;
}

unsigned Periodical::getContentCount() const
{
	return size;
}

unsigned Periodical::getCapacity() const
{
	return capacity;
}

EditionInfo* Periodical::clone() const
{
	return new Periodical(*this);
}
