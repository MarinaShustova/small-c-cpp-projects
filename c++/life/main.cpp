#include "Cell.h"
#include "Executor.h"
int main()
{
	Body BB;
	Executor RR;
	std::string command = "";
	std::string com = "", fn = "";
	int X, Y;
	RR.set_steps(0);
	BB.show(0);
	while (1)
	{
		std::getline(std::cin, command);
		RR.get_command(command, BB, com, X, Y, fn);
		RR.perform_command(com, X, Y, BB, fn);
		if ((!BB.is_alive() || BB.cmp_Bs()) && (com == "step") && (fn != "nvm"))
		{
			std::cout << "End of the game, please try again" << std::endl;
			BB.reset();
			BB.show(0);
			RR.set_steps(0);
		}
	}
	return 0;
}