#include "Series.h"

Series::Series(const char* title, const char* publisher, const char* genre, const char* description, 
	unsigned year, unsigned month, double rating, const char* author, const char** keywords, int keywordCount,
	const char* isbn, const Content** contentList, unsigned contentCapacity, unsigned contentSize, const char* issn,
	unsigned countIssue) :
	EditionInfo(title, publisher, genre, description, year, month, rating),
	Book(nullptr, nullptr, nullptr, nullptr, 0, 0, 0.0, author, keywords, keywordCount, isbn),
	Periodical(nullptr, nullptr, nullptr, nullptr, 0, 0, 0.0, contentList, contentCapacity, contentSize, issn, countIssue)
{
}

EditionInfo* Series::clone() const
{
	return new Series(*this); 
}
