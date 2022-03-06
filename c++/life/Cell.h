#pragma once
class Cell
{
public:
	Cell() { state = 0; neigbours_amout = 0; }
	void set() { state = 1; return; }
	void kill() { state = 0; return;  }
	void neigh(unsigned int n) { neigbours_amout = n; return; }
	bool gt_state() { return state; }
	Cell& operator = (const Cell& CC)
	{
		if (this != &CC)
		{
			state = CC.state;
			neigbours_amout = CC.neigbours_amout;
		}
		return *this;
	}
	bool operator == (bool n)
	{
		if (state == n)
			return true;
		return false;
	}
private:
	bool state;
	unsigned int neigbours_amout;
};