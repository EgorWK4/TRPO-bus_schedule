#include "FileFunctions.h"

int createFile(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	int choice1, choice;
	cout << "====================================" << endl;
	cout << " Which file you wan't to create:" << endl;
	cout << " 1 - File with Accounts" << endl;
	cout << " 2 - File with Bus schedule" << endl;
	cout << " 0 - Return to the previous menu" << endl;
	cout << "====================================" << endl;
	choice = defence(3);
	if (choice == 1)
	{
		cout << "Are you sure you wan't to create/rewrite this file?" << endl;
		cout << "Yes - 1 || No - 0" << endl;
		cout << "Your choice: " << endl;
		choice1 = defence(2);
		if (choice1 == 0)
		{
			return 0;
		}
		ofstream ofs(FILE_OF_DATA);
		cout << "File has been created!" << endl;
		system("pause");
	}
	if (choice == 2)
	{
		cout << "Are you sure you wan't to create/rewrite this file?" << endl;
		cout << "Yes - 1 || No - 0" << endl;
		cout << "Your choice: " << endl;
		choice1 = defence(2);
		if (choice1 == 0)
		{
			return 0;
		}
		ofstream ofs(FILE_OF_SCHEDULE);
		cout << "File has been created!" << endl;
		system("pause");

	}
	if (choice == 0)
	{
		adminFunction(vec_of_accounts, vec_of_bus);
	}
}
int deleteFile(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	int choice, choice1;
	cout << "====================================" << endl;
	cout << " Which file you wan't to delete:" << endl;
	cout << " 1 - File with Accounts" << endl;
	cout << " 2 - File with Bus schedule" << endl;
	cout << " 0 - Return to the previous menu" << endl;
	cout << "====================================" << endl;
	choice = defence(3);
	if (choice == 1)
	{
		cout << "Are you sure you wan't to delete this file?" << endl;
		cout << "Yes - 1 || No - 0" << endl;
		cout << "Your choice: " << endl;
		choice1 = defence(2);
		if (choice1 == 0)
		{
			return 0;
		}
		//remove("E://OAiP//Sem2//Kursach//LogFiles//Accounts.txt");
		remove("C://Users//Admin//source//repos//bus_schedule//bus_schedule//Accounts.txt");
		vec_of_accounts.clear();
		cout << "File has been deleted!" << endl;
		system("pause");
	}
	if (choice == 2)
	{
		cout << "Are you sure you wan't to delete this file?" << endl;
		cout << "Yes - 1 || No - 0" << endl;
		cout << "Your choice: " << endl;
		choice1 = defence(2);
		if (choice1 == 0)
		{
			return 0;
		}
		//remove("E://OAiP//Sem2//Kursach//LogFiles//Schedule.txt");
		remove("C://Users//Admin//source//repos//bus_schedule//bus_schedule//Schedule.txt");

		vec_of_bus.clear();
		cout << "File has been deleted!" << endl;
		system("pause");
	}
	if (choice == 0)
	{
		adminFunction(vec_of_accounts, vec_of_bus);
	}
}
void openFile(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus)
{
	string filepath;
	cout << "====================================" << endl;
	cout << " Input the path to the file, you wan't to open: ";
	cin >> filepath;
	ifstream read(filepath, ios::in); //Открыли файл для чтения
	if (!read.is_open()) cout << "No such file!" << endl;
	else
	{
		Bus bus_temp;
		while (!read.eof())
		{
			read >> bus_temp.bus_number >> bus_temp.bus_type >> bus_temp.destination >> bus_temp.departure_time >> bus_temp.departure_time_minute >> bus_temp.arrival_time >> bus_temp.arrival_time_minute;
			vec_of_bus.push_back(bus_temp);
		}
	}
	read.close(); //Закрыли открытый файл}
}
