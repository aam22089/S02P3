#include "Rectangle.hpp"
#include <cmath>
using namespace std;

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Blue);
    this->speed = Vector2f(5.f, 5.f);
    this->acc = Vector2f(0.f,1.f);
}

Rectangle::Rectangle(Vector2f size, int x, int y)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Blue);
    this->speed = Vector2f(5.f, 5.f);
    this->acc = Vector2f(0.f,1.f);
    this->shape.setPosition(Vector2f(x, y));
}

void Rectangle::update()
{
    this->speed+=this->acc;
    this->shape.move(speed);
    if (this->shape.getPosition().x + this->shape.getSize().x >= 1920 || this->shape.getPosition().x < 0)
    {
        this->speed.x *= -1;
        this->shape.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
    }
    if (this->shape.getPosition().y + this->shape.getSize().y >= 1080 || this->shape.getPosition().y < 0)
    {
        this->speed.y *= -1;
        Vector2f position = this->shape.getPosition();
        this->shape.setPosition(position.x, 1080- this->shape.getSize().y);
        this->shape.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
    }
    this->shape.move(this->speed);
}

void Rectangle::drawTo(RenderWindow &window)
{

    window.draw(this->shape);
}

void Rectangle::click(int x, int y)
{
}
