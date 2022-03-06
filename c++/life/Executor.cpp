#include "Executor.h"
#include <fstream>
void Executor::get_command(std::string ss, Body &BB, std::string &com, int &X, int &Y, std::string &filename)
{
	std::string s;
	str << ss;
	str >> command;
	if (command == "reset")
	{
		com = "reset";
		X = -1;
		Y = -1;
	}
	else if (command == "step")
	{
		com = "step";
		str >> X;
		Y = -1;
	}
	else if (command == "set")
	{
		com = "set";
		str >> s;
		X = s[0] - 'A';
		Y = s[1] - '0';
	}
	else if (command == "clear")
	{
		com = "clear";
		str >> s;
		X = s[0] - 'A';
		Y = s[1] - '0';
	}
	else if (command == "back")
	{
		com = "back";
		X = -1;
		Y = -1;
	}
	else if (command == "load")
	{
		com = "load";
		str >> filename;
	}
	else if (command == "save")
	{
		com = "save";
		str >> filename;
	}
	else
	{
		std::cout << "Incorrect command, please try again" << std::endl;
		com = "";
	}
	command = "";
	str.clear();
	return;
}
void Executor::perform_command(std::string com, int X, int Y, Body &BB, std::string &filename)
{
	if ((-1 == Y) && (com == "step"))
	{
		if (X > 0)
			while (X)
			{
				BB.evolution();
				if (BB.cmp_Bs())
				{
					BB.show(steps);
					break;
				}
				++steps;
				--X;
				BB.show(steps);
			}
		else
		{
			std::cout << "Impossible number of steps" << std::endl;
			filename = "nvm";
		}
	}
	else if ((-1 == X) && (-1 == Y) && (com == "reset"))
	{
		BB.upd_prev();
		BB.reset();
		steps = 0;
		BB.show(steps);
	}
	else if ((-1 == X) && (-1 == Y) && (com == "back"))
	{
		if (steps != 0)
		{
			BB.step_back();
			BB.show(steps - 1);
		}
		else
			BB.show(0);
	}
	else if ((-1 != X) && (-1 != Y) && (com == "set"))
	{
		if ((X < 10) && (Y < 10) && (X >= 0) && (Y >= 0))
		{
			BB.upd_prev();
			BB[Y][X].set();
			BB.show(steps);
		}
		else
			std::cout << "Such position doesn't exist" << std::endl;
	}
	else if ((-1 != X) && (-1 != Y) && (com == "clear"))
	{
		if ((X < 10) && (Y < 10) && (X >= 0) && (Y >= 0))
		{
			BB.upd_prev();
			BB[Y][X].kill();
			BB.show(steps);
		}
		else
			std::cout << "Such position doesn't exist" << std::endl;
	}
	else if ((filename != "") && (com == "load"))
	{
		int i, j;
		std::string s, a = "*";
		std::ifstream fin(filename, std::ios_base::in);
		if (!fin)
		{
			std::cout << "Such file can't be opened, please try again" << std::endl;
//			BB.show(steps);
			return;
		}
		BB.reset();
		steps = 0;
		for (i = 0; i < 10; ++i)
		{
			std::getline(fin, s);
			for (j = 0; j < 10; ++j)
				if (s[j] == a[0])
					BB[i][j].set();
		}
		BB.show(steps);
		fin.close();
	}
	else if ((filename != "") && (com == "save"))
	{
		int i, j;
		std::ofstream fout(filename, std::ios_base::out);
		if (!fout)
		{
			std::cout << "Such file can't be opened, please try again" << std::endl;
//			BB.show(steps);
			return;
		}
		for (i = 0; i < 10; ++i)
		{
			if (i != 0)
				fout << std::endl;
			for (j = 0; j < 10; ++j)
				if (BB[i][j] == true)
					fout << "*";
				else
					fout << ".";
		}
		fout.close();
		BB.show(steps);
	}
}