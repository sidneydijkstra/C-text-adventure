all:
	g++ parser.cpp person.cpp player.cpp command.cpp commandwords.cpp food.cpp game.cpp inventory.cpp item.cpp main.cpp room.cpp -g -o zuul


clean:
	rm zuul
