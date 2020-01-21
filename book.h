#ifndef BOOK_H_
#define BOOK_H_
#include <string>
#include <vector>
class Book {
  public:
    Book (std::string a, std::string t, std::string p, std::string y);
    std::string getAuthor();
    std::string getTitle();
    std::string getPublisher();
    std::string getYear();
    bool getInstock();
    void setInstock (bool x);
  private:
    std::string author;
    std::string title;
    std::string publisher;
    std::string year;
    bool instock = true;
};

//fstream like function that pulls books from csv file and saves them
std::vector<Book> books_in_csv_file (std::string filename);

#endif //book_H_
