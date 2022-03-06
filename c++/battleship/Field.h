#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<string>
class Field
{
public:
	size_t time1;
	Field()
	{
		int i, j, k = 0;
		F = std::vector < std::vector<int> > (10, std::vector<int>(10, 0));
		ship_beg.first = -1;
		ship_beg.second = -1;
		ship_end.first = -1;
		ship_end.second = -1;
		random = std::vector<std::pair<int, int>>(100);
		for (i = 0; i<10; ++i)
			for (j = 0; j < 10; ++j)
			{
				random[k].first = i;
				random[k].second = j;
				++k;
			}
				
	};
	void F_init();
	void F_change_state(int row, int column, bool state);
	std::pair<int, int> F_shoot();
	void B_intit(int row, int column);
	void E_intit(int row, int column);
	void R_edit(int row, int column);
	void F_correction_when_killed();
	void S_correction();
	std::pair<int, int> LS_get();
	std::vector<int>& operator[](int n)
	{
		return F[n];
	}
private:
	std::vector<std::vector<int>> F;
	std::pair<int, int> ship_beg;
	std::pair<int, int> ship_end;
	std::vector<std::pair<int, int>> random;
	std::pair<int, int> last_shoot;
};
void chatting_with_server();