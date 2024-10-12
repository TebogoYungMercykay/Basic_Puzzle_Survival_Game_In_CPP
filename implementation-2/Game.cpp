#include "Game.h"
using namespace std;

Game::Game(int w, int h, string chars)
{
    Game::map = NULL;
    Game::player = NULL;
    if (w >= 0 && h >= 0)
    {
        if (chars != "")
        {
            int size = chars.length();
            int x = 0;
            int y = 0;
            if(size == (w * h))
            {
                Game::map = new Map(w, h);
                for (int i = 0; i < size; i += 1)
                {
                    char m = chars[i];
                    if (m == '.')
                    {
                        Game::map->add(new Floor(x, y));
                    }
                    else if (m == '#')
                    {
                        Game::map->add(new Wall(x, y));
                    }
                    else if (m == '&')
                    {
                        Game::player = new Player(x, y);
                        Object* insert = new Floor(x, y);

                        insert->above = Game::player;
                        Game::player->below = insert;
                        Game::map->add(insert);
                    }
                    else
                    {
                        Game::map->add(new Object(x, y));
                    }
                    x = x + 1;
                    if (x == w)
                    {
                        x = 0;
                        y = y + 1;
                    }
                }
            }
        }
    }
}

string Game::display()
{
    string p = Game::map->print();
    return p;
}

Game::~Game()
{
    delete Game::map;
    delete Game::player;
}

void Game::update(char input)
{
    int x = 0;
    int y = 0;
    if(input != ' ')
    {
        if(input == '1')
        {
            x = -1;
            y = 1;
        }
        else if(input == '2')
        {
            x = 0;
            y = 1;
        }
        else if(input == '3')
        {
            x = 1;
            y = 1;
        }
        else if(input == '4')
        {
            x = -1;
            y = 0;
        }
        else if(input == '5')
        {
            x = 0;
            y = 0;
        }
        else if(input == '6')
        {
            x = 1;
            y = 0;
        }
        else if(input == '7')
        {
            x = -1;
            y = -1;
        }
        else if(input == '8')
        {
            x = 0;
            y = -1;
        }
        else if(input == '9')
        {
            x = 1;
            y = -1;
        }
        else
        {
            return;
        }
        if (Game::player != NULL)
        {
            Game::player->move(x, y);
        }
    }
}