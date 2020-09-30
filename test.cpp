#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

// TEST_CASE ( "Factorials are computed", "[factorial]") {
//   REQUIRE( Factorial(2) == 2 );
//   REQUIRE( Factorial(3) == 6 );
// }

TEST_CASE("Rectange is made correctly with constructor", "[rectangle]")
{
  Point one;
  Point two;
  Point three;
  one.x = 0;
  one.y = 0;
  two.x = 3;
  two.y = 3;
  three.x = 3;
  three.y = 0;

  Rectangle test_rectangle = Rectangle(one, two);
  Rectangle test_rectangle_point = Rectangle(one, one);
  Rectangle test_rectangle_line = Rectangle(one, three);
  Rectangle test_rectangle_reversed = Rectangle(two, one);

  SECTION("Correctly getting the width between two points")
  {
    REQUIRE(test_rectangle.GetWidth() == 3);
    REQUIRE(test_rectangle_point.GetWidth() == 0);
    REQUIRE(test_rectangle_line.GetWidth() == 3);
    REQUIRE(test_rectangle_reversed.GetWidth() == 3);
  }

  SECTION("Correctly getting the height between two points")
  {
    REQUIRE(test_rectangle.GetHeight() == 3);
    REQUIRE(test_rectangle_point.GetHeight() == 0);
    REQUIRE(test_rectangle_line.GetHeight() == 0);
    REQUIRE(test_rectangle_reversed.GetHeight() == 3);
  }

  SECTION("Returns true if two rectanges share a point")
  {
    Point four, five;
    four.x = 0;
    four.y = 0;
    five.x = 2;
    five.y = 2;
    Rectangle test_rectangle_2 = Rectangle(four, five);

    Point six, seven;
    six.x = 1;
    six.y = 1;
    seven.x = 3;
    seven.y = 3;
    Rectangle test_rectangle_3 = Rectangle(six, seven);

    Point eight, nine;
    eight.x = -3;
    eight.y = -3;
    nine.x = 0;
    nine.y = 0;
    Rectangle test_rectangle_4 = Rectangle(eight, nine);

    Point ten, eleven;
    ten.x = 3;
    ten.y = 3;
    eleven.x = 6;
    eleven.y = 6;
    Rectangle test_rectangle_5 = Rectangle(ten, eleven);

    Point tweleve, thirteen;
    tweleve.x = 1;
    tweleve.y = 1;
    thirteen.x = 1;
    thirteen.y = 1;
    Rectangle test_rectangle_6 = Rectangle(tweleve, thirteen);

    Point fourteen, fifteen;
    fourteen.x = 2;
    fourteen.y = 2;
    fifteen.x = 8;
    fifteen.y = 8;
    Rectangle test_rectangle_7 = Rectangle(fourteen, fifteen);

    REQUIRE(test_rectangle.Overlaps(test_rectangle_2) == true);
    REQUIRE(test_rectangle.Overlaps(test_rectangle_3) == true);
    REQUIRE(test_rectangle.Overlaps(test_rectangle_4) == true);
    REQUIRE(test_rectangle.Overlaps(test_rectangle_5) == true);
    REQUIRE(test_rectangle.Overlaps(test_rectangle_6) == true);
    REQUIRE(test_rectangle_7.Overlaps(test_rectangle) == true);
    REQUIRE(test_rectangle.Overlaps(test_rectangle_7) == true);
  }

  SECTION("Correctly getting the area of the rectangle")
  {
    REQUIRE(test_rectangle.CalculateArea() == 9);
    REQUIRE(test_rectangle_point.CalculateArea() == 0);
    REQUIRE(test_rectangle_line.CalculateArea() == 0);
    REQUIRE(test_rectangle_reversed.CalculateArea() == 9);
  }

  SECTION("Expanding the rectangle"){
    test_rectangle.Expand();
    REQUIRE(test_rectangle.get_p1().x == -1);
    REQUIRE(test_rectangle.get_p1().y == -1);
    REQUIRE(test_rectangle.get_p2().x == 4);
    REQUIRE(test_rectangle.get_p2().y == 4);
  }

  SECTION("Shrinking the rectangle"){
    test_rectangle.Shrink();
    REQUIRE(test_rectangle.get_p1().x == 1);
    REQUIRE(test_rectangle.get_p1().y == 1);
    REQUIRE(test_rectangle.get_p2().x == 2);
    REQUIRE(test_rectangle.get_p2().y == 2);
    REQUIRE(test_rectangle.CalculateArea() == 1);

    test_rectangle_point.Shrink(); //THIS IS NOT CORRECT BEHAVIOR, PASSING MEANS IT'S NOT WORKING
    REQUIRE(test_rectangle_point.get_p1().x == 0);
    REQUIRE(test_rectangle_point.get_p1().y == 0);
    REQUIRE(test_rectangle_point.get_p2().y == 0);
    REQUIRE(test_rectangle_point.get_p2().y == 0);
  }
}
