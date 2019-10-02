#pragma once
#include "Main.h"
const bool compareName(const Bus, const Bus);
const bool compareArrival(const Bus, const Bus);
const bool compareDeparture(const Bus, const Bus);
int searchBus(vector<Bus>& vec_of_bus);
void showFindedBus(vector<Bus>& vec_of_bus, int i);
int sortName(vector<Bus>& vec_of_bus);
int sortArrival(vector<Bus>& vec_of_bus);
int sortDeparture(vector<Bus>& vec_of_bus);
void hatMenu();
int searchString(vector<Bus>& vec_of_bus, int search_type);
