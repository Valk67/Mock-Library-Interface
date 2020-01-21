#include "customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

//constructor for customer class
Customer::Customer (std::string r)
  : registered_customer(r) {}  

//gets a vector of customer names
std::string Customer::getRegistered_customer() {
  return registered_customer;
} 

//gets a vector of checked out books the certain person
std::vector <Book> Customer::getChecked_out_books() {
  return checked_out_books;
} 

//push a book vector onto a vector of customers
//sends an instance of a book vector to push back to 
void Customer::setChecked_out_books (Book checkOut) {
  checked_out_books.push_back (checkOut);
}   

//erase and element of the checked book out vector for the customer
void Customer::setChecked_in_books () { 
  checked_out_books.erase (checked_out_books.begin());
}

/*function which imports names of registered users from csv file 
  stores them into a vector of class Customer and sends to 
  libray constructor*/
std::vector<Customer> registered_customers_in_csv_file (std::string filename) {
  std::ifstream inf;
  inf.open (filename);
    if (!inf.is_open()) {
    std::cout << "Error with customer file" << std::endl;
    } 
  std::string line;
  std::string tmp_get_registered_customer;
    
  std::vector <Customer> c;
    while (std::getline (inf, line)){
      tmp_get_registered_customer = line;
  Customer tmp = (tmp_get_registered_customer);
  c.push_back (tmp);
} 
inf.close();
return c;
} 
