#include "Content.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)
void Content::copyDynamic(const Content& other)
{
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	author = new char[strlen(other.author) + 1];
	strcpy(author, other.author);

	keywordCount = other.keywordCount;
	keywords = new char* [keywordCount];
	for (int i = 0; i < keywordCount; i++) {
		keywords[i] = new char[strlen(other.keywords[i]) + 1];
		strcpy(keywords[i], other.keywords[i]);
	}
}

void Content::freeDynamic()
{
	delete[] author;
	delete[] title;
	for (size_t i = 0; i < keywordCount; i++)
	{
		delete[]keywords[i];
	}
	delete[] keywords;
	author = nullptr;
	title = nullptr;
	keywords = nullptr;
	keywordCount = 0;
}

Content::Content(const char* title, const char* author, const char** keywords, unsigned keywordsCount)
{
	setTitle(title);
	setAuthor(author);
	setKeywords(keywords, keywordsCount);
}

Content::Content(const Content& other)
{
	copyDynamic(other);
}

Content& Content::operator=(const Content& other)
{
	if (this != &other) {
		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}

Content::~Content()
{
	freeDynamic();
}

void Content::setTitle(const char* title)
{
	if (!title || title == this->title)
		return;
	delete[] this->title;
	size_t size = strlen(title);
	this->title = new char[size + 1];
	strcpy(this->title, title);
}

void Content::setAuthor(const char* author)
{
	if (!author || author == this->author)
		return;
	delete[] this->author;
	size_t size = strlen(author);
	this->author = new char[size + 1];
	strcpy(this->author, author);
}

void Content::setKeywords(const char** keywords, int keywordCount)
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

const char* Content::getTitle() const
{
	return title;
}

const char* Content::getAuthor() const
{
	return author;
}

const char* const* Content::getKeywords() const
{
	return keywords;
}

int Content::getKeywordsCount() const
{
	return keywordCount;
}
