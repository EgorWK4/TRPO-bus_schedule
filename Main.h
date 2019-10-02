#pragma once
#include "Libraries.h"
#include "FileFunctions.h"
#include "AccountFunctions.h"
#include "BusFunctions.h"
#include "UserFunctions.h"
#include "AdminFunctions.h"
#include "Individual_Quest.h"
int defence(int);
void main();
void clearVectors(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus);
void authorisation(vector<Account>& vec_of_accounts, vector<Bus>& vec_of_bus);

