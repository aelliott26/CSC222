#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "BigInt.h"
using namespace std;

TEST_CASE("Test can create and render BigInts") {
    BigInt bi;
    CHECK(bi.to_string() == "0");
    BigInt bi2(42);
    CHECK(bi2.to_string() == "42");
    BigInt bi3(-42);
    CHECK(bi3.to_string() == "-42");
    BigInt bi4("123456789012345678901234567890");
    CHECK(bi4.to_string() == "123456789012345678901234567890");
    BigInt bi5("-923456789012345678901234567890");
    CHECK(bi5.to_string() == "-923456789012345678901234567890");
}

TEST_CASE("Test can compare BigInts for equality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 == i5) == true);
    CHECK((i1 == i2) == false);
    CHECK((i1 == i3) == false);
    CHECK((i2 == i6) == false);
}

TEST_CASE("Test can compare BigInts for inequality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 > i5) == false);
    CHECK((i2 > i1) == true);
    CHECK((i4 > i1) == false);
    CHECK((i6 > i4) == true);
}

TEST_CASE("Test can compare BigInts for inequality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-54321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 != i5) == false);
    CHECK((i2 < i1) == false);
    CHECK((i4 <= i1) == true);
    CHECK((i6 >= i4) == true);
}


TEST_CASE("Test helper function to add digit strings with same num digits") {
    CHECK(sum_common_len_digit_strs("123", "321") == "444");
    CHECK(sum_common_len_digit_strs("123", "123") == "246");
    CHECK(sum_common_len_digit_strs("123", "222") == "345");
    CHECK(sum_common_len_digit_strs("123", "119") == "242");
    CHECK(sum_common_len_digit_strs("123", "888") == "c+011");
    CHECK(sum_common_len_digit_strs("999", "999") == "c+998");
    CHECK(sum_common_len_digit_strs("123456789012345678901234567890",
                                    "123456789012345678901234567890")
                                 == "246913578024691357802469135780");
    CHECK(sum_common_len_digit_strs("900000000000000000000000000009",
                                    "900000000000000000000000000009")
                                 == "c+800000000000000000000000000018");
}

TEST_CASE("Test increment_digit_string helper function") {
    CHECK(increment_digit_string("8") == "9");
    CHECK(increment_digit_string("24") == "25");
    CHECK(increment_digit_string("100") == "101");
    CHECK(increment_digit_string("99") == "100");
    CHECK(increment_digit_string("1199") == "1200");
    CHECK(increment_digit_string("9999") == "10000");
}

TEST_CASE("Test can add BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("1");
    BigInt i6("123456789123456789123456789");
    CHECK((i1 + i2).to_string() == "444");
    CHECK((i1 + i3).to_string() == "43333");
    CHECK((i4 + i5).to_string() == "10000");
    CHECK((i6 + i6).to_string() == "246913578246913578246913578");
}


TEST_CASE("Test can add BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("1");
    CHECK((i1 + i2).to_string() == "444");
    CHECK((i1 + i3).to_string() == "43333");
}



TEST_CASE("Test helper function to subtract digit strings with same num digits") {
    CHECK(sub_common_len_digit_strs("345", "123") == "222");
    CHECK(sub_common_len_digit_strs("123", "123") == "0");
    CHECK(sub_common_len_digit_strs("123", "222") == "-99");
    CHECK(sub_common_len_digit_strs("123", "119") == "4");
    CHECK(sub_common_len_digit_strs("-123", "119") == "-242");
    CHECK(sub_common_len_digit_strs("123", "-119") == "242");

}


TEST_CASE("Test can subtract BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("10000");
    BigInt i5("1");
    CHECK((i4 - i5).to_string() == "9999");
    CHECK((i3 - i2).to_string() == "42889");
}

TEST_CASE("Test can multiply BigInts") {
    BigInt i1("10");
    BigInt i2("321");
    BigInt i3("-100");
    BigInt i4("123456789123456789123456789");
    CHECK((i1 * i2).to_string() == "3210");
    CHECK((i2 * i3).to_string() == "-32100");
    CHECK((i1 * i4).to_string() == "1234567891234567891234567890");
}
	
