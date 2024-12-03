#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "MyObject.h"
using namespace std;

TEST_CASE("Test can store a date") {
    MyObject date1(1, 1, 2024);
    CHECK(date1.day == 1);
    CHECK(date1.month == 1);
    CHECK(date1.year == 2024);

}


