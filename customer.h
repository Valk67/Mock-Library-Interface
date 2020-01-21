#include "book.h"
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <vector>

class Customer {
  public:
    Customer (std::string r);
    std::string getRegistered_customer();
    std::vector <Book> getChecked_out_books();
    void setChecked_out_books (Book checkOut);
    void setChecked_in_books();
  private:
    std::vector <Book> checked_out_books;
    std::string registered_customer;  
};

//creates a vector from csv file
std::vector <Customer> registered_customers_in_csv_file (std::string filename);

#endif //customers_h_
