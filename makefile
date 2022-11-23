main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	./main

tar:
	tar -cvz *.h *.cpp -f Puzzle_Game.tar.gz

untar_gz:
	tar -zxvf *.tar.gz