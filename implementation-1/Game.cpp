#include "Game.h"

using namespace std;

// The constructor for a game instance. The third parameter is a text representation of a map.
// You need to iterate through the entire string, character by character, and determine
// 1. what object is at that position
// 2. what the x and y values are for that position.
// You can assume that the map will always be a perfect rectangle, so you can use the width and
// height values to keep track of your current ‘position’ in the iteration. Then for each character,
// add a corresponding Object to the map.
// When a player is created, it assumed that there is a floor object beneath it. The
// floor is added to the map, but the player is not, and is just assigned to the player member of
// the game for future use. The above/below links still need to be set.
Game::Game(int w, int h, string chars)
{
    map = NULL;
    player = NULL;
    exit = NULL;
    messages = NULL;
    int x = 0;
    int y = 0;
    if (chars.length() == (w * h) && w >= 0 && h >= 0)
    {
        map = new Map(w, h);
        messages = new MessageQueue(4);
        for (int i = 0; i < chars.length(); i++)
        {
            if (chars[i] == '#')
            {
                map->add(new Wall(x, y));
            }
            else if (chars[i] == '.')
            {
                map->add(new Floor(x, y));
            }
            else if (chars[i] == '&')
            {
                player = new Player(x, y);
                Object* temp = new Floor(x, y);

                temp->above = player;
                player->below = temp;
                map->add(temp);
            }
            else if (chars[i] == '^')
            {
                Object* temp = new Floor(x, y);
                Object* temp1 = new Lamp(x, y);

                temp->above = temp1;
                temp1->below = temp;
                map->add(temp);
                map->addLight(temp1);
            }
            if (chars[i] == '=')
            {
                map->add(new Door(x, y, true));
            }
            if (chars[i] == '+')
            {
                map->add(new Door(x, y, false));
            }
            else if (chars[i] == '@')
            {
                exit = new Exit(x, y);
                map->add(exit);
            }
            x++;
            if (x == w)
            {
                x = 0;
                y++;
            }
        }
        map->resetEnvironment();
        map->updateEnvironment();
    }
}

// Destructor, deletes the map and player
Game::~Game()
{
    delete map;
    delete messages;
    delete player;
}

// This displays the entire game. For now, this only returns the map display (print())
string Game::display()
{
    return messages->print() + map->print();
}

// This performs an update on the game. Move the player depending on the input. Any undefined input advances the game, but does not
// do anything else. Here it is explicitly what each
// input does to make a player move:
// – 1
// Diagonally down/left
// xDiff = -1, yDiff = 1
// – 2
// Down
// xDiff = 0, yDiff = 1
// – 3
// Diagonally down/right
// xDiff = 1, yDiff = 1
// – 4
// Left
// xDiff = -1, yDiff = 0
// – 6
// Right
// xDiff = 1, yDiff = 0
// – 7
// Diagonally up/left
// xDiff = -1, yDiff = -1
// – 8
// Up
// xDiff = 0, yDiff = -1
// – 9
// Diagonally up/right
// xDiff = 1, yDiff = -1
void Game::update(char input)
{
    int xDiff = 0;
    int yDiff = 0;
    switch (input)
    {
        case '1':
            xDiff = -1;
            yDiff = 1;
            break;
        case '2':
            xDiff = 0;
            yDiff = 1;
            break;
        case '3':
            xDiff = 1;
            yDiff = 1;
            break;
        case '4':
            xDiff = -1;
            yDiff = 0;
            break;
        case '5':
            break;
        case '6':
            xDiff = 1;
            yDiff = 0;
            break;
        case '7':
            xDiff = -1;
            yDiff = -1;
            break;
        case '8':
            xDiff = 0;
            yDiff = -1;
            break;
        case '9':
            xDiff = 1;
            yDiff = -1;
            break;
        case 'e':
            if (player != NULL)
            {
                playerInteract(player->below->prevVert);
                playerInteract(player->below->nextHoriz);
                playerInteract(player->below->prevHoriz);
                playerInteract(player->below->nextVert);
            }
            break;
        default:
            return;
    }
    if (player == NULL)
    {
        messages->addMessage(new Message("Missing player"));
    }
    else
    {
        if (map->getAt(player->getCoord(false) + xDiff, player->getCoord(true) + yDiff) != NULL && map->getAt(player->getCoord(false) + xDiff, player->getCoord(true) + yDiff)->isSolid()){
            messages->addMessage(new Message("Walked into something"));
        }
        else if (map->getAt(player->getCoord(false) + xDiff, player->getCoord(true) + yDiff) == NULL)
        {
            messages->addMessage(new Message("Out of bounds"));
        }
        else
        {
            player->move(xDiff, yDiff);
        }
    }
    map->resetEnvironment();
    map->updateEnvironment();
    if (player != NULL && exit != NULL)
    {
        if (player->below == exit)
        {
            std::string throwMe = "You reached the exit!";
            throw throwMe;
        }
    }
}
void Game::playerInteract(Object* obj)
{
    if (obj != NULL)
    {
        try
        {
            if (obj->above == NULL)
            {
                obj->interact();
            }
            else
            {
                obj->above->interact();
            }
        }
        catch(std::string e)
        {
            messages->addMessage(new Message(e));
        }
    }
}