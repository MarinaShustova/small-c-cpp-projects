#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Header.h"
using namespace std;
TEST_CASE("cin_to_vector", "cintovect")
{
	stringstream in_1("Twinkle twinkle little star how I wonder what you are");
	stringstream in_2("");
	stringstream in_3("Up above the world so high, like a diamond in the sky.");
	vector<string> results_1 = { {"Twinkle"}, {"twinkle"}, {"little"}, {"star"}, {"how"}, {"I"}, {"wonder"}, {"what"}, {"you"}, {"are"}};
	vector<string> results_2 = {};
	vector<string> results_3 = { {"Up"}, {"above"}, {"the"}, {"world"}, {"so"},  {"high,"}, {"like"}, {"a"}, {"diamond"}, {"in"}, {"the"}, {"sky."}};
	REQUIRE(results_1 == cin_to_vect(in_1));
	REQUIRE(results_2 == cin_to_vect(in_2));
	REQUIRE(results_3 == cin_to_vect(in_3));
}
TEST_CASE("vect_to_map", "vecttomap")
{
	vector<string> input_1 = { { "twinkle" },{ "twinkle" },{ "little" },{ "star" },{ "how" },{ "I" },{ "wonder" },{ "what" },{ "you" },{ "are" } };
	vector<string> input_2 = { {"I"}, {"think"}, {"we"}, {"are"}, {"doomed"},{ "I" },{ "think" },{ "we" },{ "are" },{ "doomed" } };
	vector<string> input_3 = { {"Work"}, {"it"}, {"harder"}, {"Make"}, {"it"}, {"better"}, {"Do"}, {"it"}, {"faster"}, {"Makes"}, {"us"}, {"stronger"}, {"Work"}, {"it"}, {"harder"}, {"Make"}, {"it"}, {"better"}, {"Do"}, {"it"}, {"faster"}, {"Makes"}, {"us"}, {"stronger"} };
	map<string, int> res_1 = { { "twinkle", 2 },{ "little", 1 },{ "star", 1 },{ "how", 1 },{ "I", 1 },{ "wonder", 1 },{ "what", 1 },{ "you", 1 },{ "are", 1 } };
	map<string, int> res_2 = { {"I think we are doomed", 2}, {  "think we are doomed I", 1 }, { "we are doomed I think", 1 }, { "are doomed I think we", 1 }, { "doomed I think we are", 1 }};
	map<string, int> res_3 = { { "Work", 2 },{ "it", 6 },{ "harder", 2 },{ "Make", 2 },{ "better", 2 },{ "Do", 2 },{ "faster", 2 },{ "Makes", 2 },{ "us", 2 },{ "stronger", 2 } };
	REQUIRE(res_1 == vect_to_map(input_1, 1));
	REQUIRE(res_2 == vect_to_map(input_2, 5));
	REQUIRE(res_3 == vect_to_map(input_3, 1));
}
TEST_CASE("map_to_vect", "maptovect")
{
	map<string, int> in_1 = { { "twinkle", 2 },{ "little", 1 },{ "star", 1 },{ "how", 1 },{ "I", 1 },{ "wonder", 1 },{ "what", 1 },{ "you", 1 },{ "are", 1 } };
	map<string, int> in_2 = { { "I think we are doomed", 2 },{ "think we are doomed I", 1 },{ "we are doomed I think", 1 },{ "are doomed I think we", 1 },{ "doomed I think we are", 1 } };
	map<string, int> in_3 = { { "Work", 2 },{ "it", 6 },{ "harder", 2 },{ "Make", 2 },{ "better", 2 },{ "Do", 2 },{ "faster", 2 },{ "Makes", 2 },{ "us", 2 },{ "stronger", 2 } };
	vector<pair <string, int>> results_1 = { { "twinkle", 2 } };
	vector<pair <string, int>> results_2 = { { "I think we are doomed", 2 },{ "are doomed I think we", 1 },{ "doomed I think we are", 1 },{ "think we are doomed I", 1 },{ "we are doomed I think", 1 } };
	vector<pair <string, int>> results_3 = { { "it", 6 } };
	REQUIRE(results_1 == map_to_vect(in_1, 2));
	REQUIRE(results_2 == map_to_vect(in_2, 1));
	REQUIRE(results_3 == map_to_vect(in_3, 3));
}