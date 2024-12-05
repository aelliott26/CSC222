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


TEST_CASE("Test can output the date") {
    MyObject date1(1, 12, 2024);
    string expected = "12/1/2024";
    CHECK(date1.to_string() == expected);
}

TEST_CASE("Test can output the date") {
    MyObject date1(1, 12, 2024);
    string expected = "12/1/2024";
    CHECK(date1.to_string() == expected);
}
TEST_CASE("Test can read from the vector") {
    MyObject date1(25, 12, 2024);
    string expected = "Christmas";
    CHECK(date1.special_day() == expected);
}

TEST_CASE("Test can add events") {
    MyObject date1(1, 1, 2024, "New Years");
    MyObject date2(1, 1, 2024);
    CHECK(date2.special_day() == "New Years");
}

TEST_CASE("Test can remove events") {
    MyObject date1(1, 2, 2024, "Bad Date");
    MyObject date2(1, 2, 2024, "Bad Date", 0);
    MyObject date3(1, 2, 2024);
    CHECK(date3.special_day() == "");
}

