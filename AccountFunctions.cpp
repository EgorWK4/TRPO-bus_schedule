#include "AccountFunctions.h"
void showAccountArray(vector <Account>& vec_of_accounts)
{
	cout << "============================================" << endl;
	cout << "| Position |  Login  |  Password  |  Role  |" << endl;
	cout << "============================================" << endl;
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		cout << "|" << setw(5) << i + 1 << ". " << setw(5) << " | " << setw(7) << vec_of_accounts.at(i).login << " | " << setw(10) <<
			vec_of_accounts.at(i).password << " | " << setw(4)
			<< vec_of_accounts.at(i).role << "   |   " << endl;
		cout << "============================================" << endl;
	}
	system("pause");
}
void writeEndFileAccounts(vector <Account>& vec_of_accounts)
{
	ofstream fadd(FILE_OF_DATA, ios::app); //Открыли файл для дозаписи
	fadd << endl;
	fadd << vec_of_accounts.at(vec_of_accounts.size() - 1).login << " "
		<< vec_of_accounts.at(vec_of_accounts.size() - 1).password << " "
		<< vec_of_accounts.at(vec_of_accounts.size() - 1).role;
	fadd.close();
}
void readFileAccounts(vector <Account>& vec_of_accounts)
{
	ifstream read(FILE_OF_DATA, ios::in); //Открыли файл для чтения
	if (!read.is_open()) cout << "There are no such file" << endl;
	else
	{
		Account account_temp;
		while (!read.eof())
		{
			read >> account_temp.login >> account_temp.password >> account_temp.role;
			vec_of_accounts.push_back(account_temp);
		}
	}
	read.close(); //Закрыли открытый файл
}
void createAdminAccount(vector <Account>& vec_of_accounts)
{
	ifstream read(FILE_OF_DATA, ios::in); //Открыли файл для чтения
	if (!read.is_open()) {
		ofstream ofs(FILE_OF_DATA);
		Account account_admin;
		account_admin.login = "admin";
		account_admin.password = "admin";
		account_admin.role = 1;
		vec_of_accounts.push_back(account_admin);
		writeEndFileAccounts(vec_of_accounts);
		vec_of_accounts.clear();
	}
	read.close(); //Закрыли открытый файл
}
void writeAccountVector(vector<Account>& vec_of_accounts)
{
	ofstream fout(FILE_OF_DATA, ios::out); //Открыли файл для записи
	fout << endl;
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (i < vec_of_accounts.size())
		{
			fout << endl;
		}
		fout << vec_of_accounts.at(i).login << " "
			<< vec_of_accounts.at(i).password << " "
			<< vec_of_accounts.at(i).role;
	}
	fout.close();
}
void generateAccountsVector(vector<Account>& vec_of_accounts)
{
	Account new_account;
	bool flag = 0;
	while (flag == false)
	{
		cout << "Input the login ";
		cin >> new_account.login;
		flag = isAccountUnique(vec_of_accounts, new_account.login);
	}
	cout << "Input the password ";
	cin >> new_account.password;
	cout << "Input the role ";
	new_account.role = defence(2);
	vec_of_accounts.push_back(new_account);
}
int deleteAccount(vector <Account>& vec_of_accounts)
{
	int delete_position, choice;
	cout << "Input the position of account, you wan't to delete:" << endl;	showAccountArray(vec_of_accounts);
	delete_position = defence(vec_of_accounts.size() + 1);
	delete_position--;
	cout << "Are you sure you wan't to delete this account?" << endl;
	cout << "Yes - 1 || No - 0" << endl;
	cout << "Your choice: " << endl;
	choice = defence(2);
	if (choice == 0)
	{
		return 0;
	}
	vec_of_accounts.erase(vec_of_accounts.begin() + delete_position);
	writeAccountVector(vec_of_accounts);
}
bool isAccountUnique(vector<Account>& vec_of_accounts, string& check_login)
{
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (check_login == vec_of_accounts.at(i).login)
		{
			cout << "There are such account!" << endl;
			return(false);
		}
	}
	return true;

}
int editAccounts(vector<Account>& vec_of_accounts)
{
	int change_position, new_role, change_role, choice;
	string  new_password;
	cout << "Input the position of account, you wan't to change: " << endl;
	showAccountArray(vec_of_accounts);
	change_position = defence(vec_of_accounts.size() + 1);
	change_position--;
	cout << "Are you sure you wan't to change this account?" << endl;
	cout << "Yes - 1 || No - 0" << endl;
	cout << "Your choice: " << endl;
	choice = defence(2);
	if (choice == 0)
	{
		return 0;
	}
	system("cls");
	cout << "Input a new password - ";
	cin >> new_password;
	cout << "Would you like to change the role?" << endl << "Yes - 1|| No - 0 " << endl;
	change_role = defence(2);
	if (change_role == 1)
	{
		cout << "Input a new role - ";
		new_role = defence(2);
		vec_of_accounts.at(change_position).role = new_role;
	}
	vec_of_accounts.at(change_position).password = new_password;
	writeAccountVector(vec_of_accounts);
}

