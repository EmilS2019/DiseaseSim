#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"

class Game
{
    public:
        Game();
        virtual ~Game();

        void updateSFMLEvents();
        void update();
        void render();
        void run();
        void print();

    protected:

    private:
        void initWindow();
        //sf::renderWindow app*;
        sf::Event sfEvent;
};

#endif // GAME_H
