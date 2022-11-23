// /******************************************************//*
// 	   Tebogo - Assignment 3 - Part 2 Testing Main 
//        Do Not Include The Main In Your Submission 
// 	   The Expected Output Starts From Line: 176
// *//*
// 	There is still a lot to test on your own! 
// 	 - Remember NOT to use namespace std; in h files
// 	 - If a class does not ask for a destructor, DO NOT MAKE ONE! 
// 	 - Check SPELLING!
// *//*
// 	NB:= The Makefile deletes main.cpp if it's in the directory before creating the .tar file.
// 	makefile:

// 	main:
// 		g++ -g *.cpp -std=c++98 -pedantic -o main

// 	clean:
// 		rm -f *.o *.tar.gz main
// 		reset
// 		clear

// 	run:
// 		./main

// 	tar:
// 		rm -f main.cpp
// 		tar -cvz *.h *.cpp -f uXXXXXXXX_Assignment_3.tar.gz
// */
// #include <iostream>
// #include "Game.h"

// using namespace std;
// static void Message_X_MessageQueue();
// static void testing_Map_Class();
// static void Basic_Map();
// static void Test_Walls();
// static void More_Interesting_Map_For_Lighting();
// static void Lights_And_A_Door();

// int main(){
// 	Message_X_MessageQueue();
// 	testing_Map_Class();
// 	Basic_Map();
// 	Test_Walls();
// 	Lights_And_A_Door();
// 	More_Interesting_Map_For_Lighting();
// }
// static void testing_Map_Class(){
// 	cout<<" ------------- Map Constructor ------------- "<<endl;
// 	/*
// 	Example Map:
// 		####
// 		#..#
// 		#&.#
// 		####
// 	*/
// 	cout<<" ---- Tests both (rows) & (columns) --- "<<endl;
// 	Map* mapPtr = new Map(4, 4);
// 	mapPtr->add(new Wall(3, 0));
// 	mapPtr->add(new Wall(3, 1));
// 	mapPtr->add(new Exit(3, 2));
// 	mapPtr->add(new Wall(3, 3));
// 	mapPtr->add(new Wall(0, 0));
// 	mapPtr->add(new Object(0, 1));
// 	mapPtr->add(new Lamp(0, 2));
// 	mapPtr->add(new Wall(0, 3));
// 	mapPtr->add(new Wall(1, 0));
// 	mapPtr->add(new Floor(1, 1));
// 	mapPtr->add(new Floor(1, 2));
// 	mapPtr->add(new Wall(1, 3));
// 	mapPtr->add(new Wall(2, 0));
// 	mapPtr->add(new Player(2, 1));
// 	mapPtr->add(new Floor(2, 2));
// 	mapPtr->add(new Wall(2, 3));
// 	cout<<" ----------- (Print) ----------- "<<endl;
// 	cout<<mapPtr->print();
// 	cout<<mapPtr->getAt(2,1)->getIcon() << endl;
// 	cout<<mapPtr->getAt(0,1)->getIcon() << endl;
// 	cout<<mapPtr->getAt(0,2)->getIcon() << endl;
// 	cout<<mapPtr->getAt(1,3)->getIcon() << endl;
// 	cout<<mapPtr->getAt(2,2)->getIcon() << endl;
// 	cout<<mapPtr->getAt(3,2)->getIcon() << endl;
// 	cout<<" ----------- D O N E ----------- "<<endl;
// 	/*
// 		#?^#
// 		#..#
// 		#&.#
// 		##@#
// 		&
// 		?
// 		^
// 		#
// 		.
// 		@
// 	*/	
// }

// void Message_X_MessageQueue(){
// 	//Feel free to comment out the Game reference in the main, and add tests for individual classes here
// 	//Before you put everything together
// 	MessageQueue queue(1);
// 	cout<<"0. "<<endl<<queue.print()<<endl;
// 	queue.addMessage(new Message("Message 1"));
// 	queue.addMessage(new Message("Message 2"));
// 	cout<<"1. "<<endl<<queue.print()<<endl;
// 	queue.addMessage(new Message("Message 3"));
// 	cout<<"2. "<<endl<<queue.print()<<endl;
// 	cout<<"3. "<<endl<<queue.print()<<endl;
// 	cout<<"4. "<<endl<<queue.print()<<endl;
// 	/*
// 		0.       

// 		1.       
// 		Message 1
// 		Message 2

// 		2.
// 		Message 2
// 		Message 3

// 		3.
// 		Message 3

// 		4.
// 	*/
// }

// static void Basic_Map(){
// 	const int w = 31;
// 	const int h = 12;
// 	string array =
// 	"###############################"
// 	"#.............................#"
// 	"#.............................#"
// 	"#........^....................#"
// 	"#.............................#"
// 	"#.............................#"
// 	"#.............................#"
// 	"#.............................#"
// 	"#..............^..............#"
// 	"#.............................#"
// 	"#.............................#"
// 	"###############################";

// 	Game* game = new Game(w, h, array);


// 	cout<<game->display()<<endl;
// 	bool running = true;
// 	string mess = "";
// 	int k = 0;
// 	while (running){
// 		char action;
// 		if(k++ == 0) action = '5';
// 		else{ action = 'q'; }
// 		// cin>>action;
// 		if (action == 'q') //Quit
// 			break;
// 		try{
// 			game->update(action);
// 		}
// 		catch(string m){
// 			mess = m;
// 			running = false;
// 		}
// 		cout<<game->display()<<endl;
// 	}
// 	cout<<endl<<mess<<endl;
// }

// static void Test_Walls(){
// 	const int w = 19;
// 	const int h = 7;
// 	string array =
// 	"###^###############"
// 	"#................^#"
// 	"###.#########....##"
// 	"#.....#.....#.....#"
// 	"#.....###.###.....#"
// 	"#.......#.#.......#"
// 	"#########^#########";

// 	Game* game = new Game(w, h, array);


// 	cout<<game->display()<<endl;
// 	bool running = true;
// 	string mess = "";
// 	int k = 0;
// 	while (running){
// 		char action;
// 		if(k++ == 0) action = '5';
// 		else{ action = 'q'; }
// 		// cin>>action;
// 		if (action == 'q') //Quit
// 			break;
// 		try{
// 			game->update(action);
// 		}
// 		catch(string m){
// 			mess = m;
// 			running = false;
// 		}
// 		cout<<game->display()<<endl;
// 	}
// 	cout<<endl<<mess<<endl;
// }

// static void Lights_And_A_Door(){
// 	const int w = 19;
// 	const int h = 4;
// 	string array =
// 	"###################"
// 	"^&......+.........@"
// 	"^.......#.........#"
// 	"#############^#####";

// 	std::cout << "--- Here ---" << std::endl; 
// 	Game* game = new Game(w, h, array);

// 	cout<<game->display()<<endl;
// 	bool running = true;
// 	string mess = "";
// 	int k = 0;
// 	std::string p20 = "666662738196666e6622228888664666666666";
// 	while (running){
// 		char action;
// 		action = p20[k++];
// 		// cin>>action;
// 		if (action == 'q') //Quit
// 			break;
// 		try{
// 			game->update(action);
// 		}
// 		catch(string m){
// 			mess = m;
// 			running = false;
// 		}
// 		cout<<game->display()<<endl;
// 	}
// 	cout<<endl<<mess<<endl;
// }

// static void More_Interesting_Map_For_Lighting(){
// 	const int w = 17;
// 	const int h = 6;
// 	string array =
// 	"#########^#######"
// 	"^&......#..+....^"
// 	"^....#..#..#....#"
// 	"^....#..#..#....@"
// 	"^....#..+..^..#+#"
// 	"###############^#";
// 	int k = 0;
// 	std::string p20 = "666662226e666888e663336e6";
// 	Game* game = new Game(w, h, array);

// 	cout<<game->display()<<endl;
// 	bool running = true;
// 	string mess = "";
// 	while (running){
// 		char action;
// 		// cin>>action;
// 		action = p20[k++];
// 		if (action == 'q') //Quit
// 			break;
// 		try{
// 			game->update(action);
// 		}
// 		catch(string m){
// 			mess = m;
// 			running = false;
// 		}
// 		cout<<game->display()<<endl;
// 	}
// 	cout<<endl<<mess<<endl;
// }

// //Expected output for:
// //runTest()
// /*
// ./main
// 0.

// 1.
// Message 1
// Message 2

// 2.
// Message 2
// Message 3

// 3.
// Message 3

// 4.

//  ------------- Map Constructor ------------- 
//  ---- Tests both (rows) & (columns) ---      
//  ----------- (Print) -----------
// ####
// ?.&#
// ^..@
// ####
// &
// ?
// ^
// #
// .
// @
//  ----------- D O N E -----------
//          #     #
//         ...   ...
//  ............................
// #........^....................
//  ............................
//         ...   ...
//         ...   ...
//  .............................
// #..............^..............#
//  .............................
//         ...   ...
//          #     #

// Missing player
//          #     #
//         ...   ...
//  ............................
// #........^....................
//  ............................
//         ...   ...
//         ...   ...
//  .............................
// #..............^..............#
//  .............................
//         ...   ...
//          #     #



//  ##^##############
// #................^#
//  ##.#########....#
//   ...   ...
//   ...   #.#
//   ...   #.#
//    #    #^#

// Missing player
//  ##^##############
// #................^#
//  ##.#########....#
//   ...   ...
//   ...   #.#
//   ...   #.#        
//    #    #^#



// --- Here ---
// ########     #
// ^&......+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^.&.....+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^..&....+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^...&...+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^....&..+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^.....&.+   ...
// ^.......#   ...
// ########    #^#    

// ########     #
// ^.......+   ...
// ^.....&.#   ...
// ########    #^#

// ########     #
// ^....&..+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^.......+   ...
// ^.....&.#   ...
// ########    #^#

// ########     #
// ^.....&.+   ...
// ^.......#   ...
// ########    #^#

// ########     #
// ^.......+   ...
// ^....&..#   ...
// ########    #^#

// ########     #
// ^.....&.+   ...
// ^.......#   ...
// ########    #^#

// ########     #     
// ^......&+   ...
// ^.......#   ...
// ########    #^#

// Walked into something
// ########     #
// ^......&+   ...
// ^.......#   ...
// ########    #^#

// Walked into something
// Walked into something
// ########     #
// ^......&+   ...
// ^.......#   ...
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// ########     #
// ^......&+   ...
// ^.......#   ...
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// You opened a door
// ###################
// ^......&=.........@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// You opened a door
// ###################
// ^.......&.........@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// You opened a door
// ###################
// ^.......=&........@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// You opened a door
// ###################
// ^.......=.........@
// ^.......#&........#
// ########    #^#

// Walked into something
// Walked into something
// You opened a door
// Walked into something
// ###################
// ^.......=.........@
// ^.......#&........#
// ########    #^#

// Walked into something
// You opened a door
// Walked into something
// Walked into something
// ###################
// ^.......=.........@
// ^.......#&........#
// ########    #^#

// Walked into something
// You opened a door
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=.........@
// ^.......#&........#
// ########    #^#

// Walked into something
// You opened a door
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=&........@
// ^.......#.........#
// ########    #^#

// Walked into something
// You opened a door
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=&........@
// ^.......#.........#
// ########    #^#

// You opened a door
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=&........@
// ^.......#.........#
// ########    #^#

// You opened a door
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=&........@
// ^.......#.........#
// ########    #^#

// You opened a door
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=.&.......@
// ^.......#.........#
// ########    #^#

// You opened a door
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=..&......@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=.&.......@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=..&......@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=...&.....@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=....&....@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=.....&...@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=......&..@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=.......&.@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=........&@
// ^.......#.........#
// ########    #^#

// Walked into something
// Walked into something
// Walked into something
// Walked into something
// ###################
// ^.......=.........&
// ^.......#.........#
// ########    #^#


// You reached the exit!
// #########^# #####
// ^&......#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^.&.....#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^..&....#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^...&...#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^....&..#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^.....&.#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^.......#..+....^
// ^....#&.#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#  #..#..
// ^....#  +..^..#+
// #####    ######^#

// You opened a door
// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#..#..#..
// ^....#.&=..^..#+
// ##### #########^#

// You opened a door
// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#..#..#..
// ^....#..&..^..#+
// ##### #########^#

// You opened a door
// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#..#..#..
// ^....#..=&.^..#+
// ##### #########^#

// You opened a door
// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#..#..#..
// ^....#..=.&^..#+
// ##### #########^#

// #########^# #####
// ^.......#..+....^
// ^....#..#.. ....#
// ^....#..#.&#..
// ^....#..=..^..#+
// ##### #########^#

// #########^# #####
// ^.......#..+....^
// ^....#..#.& ....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// #########^# #####
// ^.......#.&+....^
// ^....#..#.. ....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// You opened a door
// #########^#######
// ^.......#.&=....^
// ^....#..#..#....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// You opened a door
// #########^#######
// ^.......#..&....^
// ^....#..#..#....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// You opened a door
// #########^#######
// ^.......#..=&...^
// ^....#..#..#....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// #########^#######
// ^.......#..=....^
// ^....#..#..#.&..#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// #########^#######
// ^.......#..=....^
// ^....#..#..#....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// Walked into something
// #########^#######
// ^.......#..=....^
// ^....#..#..#....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// Walked into something
// #########^#######
// ^.......#..=....^
// ^....#..#..#....#
// ^....#..#..#..
// ^....#..=..^..#+
// ##### #########^#

// Walked into something
// You opened a door
// #########^#######
// ^.......#..=....^
// ^....#..#..#....#
// ^....#..#..#...&@
// ^....#..=..^..#=#
// ##### #########^#

// You opened a door
// #########^#######
// ^.......#..=....^
// ^....#..#..#....#
// ^....#..#..#....&
// ^....#..=..^..#=#
// ##### #########^#


// You reached the exit!
// */