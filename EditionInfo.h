#pragma once
class EditionInfo {
public:
    EditionInfo(const char* title, const char* publisher, const char* genre, const char* description, 
                 unsigned year, unsigned month, double rating);
    EditionInfo(const EditionInfo& other);
    EditionInfo& operator=(const EditionInfo& other);
    virtual ~EditionInfo();

    void setTitle(const char* title);
    void setPublisher(const char* publisher);
    void setGenre(const char* genre);
    void setDescription(const char* description);
    void setYearPublished(unsigned year);
    void setMonthPublished(unsigned month);
    void setRating(double rating);

    const char* getTitle()const;
    const char* getPublisher()const;
    const char* getGenre()const;
    const char* getDescription()const;
    unsigned getYearPublished()const;
    unsigned getMontPublished()const;
    double getRating()const;
    unsigned getLibraryID() const;

    virtual EditionInfo* clone() const = 0;

private:
    char* title = nullptr;
    char* publisher = nullptr;
    char* genre = nullptr;
    char* description = nullptr;
    unsigned yearPublished = 0;
    unsigned monthPublished = 0;
    double raiting = 0.0;
    unsigned libraryID ;

    static size_t idCount;
    void copyDynamic(const EditionInfo& other);
    void freeDynamic();

    static constexpr double MAX_RATING = 10.0;
    static constexpr double MIN_RATING = 0.0;
    static constexpr unsigned MAX_YEAR = 2025;
    static constexpr double MAX_MONTH = 12;
};