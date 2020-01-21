// BRADLEY SUNDSBARM CS111 PROJECT5
#include "library.h"
#include <iostream>
#include <string>
#include <vector>

int main () {
  Library abc = Library ("chico_books.csv", "chico_customers.csv",
                         "chico_administrators.csv");
  Library SJ_abc = Library ("other_books.csv");
  
  abc.setSJ_State (&SJ_abc);
  
  bool end = false;
  std::cout << '\n';
  std::cout << "Welcome to Chico's Library!" << std::endl;
  while (!end) {
    
  //menu_options gives user 5 options returns the int selected and
  //selects which case to be use in switch
  int selection = menu_options_selection(); 
  
  switch (selection) {
    case 1: {
      //registers a new customer and ofstreams it to csv file 
      abc.register_new_customer();

      end = true;
      break;
    }  
    case 2: {
      /*validate customer validates a name by comparing to a vector of 
        other names if it matches it returns that vector element number
        if not the function returns -1.*/  
      /*view_books_and_checkout lets the user view the book library of 
        their choice and then once they choose a book it sets the book to 
        checked out via bool = false. */
      int customer_int = abc.validate_customer();
      if (customer_int >= 0) {
        abc.view_books_and_checkOut (customer_int);
      }  else {
          std::cout << '\n'; 
          std::cout << "login not found, try again or select " 
                    << "1 to register." << std::endl;
      }
     break;
     }//ends case 2 function
     case 3: {
       /*validate admin takes a login and password and returns true or false
         true then gives admin the option to see checked out books*/
       bool permission = abc.validate_admin();
       if (permission == true) {
         abc.print_checked_out();
       }  
     break;
     }//ends case 3   
     case 4: {  
       //returns: validates customer then once validated it asks which book they
       //checked out and then sets the book to back in stock via bool
       int customer_int = abc.validate_customer();
       if (customer_int >=0) {
         abc.check_in_book (customer_int);
       } else { 
          std::cout << "Invalid login for book return." << std::endl;
       } 
     break;
     }
     case 5: { 
     //just an option to exit program to avoid ctrl c.
     end = true;
     } 
     default:
       if (selection != 5) {
       std::cout << "Not a valid selection" << std::endl;
       } 
     break; 
  } //switch
  }//while 
return 0;
} //main
        
