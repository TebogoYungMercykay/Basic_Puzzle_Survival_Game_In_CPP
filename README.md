# Basic Puzzle Survival Game In C++

## Description

This is a small-scale puzzle survival game that runs in the terminal, using C++. The game features a map containing various elements:

- Floors
- Walls
- Doors
- Lights
- An exit
- A playable character

The goal of the game is to navigate the playable character through the level and reach the exit.

A testing main for the game is also included for illustration purposes.

## Requirements before running codes:

- Install an IDE that compiles and runs C++ codes. Recommendation: VS Code
- For WSL users: How to setup WSL Ubuntu terminal shell and run it from Visual Studio Code: [YouTube Tutorial](https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s)

## Makefile

A Makefile is included to compile and run the codes on the terminal with the following commands:

- `make clean`
- `make`
- `make run`
- Input (if required). 'q' is for quitting the game.

Here's the content of the Makefile:

```makefile
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

## How to Run

1. Ensure you have a C++ compiler and Make installed on your system.
2. Clone or download this repository to your local machine.
3. Open a terminal and navigate to the project directory.
4. Run the following commands in order:
   ```
   make clean
   make
   make run
   ```
5. Follow the on-screen instructions to play the game.
6. To quit the game at any time, input 'q'.

## Contributing

This project is primarily for personal learning and demonstration purposes. However, if you have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is open source. Please check the repository for any specific license information.
