#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;


TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
}


TEST_CASE("Testing More than 3 ints") {
    vector<int> nums = {1, 3, 7, 12};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7 12";
    CHECK(numstr == expected);
}

TEST_CASE("Testing No ints") {
    vector<int> nums;
    string numstr = render_num_vector(nums);
    string expected = "";
    CHECK(numstr == expected);
}


TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
}

