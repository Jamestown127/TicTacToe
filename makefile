TicTacToe: driver.o
	g++ -o TicTacToe driver.o

driver.o: driver.cpp
	g++ -c driver.cpp
