#include "AdminFunctions.h"

void adminFunction(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	while (true)
	{
		int choice1, choice2, choice3;
		system("cls");
		adminMenu();
		choice1 = defence(5);
		system("cls");
		if (choice1 == 1) {
			while (true)
			{
				system("cls");
				fileMenu();
				choice2 = defence(4);
				if (choice2 == 1)
				{
					createFile(vec_of_accounts, vec_of_bus);
					createAdminAccount(vec_of_accounts);
				}
				if (choice2 == 2)
				{
					openFile(vec_of_accounts, vec_of_bus);
				}
				if (choice2 == 3)
				{
					deleteFile(vec_of_accounts, vec_of_bus);
				}
				if (choice2 == 0)
				{
					break;
				}
			}
		}
		if (choice1 == 2) {
			while (true) {
				system("cls");
				accountMenu();
				choice2 = defence(5);
				if (choice2 == 1)
				{
					generateAccountsVector(vec_of_accounts);
					writeEndFileAccounts(vec_of_accounts);
				}
				if (choice2 == 2)
				{
					deleteAccount(vec_of_accounts);
				}
				if (choice2 == 3)
				{
					editAccounts(vec_of_accounts);
				}
				if (choice2 == 4)
				{
					showAccountArray(vec_of_accounts);
				}
				if (choice2 == 0)
				{
					break;
				}
			}
		}
		if (choice1 == 3) {
			while (true) {
				system("cls");
				dataMenu();
				choice2 = defence(5);
				if (choice2 == 1)
				{
					generateBusVector(vec_of_bus);
					writeEndFileBus(vec_of_bus);
				}
				if (choice2 == 2)
				{
					deleteBus(vec_of_bus);
				}
				if (choice2 == 3)
				{
					editBus(vec_of_bus);
				}
				if (choice2 == 4)
				{
					hatMenu();
					for (int i = 0; i < vec_of_bus.size(); i++)
					{
						showFindedBus(vec_of_bus, i);
					}
					system("pause");
				}
				if (choice2 == 0)
				{
					break;
				}
			}
		}
		if (choice1 == 4) {
			while (true) {
				system("cls");
				userMenu();
				choice2 = defence(5);
				if (choice2 == 1)
				{
					searchBus(vec_of_bus);
				}
				if (choice2 == 2)
				{
					while (true)
					{

						system("cls");
						sortMenu();
						choice3 = defence(4);
						system("cls");
						if (choice3 == 1)
						{
							sortName(vec_of_bus);
						}
						if (choice3 == 2)
						{
							sortArrival(vec_of_bus);
						}
						if (choice3 == 3)
						{
							sortDeparture(vec_of_bus);
						}
						if (choice3 == 0)
						{
							break;
						}
					}
				}
				if (choice2 == 3)
				{
					while (true)
					{
						system("cls");
						searchMenu();
						choice3 = defence(4);
						system("cls");
						if (choice3 == 1)
						{
							searchString(vec_of_bus, choice3);
						}
						if (choice3 == 2)
						{
							searchString(vec_of_bus, choice3);
						}
						if (choice3 == 3)
						{
							searchString(vec_of_bus, choice3);
						}
						if (choice3 == 0)
						{
							break;
						}
					}
				}
				if (choice2 == 4)
				{
					hatMenu();
					for (int i = 0; i < vec_of_bus.size(); i++)
					{
						showFindedBus(vec_of_bus, i);
					}
					system("pause");
				}
				if (choice2 == 0)
				{
					break;
				}
			}
		}
		if (choice1 == 0)
		{
			clearVectors(vec_of_accounts, vec_of_bus);
			main();
		}
	}
}
void adminMenu()
{
	cout << "=============================" << endl;
	cout << "~~~~~~~~Admin functions~~~~~~~" << endl;
	cout << " 1 - File menu" << endl;
	cout << " 2 - Account menu " << endl;
	cout << " 3 - Data menu" << endl;
	cout << " 4 - User menu" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}

void fileMenu()
{

	cout << "=============================" << endl;
	cout << "~~~~~~~~File functions~~~~~~~~" << endl;
	cout << " 1 - Create file" << endl;
	cout << " 2 - Open file" << endl;
	cout << " 3 - Delete file" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}
void accountMenu()
{

	cout << "=============================" << endl;
	cout << "~~~~~~Account functions~~~~~~~" << endl;
	cout << " 1 - Create account" << endl;
	cout << " 2 - Delete account " << endl;
	cout << " 3 - Edit account" << endl;
	cout << " 4 - View a list of accounts" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}
void dataMenu()
{
	cout << "=============================" << endl;
	cout << "~~~~~~Schedule functions~~~~~~" << endl;
	cout << " 1 - Create bus travel" << endl;
	cout << " 2 - Delete bus travel " << endl;
	cout << " 3 - Edit bus travel" << endl;
	cout << " 4 - View a list of bus" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "=============================" << endl;
	cout << " 0 - Log out" << endl;
	cout << "=============================" << endl;
	cout << "Your choice: ";
}
