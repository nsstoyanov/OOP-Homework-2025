

//int main() {
//    Library library;
//
//    const char* bookKeywords[] = { "C++", "OOP", "Programming" };
//
//    // Създаваме книга
//    Book* b1 = new Book(
//        "Effective C++", "Pearson", "Programming", "Tips for better C++",
//        2020, 3, 9.1, "Scott Meyers", bookKeywords, 3, "1234567890"
//    );
//
//    const char* kw1[] = { "AI", "Future" };
//    const char* kw2[] = { "Quantum", "Computing" };
//
//    Content* a1 = new Content("AI in 2030", "Alice Smith", kw1, 2);
//    Content* a2 = new Content("Quantum Revolution", "Bob Jones", kw2, 2);
//
//    const Content* articles[] = { a1, a2 };
//
//    Periodical* p1 = new Periodical(
//        "Tech Monthly", "InnovatePress", "Technology", "Future tech insights",
//        2025, 5, 8.7, articles, 2, 2, "9876-5432", 12
//    );
//    const char* seriesKeywords[] = { "Robotics", "Automation" };
//    Content* s1 = new Content("Rise of Robots", "Dr. Robotnik", seriesKeywords, 2);
//    Content* s2 = new Content("Automate World", "Cyber Jane", seriesKeywords, 2);
//
//    const Content* seriesContent[] = { s1, s2 };
//
//    Series* series = new Series(
//        "Future Machines", "TechBooks", "Sci-Fi", "Robots and Automation",
//        2025, 4, 9.3,
//        "Isaac Asimov", seriesKeywords, 2, "1122-3344-5566",
//        seriesContent, 2, 2, "4455-6677", 6
//    );
//
//    library.addItem(b1,3);
//    library.addItem(p1,1);
//    library.addItem(series,3);
//    library.print();
//
//    return 0;
//}
//#include <iostream>
//#include "Time.h"
//#include "Administrator.h"
//#include "Reader.h"
//#include "GivenReturnTime.h"
//
//int main() {
//    try {
//        Time regDate(1, 2, 2022);
//        Time lastAccess(24, 10, 2023);
//        Administrator AD;
//        // Създаваме потребител - Reader
//        Reader reader("JohnDoe", "pass123", regDate, lastAccess);
//        std::cout << "Reader: " << reader.getConsumerName() << ", Password: " << reader.getPassword() << "\n";
//
//        // Дата на заемане и връщане
//        Time given(2, 3, 1232);
//        Time returned(2, 6, 15);
//
//        // Книга
//        const char* bookTitle = "C++ Programming in Depth";
//
//        // Създаваме запис за заемане
//        GivenReturnTime* loan = new GivenReturnTime(bookTitle,given, returned);
//
//        // Добавяме го в Reader
//        reader.addItem(loan);
//
//        // Принтираме информация за добавената книга
//        std::cout << "Book borrowed: " << loan->getName() << std::endl;
//        std::cout << "Given on: " << loan->getGiven().getDay() << "/"
//            << loan->getGiven().getMonth() << "/"
//            << loan->getGiven().getYear() << std::endl;
//
//        delete loan; // Reader си пази копие
//
//        std::cout << "-------------------------\n";
//
//        // Създаваме администратор
//        Administrator admin("AdminGuy", "adminpass", regDate, lastAccess, "admin@example.com");
//        std::cout << "Administrator: " << admin.getConsumerName()
//            << ", Email: " << admin.getEmail()
//            << ", Password: " << admin.getPassword() << std::endl;
//
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception caught: " << e.what() << std::endl;
//    }
//    return 0;
//}
#include <iostream>
#include <fstream>
#include "Reader.h"
#include "GivenReturnTime.h"
#include "Time.h"

int main() {
    // Създаваме Reader
    Time reg(1, 1, 2020);
    Time last(2, 2, 2024);
    Reader r("ivan", "1234", reg, last);

    // Добавяме GivenReturnTime обекти
    GivenReturnTime* g1 = new GivenReturnTime("san dukan", Time(10, 3, 2024), Time(20, 3, 2024));
    GivenReturnTime* g2 = new GivenReturnTime("lukan nas", Time(5, 4, 2023), Time(15, 4, 2023));
    r.addItem(g1);
    r.addItem(g2);
    std::ofstream out("reader.txt");
    if (!out) {
        std::cout << "Cant open the file for writing" << std::endl;
        return 1;
    }
    out << r;
    out.close();

    // Четем от файл в нов обект
    std::ifstream in("reader.txt");
    if (!in) {
        std::cout << "Cant open for reading" << std::endl;
        return 1;
    }

    Reader r2("a", "b", Time(), Time()); // или ако имаш дефолтен конструктор Reader()
    in >> r2;
    in.close();

    std::cout << "Readed object:" << std::endl << r2 << std::endl;

    delete g1;
    delete g2;

    return 0;
}
