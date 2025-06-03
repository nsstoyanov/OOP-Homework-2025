#pragma once
#include "EditionInfo.h"
class Book : public virtual EditionInfo {
public:
    Book(const char* title, const char* publisher, const char* genre,
        const char* description, unsigned year, unsigned month, double rating,
        const char* author, const char** keywords, int keywordCount, const char* isbn);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();

    void setAutor(const char* author);
    void setKeywords(const char** keywords,int keywordCount);
    void setIsbn(const char* isbn);
    
    const char* getAutor()const;
    const char* const* getKeywords() const;
    int getKeywordsCount()const;
    const char* getIsbn()const;

    EditionInfo* clone() const override;

    
private:
    char* author = nullptr;         
    char* isbn = nullptr;

    char** keywords = nullptr;
    int keywordCount = 0;     

    void copyDynamic(const Book& other);
    void freeDynamic();

};