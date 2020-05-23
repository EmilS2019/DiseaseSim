#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height, sf::Color c)
{
    this->color = c;
    this->x = x;
    this->y = y;
    this->width=width;
    this->height=height;
}


sf::RectangleShape Rectangle::getRect()
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(sf::Vector2f(x, y));
    return rect;
}

Rectangle::Move(float dx, float dy)
{
    this->x += dx;
    this->y += dy;
}
