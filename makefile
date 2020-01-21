project5: project5.o administrator.o book.o library.o customer.o 
	g++ -std=c++11 -Wall -o project5 project5.o administrator.o book.o library.o customer.o

project5.o: project5.cpp 
	g++ -std=c++11 -Wall -o project5.o -c project5.cpp

administrator.o: administrator.cpp
	g++ -std=c++11 -Wall -o administrator.o -c administrator.cpp 

book.o: book.cpp 
	g++ -std=c++11 -Wall -o book.o -c book.cpp

library.o: library.cpp
	g++ -std=c++11 -Wall -o library.o -c library.cpp

customer.o: customer.cpp
	g++ -std=c++11 -Wall -o customer.o -c customer.cpp
