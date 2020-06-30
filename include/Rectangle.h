#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SFML/Graphics.hpp>
#include "../Math.h"
class Rectangle
{
    public:
        float x,y, width, height;
        sf::Color color;

        Rectangle();
        ~Rectangle();
        Rectangle(float x, float y, float width, float height, sf::Color c);


        void Move(float dx, float dy);
        void rotateRect(float radians);
        void avoidEdge();
        void randomRotation(int tenthPercentileOdds,float rotation);

        sf::RectangleShape getRect();

        void setVelocity(float xvel, float yvel);
        float getSpeed();
        float velVector[2];

        Math math;

        enum conditions {suceptible, sick, dead, immune};
        void sneeze(float range, int arrayLenght, Rectangle* suceptibles);
        float sneezeRadius;

        void changeCondition(conditions condition);
        conditions condition;
        float health;
        float immunity;


    private:

        sf::RectangleShape rectangle;

};

#endif // RECTANGLE_H
