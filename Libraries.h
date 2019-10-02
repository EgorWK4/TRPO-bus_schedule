#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#define NOMINMAX
#include <Windows.h>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;
struct Account
{
	string login;
	string password;
	int role;
};
struct Bus
{
	string bus_number;
	string bus_type;
	string destination;
	int arrival_time;
	int arrival_time_minute;
	int departure_time;
	int departure_time_minute;
};
//const string FILE_OF_DATA = "E://OAiP//Sem2//Kursach//LogFiles//Accounts.txt"; //Путь к файлу аккаунтов
//const string FILE_OF_SCHEDULE = "E://OAiP//Sem2//Kursach//LogFiles//Schedule.txt"; // Путь к файлу расписания автобусов

const string FILE_OF_DATA = "C://Users//Admin//source//repos//bus_schedule//bus_schedule//Accounts.txt";//Путь к файлу аккаунтов

const string FILE_OF_SCHEDULE = "C://Users//Admin//source//repos//bus_schedule//bus_schedule//Schedule.txt";//// Путь к файлу расписания автобусов
