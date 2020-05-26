#include <SFML/Graphics.hpp>
#include <iostream>
#include <Game.h>
#include "Rectangle.h"
#include "Matrix.h"
#define LOG(x) std::cout << x << std::endl
#include <math.h>

#include <random>
void normaldist()
{
    const int nrolls=3;  // number of experiments
    const int nstars=100;    // maximum number of stars to distribute

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(5.0,2.0);

    int p[10]={};

    for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
    }

    std::cout << "normal_distribution (5.0,2.0):" << std::endl;

    for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
    }
    LOG()
}


int main()
{
    stuff();
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

    Rectangle rec = Rectangle(500,100,20,20,sf::Color(200,100,150));
    rec.setVelocity(0.002,0.002);

	const float PI = 3.1415693;

    int n = 0;

    for (int i=0; i<30; i++)
    {
        //LOG(rand()%6);

    }
	// Start the game loop
    while (app.isOpen())
    {
        app.clear();

        if (n%10000==0)
        {
            float angleChange = 3.14;
            rec.rotateRect(3.1415/2);
            LOG(rec.getSpeed());
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

