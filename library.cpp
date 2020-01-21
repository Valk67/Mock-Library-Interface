#include "library.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//***!!!!Note funcions are in the same order as header file.

//constructor for library which automattically stores
//3 vectors of books customers and admin
Library::Library (std::string b, std::string c, std::string a) { 
  book_database = books_in_csv_file (b);
  customer_database = registered_customers_in_csv_file (c);
  admin_database = admin_in_csv_file (a);
} 

/*constructor used for other library i.e. SJ only takes in 
  a book file since our given customer and admin files pretain to
  chico.*/
Library::Library (std::string SJ_books) {
  book_database = books_in_csv_file (SJ_books);
} 

std::vector <Book> Library::getBook_database() {
  return book_database;
}
 
std::vector <Customer> Library::getCustomer_database() {
  return customer_database;
}

std::vector <Administrator> Library::getAdmin_database() {
  return admin_database;
}

void Library::setSJ_State (Library *l) {
  SJ_State = l;
} 

/*validate customer checks to see if they are indeed registered, 
  returns -1 if they are not registered.*/
int Library::validate_customer() {
  std::string verify_name;
  std::cout << "Enter login information." << std::endl;
  std::cin >> verify_name;
  for (int i = 0; i < customer_database.size(); i++) {
    if (verify_name == customer_database[i].getRegistered_customer() ) {
    return i;
    }
  }
return -1;
}

/*validates admin by checking an entered pass and username.*/
bool Library::validate_admin() {
  std::string login;
  std::string password;
  std::cout << "Please provide login id." << std::endl;
  std::cin >> login;
  std::cout << "Please provide password." << std::endl;
  std::cin >> password;
  for (int i = 0; i < admin_database.size (); i++) {
    if ( (login == admin_database[i].getAdmin_username()) && (
          password == admin_database[i].getAdmin_password()) ) {
    return true;
    }
  }
std::cout << "Invalid admin login" << std::endl;
return false;
}

//function that adds a new customer to csv file
void Library::register_new_customer() {
  std::string name_input;
  std::cout << "Enter first name to register to the library." <<std::endl;
  std::cin >> name_input;

  std::ofstream outf;
  outf.open("chico_customers.csv");
    if (!outf.is_open()) {
    std::cout << "Error with customer file" << std::endl;
    }
  //call constructor to create a new instance of a person
  Customer tmp = Customer (name_input);
  customer_database.push_back (tmp);
  for (int i = 0; i < customer_database.size(); i++) {
  outf << customer_database[i].getRegistered_customer() << std::endl;
  }
  outf.close();
  std::cout << "You must now log back into the system, "
            << "using ./project5" << std::endl;
}

/*lists all the available books 
  lists in full or just title depending on selection
  after books are listed fuction asks which book they would like to
  check out and then that number is returned by the integer fuction 
  and stored in main. note at the end the integer is subtracted by 1
  since the element of the book they choose was stored in order from
  0, 1 , 2 etc but they had options 1, 2, 3 etc 
 */
void Library::view_books_and_checkOut (int c) {
  int b_selected;
  bool end = false;
  while (!end) {
  int library_selection = which_library();
  switch (library_selection) {
    case 1: { 
      b_selected = list_books (book_database);
      bool in = book_database[b_selected].getInstock();
      if (in == true) {
        customer_database[c].setChecked_out_books(book_database[b_selected]);     
        book_database[b_selected].setInstock (false);
        std::cout << "Book Checked out, better bring it back!" << std::endl;
        end = true;
      } else {
        std::cout << "Sorry, book already checked out at Chico." << std::endl;
        std::cout << '\n';
      } 
    break;
    } 
    case 2: {
      b_selected = list_books (SJ_State->book_database);
      bool in = SJ_State->book_database[b_selected].getInstock();
      if (in == true) {
        customer_database[c].setChecked_out_books (SJ_State->book_database[b_selected]);
        SJ_State->book_database[b_selected].setInstock(false);
        std::cout << "Book from SJ checked out, better bring it back!" << std::endl;
        end = true;
       } else {
         std::cout << "Sorry book already checked out at SJ." << std::endl;
         std::cout << '\n';
       }
     break;
     }
     default:
     std::cout << "Not a valid selection" << std::endl;
     break;
  } 
  }
} 

/*function ID's which library they checked out a book from then once 
  the enter the number value of the book they rented it is subtracted
  since list book also does the same thing when they checked out a book.
  then it checks that book to see if its actually is checked out and 
  if it is sets the book to true and ends the function. */
void Library::check_in_book (int cus_int) {
  std::cout << "Which library does the book belong to?" << std::endl;
  std::cout << "Enter 1 for Chico or 2 for San Jose State." << std::endl;
  int library_selection;
  int book_num;
  std::cin >> library_selection;
  std::cout << "Please enter the book value you rented, i.e. 1,2,3." << std::endl;
  std::cin >> book_num;
  book_num--;
  switch (library_selection) {
    case 1: {
      bool instock = book_database[book_num].getInstock();
      if (instock == false) {
        book_database[book_num].setInstock (true);
        customer_database[cus_int].setChecked_in_books();
        std::cout << "Book is back in stock at chico!" << std::endl;
        std::cout << '\n';
      } else { 
        std::cout << "Your a liar we have that book!!" << std::endl;
      } 
    break;
    }
    case 2: {
      bool instock = SJ_State->book_database[book_num].getInstock();
      if (instock == false) {
        SJ_State->book_database[book_num].setInstock (true);
        customer_database[cus_int].setChecked_in_books();
        std::cout << "SJ book is back in stock." << std::endl;
        std::cout << '\n';
      } else { 
        std::cout << "Your a liar we have that book!!" << std::endl;
      } 
    break;
    } 
    default:
      std::cout << "Not a valid selection." << std::endl;
  } 
}

//admin function that reads back customers with a book below their 
//name if they have any  checked out.
void Library::print_checked_out() {
  int number_input;
  std::cout << "Press 1 to see checked out books." << std::endl;
  std::cin >> number_input;
  if (number_input == 1) {
    for (int i = 0; i < customer_database.size(); i++) { 
    std::cout << customer_database[i].getRegistered_customer() << std::endl;
      for (int k = 0; k < customer_database[i].getChecked_out_books().size() ; k++) {  
      std::cout << customer_database[i].getChecked_out_books()[k].getTitle() << std::endl;
      } 
    std::cout << '\n';
    } 
  std::cout << "Displayed are registered users, and the books" << std::endl;
  std::cout << "they have checked out below their name." << std::endl;
  std::cout << "RETURNING TO MAIN MENU" << std::endl;
  } 
}

//simple function returns a number regarding to what they chose
int which_library() {
  bool end = false;
  int library_choice;
  while (!end) {
  std::cout << "Would you like to view Brad's Library or San Jose State's?" << std::endl;
  std::cout << "Enter 1 for Brad's or 2 for San Jose State's."  << std::endl; 
  std::cin >> library_choice;
  end = true;
  } 
return library_choice;
} 

//menu options which return an int then used in the main switch function
int menu_options_selection() { 
  std::cout << '\n';
  std::cout << "Enter 1 to register, 2 for existing customer," <<std::endl;
  std::cout << "3 for administrator access, 4 to return " << std::endl;
  std::cout << "a book, or 5 to exit program." << std::endl;
  int number_input;
  std::cin >> number_input;
return number_input;
}

/*function that is used to list any librarys books, gives the user the option
  or by full discription. Note books are displayed in a plus one order to 
  their vector element number.  and once the user chooses a number to rent
  that number is decreased by 1 since the int I wish to have retruned is 
  the vector element number.*/
int list_books (std::vector <Book> inventory) { 
  bool end = false;
  int book_number;
  while (!end) {
  std::cout << "Enter 1 to list books by title or 2 for "
            << "full book discription." << std::endl;
  int number_input;
  std::cin >> number_input;
  std::cout << '\n';
  if (number_input == 1 || number_input == 2) {
    for (int i = 0; i < inventory.size(); i++) {
      std::cout << i+1 << " " << inventory[i].getTitle() << std::endl;
      if (number_input == 2) { 
        std::cout << inventory[i].getAuthor() << std::endl;
        std::cout << inventory[i].getPublisher() << std::endl;
        std::cout << inventory[i].getYear() << std::endl;
      }
      std::cout << '\n'; 
    }  
    if (number_input == 2) {
      std::cout << "ATTENTION! Books are listed in"
                << " order of Title, Author, publisher, year."
                << std::endl;
    } else { 
      std::cout << "ATTENTION! Books are Listed by"
                << " title." 
                << std::endl;
    }   
  std::cout << "Each book top to bottom is stored in a number format " << std::endl;
  std::cout << "as seen above, enter the number for the book you are " << std::endl;
  std::cout << "book you are checking out." << std::endl;
  std::cin >> book_number;
  end = true;
  } else {
    std::cout << "not a valid selection" << std::endl;
  } 
  //while loop end }
  }
  book_number--; 
return book_number;
}  
 
