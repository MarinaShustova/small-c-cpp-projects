#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Header.h"
using namespace std;
TEST_CASE("constructors+norm", "cnstr_nrm_methods")
{
	Date res_1 = { 2017, Month::Apr, 30, 15, 20, 7 };
	Date res_2 = { 1917, Month::Oct, 25, 0, 0, 0 };
	Date res_3 = { 2061, Month::Jan, 1, 0, 0, 0 };
	Date res_4 = { 1918, Month::Mar, 1, 0, 0, 0 };
	Date ex_1(2017, Month::Apr, 30, 15, 20, 7);
	Date ex_2(1917, Month::Oct, 25);
	Date ex_3(2060, Month::Dec, 31, 23, 59, 60);
	Date ex_4(1917, static_cast<Month>(13), 60);
	REQUIRE(res_1 == ex_1);
	REQUIRE(res_2 == ex_2);
	REQUIRE(res_3 == ex_3);
	REQUIRE(res_4 == ex_4);
}
TEST_CASE("adding+norm", "add_nrm_methods")
{
	Date res_1 = { 2017, Month::Apr, 30, 15, 20, 7 };
	Date res_2 = { 1917, Month::Feb, 28, 16, 5, 56 };
	Date res_3 = { 3025, Month::May, 31, 8, 19, 4 };
	Date res_4 = { 9999, Month::Nov, 13, 22, 59, 33 };
	Date res_5 = { 1957, Month::Sep, 22, 4, 55, 54 };
	Date res_6 = { 786, Month::Sep, 1, 4, 18, 39 };
	Date res_7 = { 1, Month::Apr, 20, 6, 5, 8 };
	Date ex_1(2017, Month::Mar, 31, 15, 20, 7), e1= ex_1.addMonth(1);
	Date ex_2(1916, Month::Feb, 29, 16, 5, 56), e2 = ex_2.addYears(1);
	Date ex_3(3025, Month::Jun, 30, 8, 19, 4), e3 = ex_3.addDays(-30);
	Date ex_4(9999, Month::Nov, 14, 23, 59, 33), e4 = ex_4.addHours(-25);
	Date ex_5(1957, Month::Sep, 22, 4, 45, 54), e5= ex_5.addMinutes(10);
	Date ex_6(786, Month::Aug, 32, 4, 19, 34), e6 = ex_6.addSeconds(-55);
	Date ex_7(4353, Month::Apr, 20, 6, 5, 8), e7 = ex_7.addYears(-4352);
	REQUIRE(res_1 == e1);
	REQUIRE(res_2 == e2);
	REQUIRE(res_3 == e3);
	REQUIRE(res_4 == e4);
	REQUIRE(res_5 == e5);
	REQUIRE(res_6 == e6);
	REQUIRE(res_7 == e7);
}
TEST_CASE("interval", "constructor+getint+addint")
{
	DateInterval res_1 = { 7982, -3, -27, -23, -59, -59 };
	DateInterval res_2 = { 0, 44, 6, 8, 45, 33 };
	Date  d_10 = { 2017, Month::Dec, 31, 23, 59, 59 };
	Date d_11 = { 9999, Month::Sep, 4, 0, 0, 0 };
	DateInterval d_20(0, 44, 6, 8, 45, 33);
	REQUIRE(res_1 == d_11.getInterval(d_10));
	REQUIRE(res_2 == d_20);
	REQUIRE(d_11 == d_10.addInterval(res_1));
}
TEST_CASE("operators", "+-+=-=++--")
{
	Date d_1 = { 2017, Month::Nov, 17, 12, 34, 56 };
	Date d_2 = { 1, Month::Jan, 1, 1, 1, 1 };
	Date d_3 = { 1975, Month::Sep, 22, 8, 5, 18 };
	Date copy_2(d_2);
	DateInterval di_1 = { 5, 13, 3, 3, 3, 3 };
	Date r_1 = { 2011, Month::Oct, 14, 9, 31, 53 };
	Date r_2 = { 7, Month::Feb, 4, 4, 4, 4 };
	Date r_3 = { 1975, Month::Sep, 21, 8, 5, 18 };
	Date r_4 = { 1975, Month::Sep, 23, 8, 5, 18 };
	copy_2 += di_1;
	REQUIRE((d_1-di_1) == r_1);
	REQUIRE((r_1+di_1) == d_1);
	REQUIRE(r_2 == copy_2);
	copy_2 -= di_1;
	REQUIRE(d_2 == copy_2);
	REQUIRE(r_3 == --d_3);
	REQUIRE(r_4 == ++(++d_3));
}