#include "Body.h"
void Body::evolution()
{
	Body res;
	unsigned int i, j, n;
	for (i = 0; i<10; ++i)
		for (j = 0; j < 10; ++j)
		{
			n = 0;
			if ((*this)[(i + 10) % 10][(j + 10 - 1) % 10] == true)
				++n;
			if ((*this)[(i + 10 - 1) % 10][(j + 10 - 1) % 10] == true)
				++n;
			if ((*this)[(i + 10 - 1) % 10][(j + 10) % 10] == true)
				++n;
			if ((*this)[(i + 10 - 1) % 10][(j + 10 + 1) % 10] == true)
				++n;
			if ((*this)[(i + 10) % 10][(j + 10 + 1) % 10] == true)
				++n;
			if ((*this)[(i + 10 + 1) % 10][(j + 10 + 1) % 10] == true)
				++n;
			if ((*this)[(i + 10 + 1) % 10][(j + 10) % 10] == true)
				++n;
			if ((*this)[(i + 10 + 1) % 10][(j + 10 - 1) % 10] == true)
				++n;
			res[i][j].neigh(n);
			if ((((*this)[i][j] == false) && (3 == n)) || (((*this)[i][j] == true) && ((n == 3) || (n == 2))))
			{
				res[i][j].set();
				++res.sells_alive;
			}
		}
	res.B_prev = B;
	(*this) = res;
	return;
}
bool Body::is_alive()
{
	if (sells_alive != 0)
		return true;
	return false;
}
void Body::reset()
{
	int i, j;
	for (i = 0; i < 10; ++i)
		for (j = 0; j < 10; ++j)
		{
			if ((*this)[i][j] == true)
			{
				(*this)[i][j].kill();
				--sells_alive;
			}
		}
	return;
}
void Body::show(int n)
{
	int i, j;
	for (i = 0; i < 10; ++i)
	{
		if (i == 0)
		{
			std::cout << " ABCDEFGHIJ";
		}
		std::cout << std::endl;
		for (j = 0; j < 10; ++j)
		{
			if (j == 0)
				std::cout << i;
			if ((*this)[i][j] == false)
				std::cout << ".";
			else
				std::cout << "*";
		}
	}
	std::cout << std::endl<<"Steps: "<<n<<std::endl;
}
bool Body::cmp_Bs()
{
	int i, j, c = 0;
	for (i = 0; i < 10; ++i)
		for (j = 0; j < 10; ++j)
			if (B[i][j].gt_state() == B_prev[i][j].gt_state())
				++c;
	if (100 == c)
		return true;
	return false;
}