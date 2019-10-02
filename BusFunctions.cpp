#include "BusFunctions.h"
void generateBusVector(vector<Bus>& vec_of_bus)
{
	Bus new_bus;
	cout << "Input the number of travel ";
	cin >> new_bus.bus_number;
	cout << "Input the bus type ";
	cin >> new_bus.bus_type;
	cout << "Input the destination ";
	cin >> new_bus.destination;
	cout << "Input the departure time ";
	new_bus.departure_time = defence(25);
	if (new_bus.departure_time == 24)
	{
		new_bus.departure_time = 0;
	}
	cout << "Input the departure minutes ";
	new_bus.departure_time_minute = defence(61);
	cout << "Input the arrival time ";
	new_bus.arrival_time = defence(25);
	if (new_bus.arrival_time == 24)
	{
		new_bus.arrival_time = 0;
	}
	cout << "Input the arrival minutes ";
	new_bus.arrival_time_minute = defence(61);
	vec_of_bus.push_back(new_bus);
}
void writeEndFileBus(vector<Bus>& vec_of_bus)
{
	ofstream fadd(FILE_OF_SCHEDULE, ios::app); //Открыли файл для дозаписи
	fadd << endl;
	fadd << vec_of_bus.at(vec_of_bus.size() - 1).bus_number << " "
		<< vec_of_bus.at(vec_of_bus.size() - 1).bus_type << " " << vec_of_bus.at(vec_of_bus.size() - 1).destination << " "
		<< vec_of_bus.at(vec_of_bus.size() - 1).departure_time << " " << vec_of_bus.at(vec_of_bus.size() - 1).departure_time_minute << " " << vec_of_bus.at(vec_of_bus.size() - 1).arrival_time << " " << vec_of_bus.at(vec_of_bus.size() - 1).arrival_time_minute;
	fadd.close();
}
void readFileBus(vector<Bus>& vec_of_bus)
{
	ifstream read(FILE_OF_SCHEDULE, ios::in); //Открыли файл для чтения
	if (!read.is_open()) ofstream ofs(FILE_OF_SCHEDULE);
	else
	{
		Bus bus_temp;
		while (!read.eof())
		{
			read >> bus_temp.bus_number >> bus_temp.bus_type >> bus_temp.destination >> bus_temp.departure_time >> bus_temp.departure_time_minute >> bus_temp.arrival_time >> bus_temp.arrival_time_minute;
			vec_of_bus.push_back(bus_temp);
		}
	}
	read.close(); //Закрыли открытый файл
}
int editBus(vector<Bus>& vec_of_bus)
{
	int choice, change_position, new_arrival_time_minute, new_departure_time_minute, new_departure_time, new_arrival_time;
	string new_bus_number, new_bus_type, new_destination;
	cout << "Input the position of bus travel, you wan't to change: " << endl;
	hatMenu();
	for (int i = 0; i < vec_of_bus.size(); i++)
	{
		showFindedBus(vec_of_bus, i);
	}
	system("pause");
	change_position = defence(vec_of_bus.size() + 1);
	change_position--;
	cout << "Are you sure you wan't to change this travel?" << endl;
	cout << "Yes - 1 || No - 0" << endl;
	cout << "Your choice: " << endl;
	choice = defence(2);
	if (choice == 0)
	{
		return 0;
	}
	system("cls");
	cout << "==============================" << endl;
	cout << "~What would you like to edit?~" << endl;
	cout << "1 - Number" << endl;
	cout << "2 - Type" << endl;
	cout << "3 - Destination" << endl;
	cout << "4 - Departure time" << endl;
	cout << "5 - Arrival time" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "==============================" << endl;
	cout << "0 - Log out" << endl;
	cout << "==============================" << endl;
	choice = defence(6);
	if (choice == 1) {
		cout << "Input a new bus number - ";
		cin >> new_bus_number;
		vec_of_bus.at(change_position).bus_number = new_bus_number;
	}
	if (choice == 2) {
		cout << "Input a new bus type - ";
		cin >> new_bus_type;
		vec_of_bus.at(change_position).bus_type = new_bus_type;

	}
	if (choice == 3) {
		cout << "Input a new destination - ";
		cin >> new_destination;
		vec_of_bus.at(change_position).destination = new_destination;

	}
	if (choice == 4) {
		cout << "Input a new departure time - ";
		new_departure_time = defence(25);
		if (new_departure_time == 24)
		{
			new_departure_time = 0;
		}
		cout << "Input a new departure minute - ";
		new_departure_time_minute = defence(61);
		vec_of_bus.at(change_position).departure_time = new_departure_time;
		vec_of_bus.at(change_position).departure_time_minute = new_departure_time_minute;

	}
	if (choice == 5) {
		cout << "Input a new arrival time - ";
		new_arrival_time = defence(25);
		if (new_arrival_time == 24)
		{
			new_arrival_time = 0;
		}
		cout << "Input a new arrival minute - ";
		new_arrival_time_minute = defence(61);
		vec_of_bus.at(change_position).arrival_time_minute = new_arrival_time_minute;
		vec_of_bus.at(change_position).arrival_time = new_arrival_time;

	}
	if (choice == 0)
	{
		return(0);
	}
	writeBusVector(vec_of_bus);
}
int deleteBus(vector<Bus>& vec_of_bus)
{
	int delete_position, choice;
	cout << "Input the position of bus travel, you wan't to delete:" << endl;
	hatMenu();
	for (int i = 0; i < vec_of_bus.size(); i++)
	{
		showFindedBus(vec_of_bus, i);
	}
	system("pause");
	delete_position = defence(vec_of_bus.size() + 1);
	delete_position--;
	cout << "Are you sure you wan't to delete the account?" << endl;
	cout << "Yes - 1 || No - 0" << endl;
	cout << "Your choice: " << endl;
	choice = defence(2);
	if (choice == 0)
	{
		return 0;
	}
	system("cls");
	vec_of_bus.erase(vec_of_bus.begin() + delete_position);
	cout << vec_of_bus.size();
	writeBusVector(vec_of_bus);
}
void writeBusVector(vector<Bus>& vec_of_bus)
{
	ofstream fout(FILE_OF_SCHEDULE, ios::out); //Открыли файл для записи
	fout << endl;
	for (int i = 0; i < vec_of_bus.size(); i++)
	{
		if (i < vec_of_bus.size())
		{
			fout << endl;
		}
		fout << vec_of_bus.at(i).bus_number << " "
			<< vec_of_bus.at(i).bus_type << " " << vec_of_bus.at(i).destination << " "
			<< vec_of_bus.at(i).departure_time << " " << vec_of_bus.at(i).departure_time_minute << " " << vec_of_bus.at(i).arrival_time << " " << vec_of_bus.at(i).arrival_time_minute;
	}
	fout.close();
}

