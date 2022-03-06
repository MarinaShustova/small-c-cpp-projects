#include"Header.h"
#include "catch.hpp"
using namespace std;
int work_with_arg(const int& cgra, char** vgra, int &amount, int &freq, int &place, int &stream)
{
	int i, k = -1;
	if (cgra == 1)
	{
		cout << "You didn't give enough information" << endl;
		return 3;
	}
	for (i = 1; i < cgra; i++)
	{
		if (strcmp(vgra[i], "-") == 0)
		{
			stream = 0;
			k = 0;
		}
		else if ((k != 0)&& (k != 1)&&(vgra[i][0] != '-'))
		{
			place = i;
			stream = 1;
			k = 1;
		}
		if (strcmp(vgra[i], "-n")==0)
			amount = *(vgra[i + 1]) - '0';
		if (strcmp(vgra[i], "-m")==0)
			freq = *(vgra[i + 1]) - '0';
		
	}
	return 0;
}
vector<string> cin_to_vect(istream &inf)
{
	string current_word;
	vector <string> all_words;
	while (inf >> current_word)
		all_words.push_back(current_word);
	return all_words;
}
map<string, int> vect_to_map(vector<string> &vect, const int &key_amount)
{
	map <string, int> tmp_storage;
	string current_phrase;
	size_t size = vect.size();
	for (int k = 0; k < size - key_amount + 1; k++)					//отображение map
	{
		for (int j = 1; j <= key_amount; j++)
		{
			if (j == 1)
			{
				current_phrase += vect.front();
				vect.erase(vect.begin());
			}
			else
			{
				current_phrase += " ";
				current_phrase += vect[j - 2];
			}
		}
		++tmp_storage[current_phrase];
		current_phrase.clear();
	}
	return tmp_storage;
}
vector<pair <string, int>> map_to_vect(map<string, int> &maaap, const int &rep)
{
	vector<pair <string, int>> results;
	for (pair <string, int> c : maaap)					//выбор фраз, удовлетворяющих условию количества
	{																//повторений
		if (c.second >= rep)
		{
			results.push_back(c);
		}
	}
	return results;
}
void sort(vector<pair <string, int>> &el)
{
	for (int s = 0; s < el.size() - 1; s++)
		for (int t = s + 1; t < el.size(); t++)
		{
			if (el[s].second < el[t].second)
				swap(el[s], el[t]);
		}
}