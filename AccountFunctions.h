#pragma once
#include "Main.h"
// Account functions
void generateAccountsVector(vector <Account>& vec_of_accounts);
void writeEndFileAccounts(vector <Account>& vec_of_accounts);
int deleteAccount(vector<Account>& vec_of_accounts);
void readFileAccounts(vector <Account>& vec_of_accounts);
void showAccountArray(vector <Account>& vec_of_accounts);
int editAccounts(vector<Account>& vec_of_accounts);
bool isAccountUnique(vector<Account>& vec_of_accounts, string& check_login);
void createAdminAccount(vector<Account>& vec_of_accounts);
void writeAccountVector(vector<Account>& vec_of_accounts);

