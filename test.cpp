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
  one.x = 0;
  one.y = 0;
  two.x = 3;
  two.y = 3;

  Rectangle test_rectangle = Rectangle(one, two);

  Point test_p1 = test_rectangle.get_p1();
  Point test_p2 = test_rectangle.get_p2();

  REQUIRE(test_p1.x == one.x);
  REQUIRE(test_p1.y == one.y);
  REQUIRE(test_p2.x == two.x);
  REQUIRE(test_p2.y == two.y);

  SECTION("Correctly getting the width between two points")
  {
    REQUIRE(test_rectangle.GetWidth() == 3);
  }

  SECTION("Correctly getting the height between two points")
  {
    REQUIRE(test_rectangle.GetHeight() == 3);
  }

  SECTION("Returns true if two rectanges share a point"){
    Point three, four;
    three.x = 2;
    three.y = 2;
    four.x = 5;
    four.y = 5;
    Rectangle test_rectangle_2 = Rectangle(three, four);

    REQUIRE(test_rectangle.Overlaps(test_rectangle_2) == true);
  }

  SECTION("Correctly getting the area of the rectangle")
  {
    REQUIRE(test_rectangle.CalculateArea() == 9);
  }
}
