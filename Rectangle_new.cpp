#include "Rectangle.h"

/**
 * Allows the given Player to take their turn
 * 
 * @param Player: this player will take a turn
 */
Rectangle::Rectangle(Point p1, Point p2)
{
    if (p1.x > p2.x)
    {
        int swap = 0;
        swap = p1.x;
        p1.x = p2.x;
        p2.x = swap;
    }

    if (p1.y > p2.y)
    {
        int swap = 0;
        swap = p1.y;
        p1.y = p2.y;
        p2.y = swap;
    }

    p1_ = p1;
    p2_ = p2;
}

int Rectangle::GetWidth()
{
    return get_p2().x - get_p1().x;
}

int Rectangle::GetHeight()
{
    return get_p2().y - get_p1().y;
}

int Rectangle::CalculateArea()
{
    return GetWidth() * GetHeight();
}

bool Rectangle::Overlaps(Rectangle &other)
{
    if((get_p1().x == other.get_p1().x && get_p1().y == other.get_p1().y)){
        return true;
    }

    if((get_p1().x == other.get_p2().x && get_p1().y == other.get_p2().y)){
        return true;
    }

    if((get_p2().x == other.get_p2().x && get_p2().y == other.get_p2().y)){
        return true;
    }

    if((get_p2().x == other.get_p1().x && get_p2().y == other.get_p1().y)){
        return true;
    }

    return false;
}

void Rectangle::Expand(){
    Point p1_n;
    Point p2_n;
    p1_n.x = get_p1().x + 1;
    p1_n.y = get_p1().y + 1;
    p2_n.x = get_p2().x + 1;
    p2_n.y = get_p2().y + 1;

    p1_ = p1_n;
    p2_ = p2_n;
}

void Rectangle::Shrink(){

    Point p1_n;
    Point p2_n;

    if(GetHeight() == 0 && GetWidth() == 0){
        return;
    }

    if(GetHeight() == 0){
        p1_n.x = get_p1().x - 1;
        p1_n.y = get_p1().y;
        p2_n.x = get_p2().x - 1;
        p2_n.y = get_p2().y;

        p1_ = p1_n;
        p2_ = p2_n;

        return;
    }

    if(GetWidth() == 0){
        p1_n.x = get_p1().x;
        p1_n.y = get_p1().y - 1;
        p2_n.x = get_p2().x;
        p2_n.y = get_p2().y - 1;

        p1_ = p1_n;
        p2_ = p2_n;

        return;
    }

    p1_n.x = get_p1().x - 1;
    p1_n.y = get_p1().y - 1;
    p2_n.x = get_p2().x - 1;
    p2_n.y = get_p2().y - 1;

    p1_ = p1_n;
    p2_ = p2_n;
}