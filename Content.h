#pragma once
class Content {
public:
	Content(const char* title,const char* author,const char** keywords,unsigned keywordsCount);
	Content(const Content& other);
	Content& operator=(const Content& other);
	~Content();

	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setKeywords(const char** keywords, int keywordCount);
	
	const char* getTitle()const;
	const char* getAuthor()const;
	const char* const* getKeywords() const;
	int getKeywordsCount()const;


private:
	char* title = nullptr;
	char* author = nullptr;

	char** keywords = nullptr;
	unsigned keywordCount = 0;

	void copyDynamic(const Content& other);
	void freeDynamic();
};