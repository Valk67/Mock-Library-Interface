#include "administrator.h" 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Administrator::Administrator (std::string u, std::string p) 
  : admin_username(u), admin_password(p) {} 

std::string Administrator::getAdmin_username() {
  return admin_username;
} 

std::string Administrator::getAdmin_password() {
  return admin_password;
} 

/*fstrems a admin csv file and loads it into a vector
  of class administrator, these get passed to constructor
  which sets 2 private strings a password and username*/ 
std::vector<Administrator> admin_in_csv_file (std::string filename) {
  std::ifstream inf;
  inf.open (filename);
    if (!inf.is_open()){
    std::cout << "Error with admin files" << std::endl;
    }
  std::string line;
  std::string tmp_administrator;
  std::string tmp_password;
  std::vector <Administrator> a;
    while (std::getline (inf, line)){
    std::istringstream ss(line);
      std::getline(ss, tmp_administrator, ',');
      ss.ignore();
      std::getline (ss, tmp_password);

    Administrator tmp = Administrator (tmp_administrator, tmp_password);
    a.push_back (tmp);
    } 
  inf.close();
return a;
}

