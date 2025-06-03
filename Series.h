#pragma once
#include "Book.h"
#include "Periodical.h"
class Series : public Book, public Periodical {
public:
    Series(const char* title,
        const char* publisher,
        const char* genre,
        const char* description,
        unsigned year,
        unsigned month,
        double rating,
        const char* author,
        const char** keywords,
        int keywordCount,
        const char* isbn,
        const Content** contentList,
        unsigned contentCapacity,
        unsigned contentSize,
        const char* issn,
        unsigned countIssue);

    EditionInfo* clone() const override;
};