#include "book.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Book::Book (std::string a, std::string t, std::string p, std::string y)
  : author(a), title(t), publisher(p), year(y) {} 
 
std::string Book::getAuthor() {
  return author;
} 

std::string Book::getTitle() {
  return title;
}

std::string Book::getPublisher() {
  return publisher;
} 

std::string Book::getYear() {
  return year;
} 

bool Book::getInstock() {
  return instock;
} 
void Book::setInstock (bool x) {
  instock = x;
} 

//pulls in books from a csv file.
std::vector<Book> books_in_csv_file (std::string filename) {
  std::ifstream inf;
  inf.open (filename);
    if (!inf.is_open()){ 
    std::cout << "Error with book files" << std::endl;
    } 
  std::string tmp_author;
  std::string tmp_title;
  std::string tmp_publisher;
  std::string tmp_year;
  std::string line; 
  std::vector<Book> b;
    while (std::getline (inf, line)){
    std::istringstream ss (line);
      std::getline (ss, tmp_author, ',');
      std::getline (ss, tmp_title, ',');
      std::getline (ss, tmp_publisher, ',');
      std::getline (ss, tmp_year, ',');
    Book tmp = Book (tmp_author, tmp_title, tmp_publisher, tmp_year);
    b.push_back (tmp);
    } 
  inf.close();
return b;
}
   
 
