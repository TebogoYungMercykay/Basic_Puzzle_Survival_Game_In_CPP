________________________________________________________________________________________

#                    Basic_Puzzle_Survival_Game_In_CPP                               
________________________________________________________________________________________
 ## Description
 
 - This is a small-scale puzzle survival game that runs in the terminal, using C++.
There is a map in the game containing floors, walls, doors, lights an exit and of course, a playable character.
The goal of the game is to reach the end of the level (the exit).

 - I also included a testing main for the game, Just for illustration.
________________________________________________________________________________________
- ### Requirements before running codes:
    - Install an IDE that compiles and runs C++ codes. Recommendation VS Code
    - How to setup WSL Ubuntu terminal shell and run it from Visual Studio Code: https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s
________________________________________________________________________________________
 ## Makefile
 ##### NB: A makefile Is Included to compile and run the codes on the terminal with the following commands:=
- make clean
- make
- make run
- input (if required). q is for quitting the game.

```C++
main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Puzzle_Game.tar.gz
	
untar:
	tar -zxvf *.tar.gz
```
________________________________________________________________________________________
