#include"Field.h"
void chatting_with_server()
{
	Field MyField, EnemyField;
	int i, j;
	std::string command = "";
	MyField.F_init();
	while (1)
	{
		std::getline(std::cin, command);
		if (command == "Arrange!")
		{
			for (i = 0; i < 10; ++i)
			{
				std::cout << std::endl;
				for (j = 0; j < 10; ++j)
					std::cout << MyField[i][j];
			}
			std::cout << std::endl;
		}
		else if (command == "Shoot!")
		{
			std::pair<int, int> shoot = EnemyField.F_shoot();
			std::cout << static_cast<char>(shoot.second + 'A') << " " << shoot.first << std::endl;
		}
		else if (command == "Miss")
		{
			EnemyField.F_change_state(EnemyField.LS_get().first, EnemyField.LS_get().second, 0);
			/*for (i = 0; i < 10; ++i)
			{
				std::cout << std::endl;
				for (j = 0; j < 10; ++j)
					std::cout << EnemyField[i][j];
			}*/
		}
		else if (command == "Hit")
		{
			EnemyField.F_change_state(EnemyField.LS_get().first, EnemyField.LS_get().second, 1);
			EnemyField.S_correction();
			std::pair<int, int> shoot = EnemyField.F_shoot();
			std::cout << static_cast<char>(shoot.second + 'A') << " " << shoot.first << std::endl;
			/*for (i = 0; i < 10; ++i)
			{
				std::cout << std::endl;
				for (j = 0; j < 10; ++j)
					std::cout << EnemyField[i][j];
			}*/
		}
		else if (command == "Kill")
		{
			EnemyField.F_change_state(EnemyField.LS_get().first, EnemyField.LS_get().second, 1);
			EnemyField.S_correction();
			EnemyField.F_correction_when_killed();
			EnemyField.B_intit(-1, -1);
			EnemyField.E_intit(-1, -1);
			std::pair<int, int> shoot = EnemyField.F_shoot();
			std::cout << static_cast<char>(shoot.second + 'A') << " " << shoot.first << std::endl;
			/*for (i = 0; i < 10; ++i)
			{
				std::cout << std::endl;
				for (j = 0; j < 10; ++j)
					std::cout << EnemyField[i][j];
			}*/
		}
		else if (command == "Win!")
		{
			break;
		}
		else if (command == "Lose")
		{
			break;
		}
		else
		{
			int do_nothing = 0;
			++do_nothing;
		}
	}
	//	std::cout << std::endl;
}