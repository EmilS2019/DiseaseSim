#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SFML/Graphics.hpp>

class Rectangle
{
    public:
        float x,y, width, height;
        sf::Color color;

        Rectangle();
        Rectangle(float x, float y, float width, float height, sf::Color c);


        void Move(float dx, float dy);
        void rotateRect(float radians);
        void avoidEdge();
        void randomRotation(int tenthPercentileOdds,float rotation);

        sf::RectangleShape getRect();

        void setVelocity(float xvel, float yvel);
        float getSpeed();
        float velVector[2];
    private:
        sf::RectangleShape rectangle;

};

#endif // RECTANGLE_H
