#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_
#include <vector>
#include <string>

class Administrator {
  public:
    Administrator (std::string u, std::string p);
    std::string getAdmin_password();
    std::string getAdmin_username();
  private:
    std::string admin_username;
    std::string admin_password;
};

//a fucntion that uses fstream to import a csv file of 
//usernames and passwords
std::vector< Administrator> admin_in_csv_file (std::string filename);

#endif //ADMINISTRATOR_H_
