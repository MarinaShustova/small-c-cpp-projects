#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<cstring>

void sort(std::vector<std::pair <std::string, int>> &el);
int work_with_arg(const int& cgra, char** vgra, int &amount, int &freq, int &stream, int &place);
std::vector<std::string> cin_to_vect(std::istream &in);
std::map<std::string, int> vect_to_map(std::vector<std::string> &vect, const int &key_amount);
std::vector<std::pair <std::string, int>> map_to_vect(std::map<std::string, int> &maaap, const int &rep);

