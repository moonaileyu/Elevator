#include <iostream>
using namespace std;

class Elevator
{
private:
	int FloorDown;
	int FloorUp;
	int FloorNow;
	bool power;

public:
	Elevator(int down, int up)
	{
		FloorDown = down;
		FloorUp = up;
		FloorNow = down;
		power = false;
	}

	void Working()
	{
		power = true;
		cout << "Elevator is working.\n";
	}

	void NotWorking()
	{
		power = false;
		cout << "Elevator is not working.\n";
	}

	bool GetStatus()
	{
		return power;
	}

	int GetFloor()
	{
		return FloorNow;
	}

	void GetElevator(int floor)
	{
		if (power == false)
		{
			cout << "Elevator is not working.\n";
			return;
		}
		if (floor > FloorUp || floor < FloorDown)
		{
			cout << "Unable to recognize floor.\n";
			return;
		}
		if (floor == FloorNow)
		{
			cout << "The elevator is already on this floor!\n";
			return;
		}

		cout << "The elevator starts moving from the " << FloorNow << " floor. . .\n";

		if (floor > FloorNow)
		{
			for (int i = FloorNow + 1; i <= floor; i++)
			{
				cout << "The elevator passes the " << i << " floor. . .\n";
			}
		}
		else
		{
			for (int i = FloorNow - 1; i >= floor; i--)
			{
				cout << "The elevator passes the " << i << " floor. . .\n";
			}
		}
		FloorNow = floor;
		cout << "The elevator arrived at the " << FloorNow << " floor!\n";
	}
};


int main()
{
	Elevator obj1(1, 15);

	obj1.Working();
	obj1.GetStatus();
	obj1.GetElevator(4);
	obj1.GetElevator(4);
	obj1.GetElevator(2);
	obj1.GetElevator(7);
	obj1.GetElevator(22);
	obj1.NotWorking();
	obj1.GetElevator(2);

	return 0;
}