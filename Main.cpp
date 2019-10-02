#include "Main.h"

vector <Account>vec_of_accounts;
vector<Bus>vec_of_bus;

void main()
{
	system("cls");
	cout << "=============================" << endl;
	cout << "~~~~~~~~~~Welcome!~~~~~~~~~~~" << endl;
	createAdminAccount(vec_of_accounts);
	readFileAccounts(vec_of_accounts);
	readFileBus(vec_of_bus);
	authorisation(vec_of_accounts, vec_of_bus);
}
void authorisation(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	string login, password;
	int choice;
	cout << "=============================" << endl;
	cout << "Would you like to login?" << endl;
	cout << "Yes - 1 || No - 0" << endl;
	cout << "=============================" << endl;
	choice = defence(2);
	if (choice == 1)
	{
		string login, password;
		cout << "Input the login - ";
		cin >> login;
		cout << "Input the password - ";
		cin >> password;
		int i = 0;
		if (vec_of_accounts.at(i).login == login && vec_of_accounts.at(i).password == password)
		{
			if (vec_of_accounts.at(i).role == 0)
			{
				userFunction(vec_of_accounts, vec_of_bus);
			}
			else
			{
				adminFunction(vec_of_accounts, vec_of_bus);
			}
		}
		else if (vec_of_accounts.at(i).login != login || vec_of_accounts.at(i).password != password)
		{
			for (i = 1; i < vec_of_accounts.size(); i++)
			{
				if (vec_of_accounts.at(i).login != login || vec_of_accounts.at(i).password != password)
				{
					continue;
				}
				else
				{
					if (vec_of_accounts.at(i).role == 0)
					{
						userFunction(vec_of_accounts, vec_of_bus);
					}
					else
					{
						adminFunction(vec_of_accounts, vec_of_bus);
					}
				}
			}
		}

	}
	if (choice == 0)
	{
		exit(0);
	}
	system("cls");
	cout << "Password is incorrect / Login is wrong" << endl;
	cout << "Try again?" << endl;
	cout << "Yes - 1 || No - 0" << endl;
	choice = defence(2);

	if (choice == 0)
	{
		exit(0);
	}
	if (choice == 1)
	{
		authorisation(vec_of_accounts, vec_of_bus);
	}
}
int defence(int limit)
{
	while (true)
	{
		int choice;
		cin >> choice;
		system("cls");
		if (cin.get() == '\n')
		{
			if (choice < limit && choice >= 0)	return(choice);
			cout << "=============================" << endl;
			cout << "Incorrect input!" << endl;
			cout << "Try again!" << endl;
			cout << "=============================" << endl;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "=============================" << endl;
			cout << "Incorrect input!" << endl;
			cout << "Try again!" << endl;
			cout << "=============================" << endl;
		}

	}
	system("pause");
	system("cls");
}
void clearVectors(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	vec_of_bus.clear();
	vec_of_accounts.clear();
}
