#include "book.h"
#include "customer.h"
#include "administrator.h"
#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <vector>
#include <string>

//funtions are in the same order in the library.cpp file
class Library {
  public:
    Library(std::string b, std::string c, std::string a);
    Library(std::string SJ_books);
    Library *SJ_State;
    std::vector <Book> getBook_database ();
    std::vector <Customer> getCustomer_database ();
    std::vector <Administrator> getAdmin_database ();
    void setSJ_State (Library *l);
    int validate_customer();
    bool validate_admin();
    void register_new_customer();
    void view_books_and_checkOut(int c);
    void check_in_book (int c);
    void print_checked_out();
  private:
    std::vector <Book> book_database;
    std::vector <Customer> customer_database;
    std::vector <Administrator> admin_database;
};

//lets the user choose a library 1 or 2 and returns that int.
int which_library();

//opening message, user selects 1 of 5 options which start switch
//in main
int menu_options_selection();

//prints out books that are checked out only admin
void print_checked_out (std::vector <Customer> c);

/*lists books current inventory
 *by title or full discription
 */
int list_books (std::vector <Book> inventory);

#endif //LIBRARY_H_
