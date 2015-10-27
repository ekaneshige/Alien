all: awaken

awaken: Game.o
	g++ -g -o awaken Game.o

Game.o: Game.cpp
	g++ -c -g Game.cpp

clean:
	rm *.o *~
