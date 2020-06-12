#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rectangle.h"
#include "Matrix.h"
#define LOG(x) std::cout << x << std::endl
#include <math.h>

#include "Rectangle.h"
#include "Math.h"

sf::RenderWindow app(sf::VideoMode(1000, 1000), "Disease Simulator", sf::Style::Close);

Math math;

float values[2]= {4,42};
int const rectangles = 100;
Rectangle recs[rectangles];
int n = 0;

int const numberOfRotations = 50;
double norm[numberOfRotations] = {};
int rot = 0;

void init()
{
    LOG("Yee haw howdy partner");

    //Matrix mtrx(values);

    for (int i=0; i<rectangles; i++)
    {
        recs[i]=Rectangle(rand()%(50+950), rand()%(50+950), 20, 20, sf::Color(200,110,120));
        recs[i].setVelocity(0.005,0.004);
    }

    math.normal(numberOfRotations, norm);


    recs[6].changeCondition(recs[6].sick);
}
Rectangle line = Rectangle(100,100,1,400,sf::Color(255,255,255));


void update()
{
    if (n%100 == 0)
    {
        //float dist = math.getDistance(recs[0].x, recs[0].y, recs[1].x, recs[1].y);
        /*line.height = abs(recs[1].y-recs[0].y);
        line.width = abs(recs[1].x-recs[0].x);
        line.x = std::min(recs[0].x, recs[1].x);
        line.y = std::min(recs[0].y, recs[1].y);*/

        for (int i=0;i<100;i++)
        {
            if (recs[i].condition == recs[0].sick)
            {
                recs[i].sneeze(100, 100, recs);
            }
        }
    }
        //app.draw(line.getRect());

    for (int i=0; i<rectangles; i++)
    {
        //re.rotateRect(norm[rot]);
        recs[i].Move(recs[i].velVector[0],recs[i].velVector[1]);
        app.draw(recs[i].getRect());
        recs[i].avoidEdge();
    }

    if (n%20 == 0)
    {
        int X = rand()%rectangles;
        recs[X].randomRotation(3, norm[rot]);
        if (rot < numberOfRotations){rot++;} else{rot=0;}
    }
    n++;
}

//sf::RenderWindow app2(sf::VideoMode(500, 500), "Options menu", sf::Style::Close);

int main()
{
    init();
    while (app.isOpen())
    {
        app.clear();

        update();

        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
        // Update the window
        app.display();


        //weird test
        /*while (app2.isOpen())
        {
             sf::Event event;
            while (app2.pollEvent(event))
            {
                // Close window : exit
                if (event.type == sf::Event::Closed)
                    app2.close();
            }
            // Update the window
            app2.display();
        }*/
    }

    return EXIT_SUCCESS;
}

