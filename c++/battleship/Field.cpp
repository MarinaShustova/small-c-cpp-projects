#include"Field.h"
void Field::F_init()
{
	int i, j, field_part, boat = 3;
	time1 = time(0);
	srand(time1);
//	std::cerr << "time(0) with critical bug ~(._.~)" << time1 << std::endl;
	//I descided to use a strategy in setting huge ships and random in setting boats. Is it ok?
	for (i = 0; i <= 3; ++i) //setting a battle-wagon
		(*this)[0][i] = 1;
	for (i = 5; i <= 7; ++i) //setting a cruiser1
		(*this)[0][i] = 1;
	for (j = 0; j <= 1; ++j) //setting a destroyer 1
		(*this)[j][9] = 1;
	for (j = 2; j <= 4; ++j) //setting a cruiser2
		(*this)[j][0] = 1;
	for (j = 6; j <= 7; ++j) //setting a destroyer 2
		(*this)[j][0] = 1;
	for (i = 0; i <= 1; ++i) //setting a destroyer 3
		(*this)[9][i] = 1;
	(*this)[8][4] = 1;
	while (boat)
	{
		field_part = rand() % 3 + 1; 
		field_part = 1;
		if (1 == field_part)
		{
			i = rand() % 6 + 2;
			j = rand() % 6 + 2;
			if (((*this)[i][j] == 0) && ((*this)[i - 1][j] == 0) && ((*this)[i - 1][j + 1] == 0) && ((*this)[i][j + 1] == 0)
				&& ((*this)[i + 1][j + 1] == 0) && ((*this)[i + 1][j] == 0) && ((*this)[i + 1][j - 1] == 0)
				&& ((*this)[i][j - 1] == 0) && ((*this)[i - 1][j - 1] == 0))
			{
				(*this)[i][j] = 1;
				--boat;
			}
		}
		if (2 == field_part)
		{
			j = rand() % 2 + 8;
			i = rand() % 7 + 3;
			if ((i != 9) && (j != 9))
			{
				if (((*this)[i][j] == 0) && ((*this)[i - 1][j] == 0) && ((*this)[i - 1][j + 1] == 0) && ((*this)[i][j + 1] == 0)
					&& ((*this)[i + 1][j + 1] == 0) && ((*this)[i + 1][j] == 0) && ((*this)[i + 1][j - 1] == 0)
					&& ((*this)[i][j - 1] == 0) && ((*this)[i - 1][j - 1] == 0))
				{
					(*this)[i][j] = 1;
					--boat;
				}
			}
			else if ((9 == j) && (i != 9))
			{
				if (((*this)[i][j] == 0) && ((*this)[i][j-1] == 0) && ((*this)[i + 1][j - 1] == 0) && ((*this)[i + 1][j] == 0)
					&& ((*this)[i - 1][j] == 0) && ((*this)[i - 1][j - 1] == 0))
				{
					(*this)[i][j] = 1;
					--boat;
				}
			}
			else if ((9 == i) && (9 == j))
			{
				if (((*this)[i][j] == 0) && ((*this)[i - 1][j] == 0) && ((*this)[i - 1][j - 1] == 0) && ((*this)[i][j - 1] == 0))
				{
					(*this)[i][j] = 1;
					--boat;
				}
			}
			else if ((j != 9) && (i == 9))
			{
				if (((*this)[i][j] == 0) && ((*this)[i][j - 1] == 0) && ((*this)[i - 1][j - 1] == 0) && ((*this)[i - 1][j] == 0)
					&& ((*this)[i - 1][j + 1] == 0) && ((*this)[i][j + 1] == 0))
				{
					(*this)[i][j] = 1;
					--boat;
				}
			}
		}
		if (3 == field_part)
		{
			j = rand() % 5 + 3;
			i = rand() % 2 + 8;
			if (i != 9)
			{
				if (((*this)[i][j] == 0) && ((*this)[i - 1][j] == 0) && ((*this)[i - 1][j + 1] == 0) && ((*this)[i][j + 1] == 0)
					&& ((*this)[i + 1][j + 1] == 0) && ((*this)[i + 1][j] == 0) && ((*this)[i + 1][j - 1] == 0)
					&& ((*this)[i][j - 1] == 0) && ((*this)[i - 1][j - 1] == 0))
				{
					(*this)[i][j] = 1;
					--boat;
				}
			}
			else if (i == 9)
			{
				if (((*this)[i][j] == 0) && ((*this)[i][j - 1] == 0) && ((*this)[i - 1][j - 1] == 0) && ((*this)[i - 1][j] == 0)
					&& ((*this)[i - 1][j + 1] == 0) && ((*this)[i][j + 1] == 0))
				{
					(*this)[i][j] = 1;
					--boat;
				}
			}
		}
	}
	//return (*this);
	return;
}
void Field::F_change_state(int row, int column, bool state)
{
	if (state == 0)
	{
		(*this)[row][column] = -1;
	//	std::cout << row << column << std::endl;
		R_edit(row, column);
	}
	if (state == 1)
	{
		(*this)[row][column] = 1;
		{
	//		std::cout << row << column << std::endl;
			R_edit(row, column);
		}
		if ((column) && (row) && ((*this)[row - 1][column - 1] == 0))
		{
			(*this)[row - 1][column - 1] = -1;
	//		std::cout << row-1 << column-1 << std::endl;
			R_edit(row - 1, column - 1);
		}
		if ((row) && (column != 9) && ((*this)[row - 1][column + 1] == 0))
		{
			(*this)[row - 1][column + 1] = -1;
	//		std::cout << row-1 << column+1 << std::endl;
			R_edit(row - 1, column + 1);
		}
		if ((column != 9) && (row != 9) && ((*this)[row + 1][column + 1] == 0))
		{
			(*this)[row + 1][column + 1] = -1;
	//		std::cout << row + 1 << column + 1 << std::endl;
			R_edit(row + 1, column + 1);
		}
		if ((row != 9) && (column) && ((*this)[row + 1][column - 1] == 0))
		{
			(*this)[row + 1][column - 1] = -1;
	//		std::cout << row + 1 << column - 1 << std::endl;
			R_edit(row + 1, column - 1);
		}
	}
	return;
}
std::pair<int, int> Field::F_shoot()
{
	std::pair<int, int> res;
	srand(time(0));
	if (-1 == ship_beg.first)
	{
		int k = random.size();
		int i = rand() % k;
		res.first = random.at(i).first;
		res.second = random.at(i).second;
		//R_edit(res.first, res.second);
		last_shoot.first = res.first;
		last_shoot.second = res.second;
		return res;
	}
	else
	{
		if (ship_beg.first == ship_end.first) 
		{
			if ((ship_end.second != 9)&&((*this)[ship_end.first][ship_end.second+1] != -1))
			{
				res.first = ship_end.first;
				res.second = ship_end.second + 1;
		//		R_edit(res.first, res.second);
				last_shoot.first = res.first;
				last_shoot.second = res.second;
				return res;
			}
			if ((ship_beg.second != 0) && ((*this)[ship_beg.first][ship_beg.second-1] != -1))
			{
				res.first = ship_beg.first;
				res.second = ship_beg.second - 1;
		//		R_edit(res.first, res.second);
				last_shoot.first = res.first;
				last_shoot.second = res.second;
				return res;
			}
		}
		if (ship_beg.second == ship_end.second)
		{
			if ((ship_end.first != 9) && ((*this)[ship_end.first + 1][ship_end.second] != -1))
			{
				res.first = ship_end.first + 1;
				res.second = ship_end.second;
		//		R_edit(res.first, res.second);
				last_shoot.first = res.first;
				last_shoot.second = res.second;
				return res;
			}
			if ((ship_beg.first != 0) && ((*this)[ship_end.first - 1][ship_end.second] != -1))
			{
				res.first = ship_beg.first - 1;
				res.second = ship_beg.second;
		//		R_edit(res.first, res.second);
				last_shoot.first = res.first;
				last_shoot.second = res.second;
				return res;
			}
		}
	}

}
void Field::B_intit(int row, int column)
{
	ship_beg.first = row;
	ship_beg.second = column;
	return;
}
void Field::E_intit( int row, int column)
{
	ship_end.first = row;
	ship_end.second = column;
	return;
}
void Field::R_edit(int row, int column)
{
	int i;
	for (i = 0; i < random.size(); ++i)
		if ((random.at(i).first == row) && (random.at(i).second == column))
			break;
	random.erase(random.begin() + i);  //to make algorithm of element finding or добавит стд∆∆сет
	/*for (i = 0; i < random.size(); ++i)
		std::cerr << random.at(i).first << " " << random.at(i).second << std::endl;*/
	return;
}
std::pair<int, int> Field::LS_get()
{
	return last_shoot;
}
void Field::F_correction_when_killed()
{
	if ((ship_beg.first) && ((*this)[ship_beg.first - 1][ship_beg.second] != -1))
	{
		(*this)[ship_beg.first - 1][ship_beg.second] = -1;
//		std::cout << ship_beg.first - 1 << ship_beg.second << std::endl;
		R_edit(ship_beg.first - 1, ship_beg.second);
	}
	if ((ship_beg.second) && ((*this)[ship_beg.first][ship_beg.second - 1] != -1))
	{
		(*this)[ship_beg.first][ship_beg.second - 1] = -1;
//		std::cout << ship_beg.first << ship_beg.second - 1 << std::endl;
		R_edit(ship_beg.first, ship_beg.second - 1);
	}
	if ((ship_end.first != 9) && ((*this)[ship_end.first + 1][ship_end.second] != -1))
	{
		(*this)[ship_end.first + 1][ship_end.second] = -1;
//		std::cout << ship_end.first + 1 << ship_end.second << std::endl;
		R_edit(ship_end.first + 1, ship_end.second);
	}
	if ((ship_end.second != 9) && ((*this)[ship_end.first][ship_end.second + 1] != -1))
	{
		(*this)[ship_end.first][ship_end.second + 1] = -1;
//		std::cout << ship_end.first << ship_end.second +1 << std::endl;
		R_edit(ship_end.first, ship_end.second + 1);
	}
}
void Field::S_correction()
{
	if ((ship_beg.first == ship_end.first) && (ship_beg.second != ship_end.second))
	{
		if (last_shoot.second > ship_end.second)
		{
			ship_end.first = last_shoot.first;
			ship_end.second = last_shoot.second;
		}
		if (last_shoot.second < ship_beg.second)
		{
			ship_beg.first = last_shoot.first;
			ship_beg.second = last_shoot.second;
		}
	}
	else if ((ship_beg.first != ship_end.first) && (ship_beg.second == ship_end.second))
	{
		if (last_shoot.first > ship_end.first)
		{
			ship_end.first = last_shoot.first;
			ship_end.second = last_shoot.second;
		}
		if (last_shoot.first < ship_beg.first)
		{
			ship_beg.first = last_shoot.first;
			ship_beg.second = last_shoot.second;
		}
	}
	else if (ship_beg.first != -1)
	{
		if (last_shoot.first == ship_beg.first)
		{
			if (last_shoot.second > ship_beg.second)
			{
				ship_end.first = last_shoot.first;
				ship_end.second = last_shoot.second;
			}
			else if (last_shoot.second < ship_beg.second)
			{
				ship_beg.first = last_shoot.first;
				ship_beg.second = last_shoot.second;
			}
		}
		if (last_shoot.second == ship_beg.second)
		{
			if (last_shoot.first > ship_beg.first)
			{
				ship_end.first = last_shoot.first;
				ship_end.second = last_shoot.second;
			}
			else if (last_shoot.first < ship_beg.first)
			{
				ship_beg.first = last_shoot.first;
				ship_beg.second = last_shoot.second;
			}
		}
	}
	else if (ship_beg.first == -1)
	{
		ship_beg.first = last_shoot.first;
		ship_beg.second = last_shoot.second;
		ship_end.first = last_shoot.first;
		ship_end.second = last_shoot.second;
	}
}