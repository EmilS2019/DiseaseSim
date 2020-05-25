#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>
#include "Rectangle.h"
#include "Matrix.h"
#define LOG(x) std::cout << x << std::endl
#include <math.h>

int main()
{
    LOG("Yee haw howdy partner");
    /*int test = 5;
    void* ptr = &test;
    LOG(ptr);*/
    // Create the main window

    /*int t[4] = {1,2,3,4};
    int (*ptr)[4] = &t;
    //LOG(ptr);

    float arr[4] = {1,2,3,65};*/
    //LOG(getThird(arr));
    //LOG(arr[3]);

    float values[2]= {4,42};
    Matrix mtrx(values);
    //LOG((mtrx+mtrx).values[0]);

    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    Rectangle rec = Rectangle(100,500,20,20,sf::Color(200,100,150));
    rec.setVelocity(0.003,0.0008);

	const float PI = 3.1415693;

    int n = 0;

	// Start the game loop
    while (app.isOpen())
    {
        app.clear();

        if (n%3000==0)
        {
            float angleChange = 3.14;
            rec.rotateRect(0.31415);
            LOG(rec.velVector[0]+rec.velVector[1]);
            //LOG(rec.getSpeed());
        }
        n++;
        rec.Move(rec.velVector[0],rec.velVector[1]);
        app.draw(rec.getRect());

        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }


        for (int i=0; i<10; i++)
        {
            Rectangle rect = Rectangle(i*50.f,0,40,40,sf::Color(255-i*10,255,255));
            app.draw(rect.getRect());
        }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

