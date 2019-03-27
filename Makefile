CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Card.o Player.o Game.o 

Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) --compile Card.cpp -o Card.o

Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) --compile Player.cpp -o Player.o

TicTacToe.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) --compile Game.cpp -o Game.o

clean: 
	rm *.o a.out