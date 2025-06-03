#include "EditionInfo.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)
size_t EditionInfo::idCount = 0;
void EditionInfo::copyDynamic(const EditionInfo& other) {
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	publisher = new char[strlen(other.publisher) + 1];
	strcpy(publisher, other.publisher);

	genre = new char[strlen(other.genre) + 1];
	strcpy(genre, other.genre);

	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}
void EditionInfo::freeDynamic() {
	delete[] title;
	delete[] publisher;
	delete[] genre;
	delete[] description;
	title = nullptr;
	publisher = nullptr;
	genre = nullptr;
	description = nullptr;
}
EditionInfo::EditionInfo(const char* title, const char* publisher, const char* genre, const char* description,
	unsigned year, unsigned mount, double raiting) :libraryID(idCount++) {
	setTitle( title);
	 setPublisher( publisher);
	 setGenre( genre);
	 setDescription( description);
	 setYearPublished( year);
	 setMonthPublished(mount);
	 setRating( raiting);
}
EditionInfo::EditionInfo(const EditionInfo& other) {
	copyDynamic(other);
	yearPublished = other.yearPublished;
	monthPublished = other.monthPublished;
	raiting = other.raiting;
}
EditionInfo& EditionInfo::operator=(const EditionInfo& other) {
	if (this != &other) {
		freeDynamic();
		copyDynamic(other);
		yearPublished = other.yearPublished;
		raiting = other.raiting;
		monthPublished = other.monthPublished;
	}
	return *this;
}
EditionInfo::~EditionInfo() {
	freeDynamic();
}

void EditionInfo::setTitle(const char* title) {
	if (!title || title == this->title)
		return;
	delete[] this->title;
	size_t size = strlen(title);
	this->title = new char[size + 1];
	strcpy(this->title, title);
}
void EditionInfo::setPublisher(const char* publisher) {
	if (!publisher || publisher == this->publisher)
		return;
	delete[] this->publisher;
	size_t size = strlen(publisher);
	this->publisher = new char[size + 1];
	strcpy(this->publisher, publisher);
}
void EditionInfo::setGenre(const char* genre){
	if (!genre || genre == this->genre)
		return;
	delete[] this->genre;
	size_t size = strlen(genre);
	this->genre = new char[size + 1];
	strcpy(this->genre, genre);
}
void EditionInfo::setDescription(const char* description) {
	if (!description || description == this->description)
		return;
	delete[] this->description;
	size_t size = strlen(description);
	this->description = new char[size + 1];
	strcpy(this->description, description);
}
void EditionInfo::setYearPublished(unsigned year) {
	if (year > MAX_YEAR) {
		throw std::invalid_argument("The book must exist.");
	}
	this->yearPublished = year;
}
void EditionInfo::setMonthPublished(unsigned month) {
	if (month > MAX_MONTH ) {
		throw std::invalid_argument("The month must exist.");
	}
	this->monthPublished = month;
}
void EditionInfo::setRating(double raiting) {
	if (raiting < MIN_RATING || raiting > MAX_RATING) {
		throw std::invalid_argument("Rating must be between 0 and 10.");
	}
	this->raiting = raiting;
}

const char* EditionInfo::getTitle() const
{
	return title;
}

const char* EditionInfo::getPublisher() const
{
	return publisher;
}

const char* EditionInfo::getGenre() const
{
	return genre;
}

const char* EditionInfo::getDescription() const
{
	return description;
}

unsigned EditionInfo::getYearPublished() const
{
	return yearPublished;
}

unsigned EditionInfo::getMontPublished()const 
{
	return monthPublished;
}

double EditionInfo::getRating() const
{
	return raiting;
}

unsigned EditionInfo::getLibraryID() const
{
	return libraryID;
}
