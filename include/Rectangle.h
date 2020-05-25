#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SFML/Graphics.hpp>

class Rectangle
{
    public:
        float x,y, width, height;
        sf::Color color;

        Rectangle(float x, float y, float width, float height, sf::Color c);


        void Move(float dx, float dy);
        void rotateRect(float radians);

        sf::RectangleShape getRect();

        void setVelocity(float xvel, float yvel);
        float getSpeed();
        float velVector[2];
    private:

};

#endif // RECTANGLE_H
