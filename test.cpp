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

  SECTION("Returns true if two rectanges share a point"){
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

    REQUIRE(test_rectangle.Overlaps(test_rectangle_2) == true);
    REQUIRE(test_rectangle.Overlaps(test_rectangle_3) == true);
  }

  SECTION("Correctly getting the area of the rectangle")
  {
    REQUIRE(test_rectangle.CalculateArea() == 9);
    REQUIRE(test_rectangle_point.CalculateArea() == 0);
    REQUIRE(test_rectangle_line.CalculateArea() == 0);
    REQUIRE(test_rectangle_reversed.CalculateArea() == 9);
  }
}
