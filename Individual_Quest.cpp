#include "Individual_Quest.h"

int searchBus(vector<Bus>& vec_of_bus)
{
	int time_1, time_2;
	cout << "=============================" << endl;
	cout << " Input necessary time" << endl;
	cout << "=============================" << endl;
	time_1 = defence(25);
	time_2 = time_1;
	bool isTime12 = false;
	if (time_1 > 12)
	{
		time_1 -= 12;
		time_2 -= 13;
		isTime12 = false;
	}
	else
	{
		if (time_1 == 12)
		{
			isTime12 = true;
			time_1 -= 12;
			time_2 += 11;
		}
		else if (time_1 < 12)
		{
			isTime12 = false;
			time_1 += 12;
			time_2 += 11;
		}
	}
	system("cls");
	int i = 0;
	if (isTime12 == false) {
		if (vec_of_bus.at(i).arrival_time <= time_1 && vec_of_bus.at(i).arrival_time >= time_2)
		{
			hatMenu();
			showFindedBus(vec_of_bus, i);

			for (i++; i < vec_of_bus.size(); i++)
			{
				if (vec_of_bus.at(i).arrival_time > time_1 || vec_of_bus.at(i).arrival_time < time_2)
				{
					continue;
				}
				else {
					if (vec_of_bus.at(i).arrival_time <= time_1 && vec_of_bus.at(i).arrival_time >= time_2)
					{
						hatMenu();
						showFindedBus(vec_of_bus, i);
					}
				}
			}
			system("pause");

		}
		else
		{
			for (i = 0; i < vec_of_bus.size(); i++)
			{
				if (vec_of_bus.at(i).arrival_time > time_1 || vec_of_bus.at(i).arrival_time < time_2)
				{
					continue;
				}
				else {
					if (vec_of_bus.at(i).arrival_time <= time_1 && vec_of_bus.at(i).arrival_time >= time_2)
					{
						hatMenu();
						showFindedBus(vec_of_bus, i);
						system("pause");
						continue;
					}
				}
				cout << "No such bus travels" << endl;
				system("pause");
			}
		}
	}
	if (isTime12 == true)
	{
		for (i = 0; i < vec_of_bus.size(); i++) {
			if (vec_of_bus.at(i).arrival_time == time_1 || vec_of_bus.at(i).arrival_time == time_2)
			{
				hatMenu();
				showFindedBus(vec_of_bus, i);
				system("pause");
			}
		}
	}
	return(0);
}

int sortName(vector<Bus>& vec_of_bus)
{
	cout << "=============================" << endl;
	cout << "~~~~~~~~~~Sort type~~~~~~~~~~" << endl;
	cout << "1 - Sort by alphabet " << endl;
	cout << "0 - Exit to the previous menu" << endl;
	cout << "=============================" << endl;
	int choice;
	choice = defence(2);
	if (choice == 1)
	{
		sort(vec_of_bus.begin(), vec_of_bus.end(), compareName);
		system("cls");
		hatMenu();
		for (int i = 0; i < vec_of_bus.size(); i++)
		{
			showFindedBus(vec_of_bus, i);
		}
		system("pause");
	}
	if (choice == 0)
	{
		return(0);
	}
}
int sortArrival(vector<Bus>& vec_of_bus)
{
	cout << "=============================" << endl;
	cout << "~~~~~~~~~~Sort type~~~~~~~~~~" << endl;
	cout << "1 - Sort with expansion" << endl;
	cout << "0 - Exit to the previous menu" << endl;
	cout << "=============================" << endl;
	int choice;
	choice = defence(2);
	if (choice == 1)
	{
		sort(vec_of_bus.begin(), vec_of_bus.end(), compareArrival);
		system("cls");
		hatMenu();
		for (int i = 0; i < vec_of_bus.size(); i++)
		{
			showFindedBus(vec_of_bus, i);
		}
		system("pause");
	}
	if (choice == 0)
	{
		return(0);
	}
}
int sortDeparture(vector<Bus>& vec_of_bus)
{
	cout << "=============================" << endl;
	cout << "~~~~~~~~~~Sort type~~~~~~~~~~" << endl;
	cout << "1 - Sort with expansion" << endl;
	cout << "0 - Exit to the previous menu" << endl;
	cout << "=============================" << endl;
	int choice;
	choice = defence(2);
	if (choice == 1)
	{
		sort(vec_of_bus.begin(), vec_of_bus.end(), compareDeparture);
		system("cls");
		hatMenu();
		for (int i = 0; i < vec_of_bus.size(); i++)
		{
			hatMenu();
			for (int i = 0; i < vec_of_bus.size(); i++)
			{
				showFindedBus(vec_of_bus, i);
			}
			system("pause");
		}
	}
	if (choice == 0)
	{
		return(0);
	}
}
const bool compareName(const Bus LHS, const Bus RHS)
{
	return(LHS.bus_number < RHS.bus_number);
}
const bool compareArrival(const Bus LHS, const Bus RHS)
{
	return(LHS.arrival_time < RHS.arrival_time);
}
const bool compareDeparture(const Bus LHS, const Bus RHS)
{
	return(LHS.departure_time < RHS.departure_time);
}
void showFindedBus(vector<Bus>& vec_of_bus, int i)
{

	if (vec_of_bus.at(i).departure_time_minute < 10 && vec_of_bus.at(i).arrival_time_minute >= 10)
	{
		cout << "|" << setw(5) << i + 1 << ". " << setw(5) << " | " << setw(12) << vec_of_bus.at(i).bus_number << " | " << setw(10)
			<< vec_of_bus.at(i).bus_type << " | " << setw(15) << vec_of_bus.at(i).destination << " | " << setw(15)
			<< vec_of_bus.at(i).departure_time << ":0" << vec_of_bus.at(i).departure_time_minute << " | " << setw(13) << vec_of_bus.at(i).arrival_time << ":" << vec_of_bus.at(i).arrival_time_minute << " |" << endl;
	}
	if (vec_of_bus.at(i).departure_time_minute < 10 && vec_of_bus.at(i).arrival_time_minute < 10)
	{
		cout << "|" << setw(5) << i + 1 << ". " << setw(5) << " | " << setw(12) << vec_of_bus.at(i).bus_number << " | " << setw(10)
			<< vec_of_bus.at(i).bus_type << " | " << setw(15) << vec_of_bus.at(i).destination << " | " << setw(15)
			<< vec_of_bus.at(i).departure_time << ":0" << vec_of_bus.at(i).departure_time_minute << " | " << setw(13) << vec_of_bus.at(i).arrival_time << ":0" << vec_of_bus.at(i).arrival_time_minute << " |" << endl;
	}
	if (vec_of_bus.at(i).departure_time_minute >= 10 && vec_of_bus.at(i).arrival_time_minute >= 10)
	{
		cout << "|" << setw(5) << i + 1 << ". " << setw(5) << " | " << setw(12) << vec_of_bus.at(i).bus_number << " | " << setw(10)
			<< vec_of_bus.at(i).bus_type << " | " << setw(15) << vec_of_bus.at(i).destination << " | " << setw(15)
			<< vec_of_bus.at(i).departure_time << ":" << vec_of_bus.at(i).departure_time_minute << " | " << setw(13) << vec_of_bus.at(i).arrival_time << ":" << vec_of_bus.at(i).arrival_time_minute << " |" << endl;
	}
	else if (vec_of_bus.at(i).departure_time_minute >= 10 && vec_of_bus.at(i).arrival_time_minute < 10)
	{
		cout << "|" << setw(5) << i + 1 << ". " << setw(5) << " | " << setw(12) << vec_of_bus.at(i).bus_number << " | " << setw(10)
			<< vec_of_bus.at(i).bus_type << " | " << setw(15) << vec_of_bus.at(i).destination << " | " << setw(15)
			<< vec_of_bus.at(i).departure_time << ":" << vec_of_bus.at(i).departure_time_minute << " | " << setw(13) << vec_of_bus.at(i).arrival_time << ":0" << vec_of_bus.at(i).arrival_time_minute << " |" << endl;
	}
	cout << "==================================================================================================" << endl;
}
void hatMenu()
{
	cout << "==================================================================================================" << endl;
	cout << "| Position |  Bus number  |  Bus type  |   Destination   |   Departure time   |   Arrival time   |" << endl;
	cout << "==================================================================================================" << endl;
}
int searchString(vector<Bus>& vec_of_bus, int search_type)
{
	int check = 0;
	string input_string;
	cout << "Input the info, you wan't to search" << endl;
	cin >> input_string;
	cout << "==================================================================================================" << endl;
	for (int i = 0; i < vec_of_bus.size(); i++)
	{
		if ((vec_of_bus.at(i).bus_number.find(input_string) != string::npos && search_type == 1) || (vec_of_bus.at(i).bus_type.find(input_string) != string::npos && search_type == 2) || (vec_of_bus.at(i).destination.find(input_string) != string::npos && search_type == 3))
		{
			showFindedBus(vec_of_bus, i);
			check++;
		}
	}
	if (check == 0)
	{
		cout << "There are no such travels!" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	system("pause");
	system("cls");
	return 0;
}
