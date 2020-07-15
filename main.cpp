#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rectangle.h"
#include "Matrix.h"
#define LOG(x) std::cout << x << std::endl
#include <math.h>
#include "Math.h"
#include "Timing.h"

int screenWidth = 900;
int screenHeight = 900;

sf::RenderWindow app(sf::VideoMode(screenWidth, screenHeight), "Disease Simulator", sf::Style::Close);

Math math;

float values[2]= {4,42};
int const rectangles = 100;
Rectangle recs[rectangles];
int n = 0;

int const numberOfRotations = 50;
double norm[numberOfRotations] = {};
int rot = 0;
float initialSpeed = 0.4;
float immunityRate = 4;
float deathRate = 2;


void init()
{
    LOG("Yee haw howdy partner");

    //Matrix mtrx(values);

    for (int i=0; i<rectangles; i++)
    {
        recs[i] = Rectangle(rand()%(50+(screenWidth-50)), rand()%(50+(screenHeight-50)), 20, 20, sf::Color(200,110,120));
        float xvel = rand()%10;
        float yvel = rand()%10;

        recs[i].setVelocity(0.01-xvel/(50/initialSpeed), 0.01-yvel/(50/initialSpeed));
    }

    math.normal(numberOfRotations, norm);


    recs[6].changeCondition(recs[6].sick);

}

float sneezeSpeed = 0.2;

bool animationForRecI[rectangles];

void sneezeAnimation(int x, int y, float sneezeRadius, int i)
{
    recs[i].sneezeRadius += sneezeSpeed;
    if (sneezeRadius < 100)
    {
        sf::CircleShape circle(sneezeRadius);
        circle.setFillColor(sf::Color(200,255,200,200-sneezeRadius*2));
        circle.setPosition(sf::Vector2f(x-sneezeRadius, y-sneezeRadius));
        app.draw(circle);
    }
    else
    {
        animationForRecI[i] = false;
        recs[i].sneezeRadius = 0;
    }

}
#include <fstream>

void update()
{
    for (int i=0;i<100;i++)
    {
        if (recs[i].condition == recs[0].sick && rand()%2000 == 1)
        {
            recs[i].sneeze(100, rectangles, recs);
            animationForRecI[i] = true;

            if (recs[i].health > 0) {recs[i].health -= deathRate;}
            else {
                recs[i].changeCondition(Rectangle::dead);
            }
        }

        if (animationForRecI[i] == true)
        {
            sneezeAnimation(recs[i].x, recs[i].y, recs[i].sneezeRadius, i);
        }


        if (recs[i].condition == Rectangle::sick && rand()%2000 == 1)
        {
            recs[i].immunity += immunityRate;

            if (recs[i].immunity >= 10)
            {
                recs[i].changeCondition(Rectangle::immune);
            }
        }
    }


    for (int i=0; i<rectangles; i++)
    {
        recs[i].Move(recs[i].velVector[0],recs[i].velVector[1]);
        app.draw(recs[i].getRect());
        recs[i].avoidEdge(screenWidth, screenHeight);
    }

    if (n%20 == 0)
    {
        int X = rand()%rectangles;
        recs[X].randomRotation(3, norm[rot]);
        if (rot < numberOfRotations){rot++;} else{rot=0;}
    }

    if (n%50 == 0)
    {
        int statistics[4];
        for (int i = 0; i<rectangles; i++)
        {
            statistics[0]+=(recs[i].condition == Rectangle::suceptible);
            statistics[1]+=(recs[i].condition == Rectangle::sick);
            statistics[2]+=(recs[i].condition == Rectangle::immune);
            statistics[3]+=(recs[i].condition == Rectangle::dead);
        }

        LOG(statistics[1]);
    }
    n++;


}

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//This copy-paste code somehow makes the rest of the simulation non-deterministic. Don't ask why.
int test()
{
    unsigned long j;
    srand( (unsigned)time(NULL) );

    for( j = 0; j < 100; ++j )
    {
        int n;

        /* skip rand() readings that would make n%6 non-uniformly distributed
          (assuming rand() itself is uniformly distributed from 0 to RAND_MAX) */
        while( ( n = rand() ) > RAND_MAX - (RAND_MAX-5)%6 )
        { /* bad value retrieved so get next one */ }

        //printf( "%d,\t%d\n", n, n % 6 + 1 );
    }

    return 0;
}

#include <string>
int main()
{
    test();
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
    }
    return EXIT_SUCCESS;
}
