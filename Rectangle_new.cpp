#include "Rectangle.h"

/**
 * Constructor for the rectangle object
 * Fixed a bug where rectangles with reversed points were still allowed to be constructed without changes.
 * If this is the case, the coordinates in question are swapped over so that they are in the correct order.
 * 
 * @param p1: The first, lower-left corner
 * @param p2: The second, upper-right corner
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

/**
 * A function that returns the width of the rectangle. This should not have any bugs since the rectangle constructor
 * has been fixed to account for the event in which the points are input in the wrong order.
 * 
 * @param : none
 */
int Rectangle::GetWidth()
{
    return get_p2().x - get_p1().x;
}

/**
 * A function that returns the height of the rectangle. This should not have any bugs since the rectangle constructor
 * has been fixed to account for the event in which the points are input in the wrong order.
 * 
 * @param : none
 */
int Rectangle::GetHeight()
{
    return get_p2().y - get_p1().y;
}

/**
 * A function that returns the area of the rectangle using the width and the height from the previous two member functions.
 * This did not have any bugs when I ran it with the object-code file
 * 
 * @param : none
 */
int Rectangle::CalculateArea()
{
    return GetWidth() * GetHeight();
}

/**
 * A function that returns true if this rectangle shares any points with the other one. I am making the assumption they
 * are referring to sharing points used to make the rectangles. There was a glitch where p1 of a rectangle was being checked, but not p2
 * of a rectangle, so I have fixed that below.
 * 
 * @param other : The second rectange to compare and figure out if it overlaps or not
 */
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

/**
 * A function that expands the rectangle by moving the bottom left coordinate down one and to the left one and
 * moving the upper right coordinate up one and to the right one. I did not have any bugs with this function.
 * 
 * @param : None
 */
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

/**
 * A function that expands the rectangle by moving the bottom left coordinate up one and to the right one and 
 * moving the upper right coordinate down one and to the left one. This did have a bug with lines and points, so I coded it
 * so that if the width or heigh of rectangle was already 0, they would not be shrunk farther, since I didn't know what the 
 * intended behavior was supposed to be.
 * 
 * @param : None
 */
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