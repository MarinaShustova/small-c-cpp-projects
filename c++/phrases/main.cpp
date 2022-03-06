#include"Header.h"
using namespace std;
int main(int argc, char *argv[])
{
	int key_repeats = 2, key_amount = 2, place = -1, stream = -1;
	vector <string> all_words;
	string current_word;
	vector <pair <string, int>> results;
	map <string, int> tmp_storage;
	ifstream info;
	if (work_with_arg(argc, argv, key_amount, key_repeats, place, stream) != 0)
		return 3;
	if (stream == 0)
		all_words = cin_to_vect(cin);
	else if (stream == 1)
	{
		info.open(argv[place]);
		if (!info.is_open())
		{
			cout << "File can't be opened." << endl;
			return 0;
		}
				all_words = cin_to_vect(info);
	}
	else
	{
		cout << "Got error while reading." << endl;
		return 1;
	}
	if (all_words.empty())
	{
		cout << "You gave an empty string." << endl;
		return 0;
	}
	if (key_amount > all_words.size())
	{
		cout << "Impossible to make a phrase - given length is more than string's." << endl;
		return 2;
	}
	tmp_storage = vect_to_map(all_words, key_amount);
	results = map_to_vect(tmp_storage, key_repeats);
	if (results.empty())
	{
		cout << "No repeats found." << endl;
		return 0;
	}
	sort(results);
	for (pair <string, int> g : results)
		cout << g.first << " (" << g.second << ")" << endl;
	return 0;
}