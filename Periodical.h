#pragma once
#include "EditionInfo.h"
#include "Content.h"
using namespace std;
class Periodical : public virtual EditionInfo {
public:
	Periodical(const char* title, const char* publisher, const char* genre, const char* description,
		unsigned year, unsigned month, double rating, const Content** contentList,unsigned capacity , 
		unsigned size , const char* issn, unsigned countIssue);
	Periodical(const Periodical& other);
	Periodical& operator=(const Periodical& other);
	~Periodical();

	void setContentList(const Content** contentList, unsigned capacity , unsigned size );
	void setIssn(const char* issn);

	const char* getIssn()const;
	unsigned getCountIssue()const;
	Content** getContent()const;
	unsigned getContentCount() const;
	unsigned getCapacity()const;
	EditionInfo* clone() const override;

private:
	Content** contentList = nullptr;
	unsigned capacity = 0;
	unsigned size = 0;

	char* issn = nullptr;
	unsigned countIssue = 0;
	
	void copyDynamic(const Periodical& other);
	void freeDynamic();
	void resize();


	static constexpr double MULTY = 2;
};