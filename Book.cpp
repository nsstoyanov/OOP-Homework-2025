#include "Book.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)

void Book::copyDynamic(const Book& other) {
	author = new char[strlen(other.author) + 1];
	strcpy(author, other.author);

	keywordCount = other.keywordCount;
	keywords = new char* [keywordCount];
	for (int i = 0; i < keywordCount; i++) {
		keywords[i] = new char[strlen(other.keywords[i]) + 1];
		strcpy(keywords[i], other.keywords[i]);
	}
	
	isbn = new char[strlen(other.isbn) + 1];
	strcpy(isbn, other.isbn);
}
void Book::freeDynamic() {
	delete[] author;
	for (size_t i = 0; i < keywordCount; i++)
	{
		delete[]keywords[i];
	}
	delete[] keywords;
	delete[] isbn;
	author = nullptr;
	keywords = nullptr;
	keywordCount = 0;
	isbn = nullptr;
}
Book::Book(const char* title, const char* publisher, const char* genre,
	const char* description, unsigned year, unsigned month, double rating,
	const char* author, const char** keywords, int keywordCount, const char* isbn): EditionInfo(title, publisher, genre, description, year, month, rating) {
	setAutor(author);
	setKeywords(keywords,keywordCount);
	setIsbn(isbn);
}
Book::Book(const Book& other) : EditionInfo(other){
	copyDynamic(other);
}
Book& Book::operator=(const Book& other) {
	if (this != &other) {
		EditionInfo::operator=(other);
		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}
Book::~Book(){
	freeDynamic();
}

void Book::setAutor(const char* author)
{
	if (!author || author == this->author) 
		return;
	delete[] this->author;
	size_t size = strlen(author);
	this->author = new char[size + 1];
	strcpy(this->author, author);
}

void Book::setKeywords(const char** keywords, int keywordCount)
{
	if (this->keywords != nullptr) {
		for (int i = 0; i < this->keywordCount; ++i) {
			delete[] this->keywords[i];  
		}
		delete[] this->keywords;  
	}

	this->keywordCount = keywordCount;
	this->keywords = new char* [keywordCount];

	for (int i = 0; i < keywordCount; ++i) {
		size_t len = strlen(keywords[i]);
		this->keywords[i] = new char[len + 1];
		strcpy(this->keywords[i], keywords[i]);
	}
}

void Book::setIsbn(const char* isbn)
{
	if (!isbn || isbn == this->isbn)
		return;
	delete[] this->isbn;
	size_t size = strlen(isbn);
	this->isbn = new char[size + 1];
	strcpy(this->isbn, isbn);
}

const char* Book::getAutor() const
{
	return author;
}

const char* const* Book::getKeywords() const
{
	return keywords;
}

int Book::getKeywordsCount() const
{
	return keywordCount;
}

const char* Book::getIsbn() const
{
	return isbn;
}

EditionInfo* Book::clone() const
{
	return new Book(*this);
}
