#include "Cell.h"
#include <iostream>
#include <vector>
class Body
{
public:
	Body()
	{
		B = std::vector < std::vector<Cell> >(10, std::vector<Cell>(10));
		B_prev = B;
		sells_alive = 0;
	}
	void evolution();
	std::vector<Cell>& operator[](int n)
	{
		return B[n];
	}
	/*std::vector<Cell>& operator[](int n) // for making const []
	{
		return B[n];
	}*/
	Body& operator = ( Body &BB) //there should be const
	{
		if (this != &BB)
		{
			B = BB.B;
			B_prev = BB.B_prev;
			sells_alive = BB.sells_alive;
		}
		return *this;
	}
	bool is_alive();
	void inc_alive() { ++sells_alive; return; }
	void reset();
	void show(int n);
	void upd_prev() { B_prev = B; }
	bool cmp_Bs();
	void step_back() { B = B_prev; }
private:
	std::vector<std::vector<Cell>> B;
	std::vector<std::vector<Cell>> B_prev;
	unsigned int sells_alive;
};