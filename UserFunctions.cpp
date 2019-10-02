#include "UserFunctions.h"

void userFunction(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	while (true) {
		int choice1, choice2;
		system("cls");
		userMenu();
		choice1 = defence(5);
		system("cls");
		if (choice1 == 1)
		{
			searchBus(vec_of_bus);
		}
		if (choice1 == 2)
		{
			while (true)
			{
				system("cls");
				sortMenu();
				choice2 = defence(4);
				system("cls");
				if (choice2 == 1)
				{
					sortName(vec_of_bus);
				}
				if (choice2 == 2)
				{
					sortArrival(vec_of_bus);
				}
				if (choice2 == 3)
				{
					sortDeparture(vec_of_bus);
				}
				if (choice2 == 0)
				{
					break;
				}
			}
		}
		if (choice1 == 3)
		{
			while (true)
			{
				system("cls");
				searchMenu();
				choice2 = defence(4);
				system("cls");
				if (choice2 == 1)
				{
					searchString(vec_of_bus, choice2);
				}
				if (choice2 == 2)
				{
					searchString(vec_of_bus, choice2);
				}
				if (choice2 == 3)
				{
					searchString(vec_of_bus, choice2);
				}
				if (choice2 == 0) {
					break;
				}
			}
		}
		if (choice1 == 4) {
			hatMenu();
			for (int i = 0; i < vec_of_bus.size(); i++)
			{
				showFindedBus(vec_of_bus, i);
			}
			system("pause");
		}
		if (choice1 == 0)
		{
			clearVectors(vec_of_accounts, vec_of_bus);
			main();
		}
	}
}
void userMenu()
{
	cout << "=============================" << endl;
	cout << "~~~~~Available functions~~~~~" << endl;
	cout << " 1 - Search 12hour travel" << endl;
	cout << " 2 - Sort menu" << endl;
	cout << " 3 - Search menu" << endl;
	cout << " 4 - View a list of travels" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}
void sortMenu()
{
	cout << "=============================" << endl;
	cout << "~~~~~~~Sort functions~~~~~~~~" << endl;
	cout << " 1 - Sort by the name of the travel " << endl;
	cout << " 2 - Sort by the arrival time of the travel " << endl;
	cout << " 3 - Sort by the departure time of the travel " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}
void searchMenu()
{
	cout << "=============================" << endl;
	cout << "~~~~~~~Search functions~~~~~~~~" << endl;
	cout << " 1 - Search by the name of the travel " << endl;
	cout << " 2 - Search by the type of the bus " << endl;
	cout << " 3 - Search by the destination " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}
