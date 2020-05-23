#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SFML/Graphics.hpp>

class Rectangle
{
    public:
        float x,y, width, height;
        sf::Color color;

        Rectangle(float x, float y, float width, float height, sf::Color c);

        Move(float dx, float dy);

        sf::RectangleShape getRect();
};

#endif // RECTANGLE_H
