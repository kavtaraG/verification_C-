#ifndef USERANDPASS_H
#define USERANDPASS_H

#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;

class User_and_pass
{
private:
	string password;
	vector<string> existing_password;
	vector<string> existing_username;

	friend class Admin_user;

public:
	string username;
	void set_username();
	string set_password();

	User_and_pass();
	User_and_pass(const string &set_username, const string &set_password);
	~User_and_pass();
};

User_and_pass::User_and_pass() : username(""), password("")
{

};

User_and_pass::User_and_pass(const string &set_username, const string &set_password)
{
}

User_and_pass::~User_and_pass()
{
}

void User_and_pass::set_username()
{
	string exit, local_username;
	local_username = username;
	bool is_username_dublicated;

	do
	{
		cout << "Username: ";
		cin >> local_username;
		cout << "\n";

		is_username_dublicated = false;

		for(auto &u : existing_username)
		{
			if(u == local_username)
			{
				is_username_dublicated = true;
				cout << "Username exist, try again\n";
				break;
			};
		};

		if(is_username_dublicated)
		{
			cout << "New username\n";
			continue;
		};

		existing_username.push_back(local_username);
		cout << "Username pushed\n";
		cout << "*******************************\n";

		for(auto &push : existing_username)
		{
			cout << "-" << push << "\n";
		};

		cout << "To quit press Y, else press N\n";
		cin >> exit;

	} while (exit == "Y" && !exit.empty());
	
};


string User_and_pass::set_password()
{
	string exit, local_password;
	bool is_password_dublicated;
	local_password = password;
	
	do
	{
		set_username();
			cout << "Password: ";
			cin >> local_password;
			cout << "\n";

			is_password_dublicated = false;

		for(auto &p : existing_password)
		{
			if(p == local_password)
			{
				is_password_dublicated = true;
				cout << "Password exists, try again\n";
				break;
			};
		};

		if(is_password_dublicated)
		{
			cout << "New password\n";
			continue;
		};

		existing_password.push_back(local_password);
		cout << "Password pushed\n";

		cout << "**********************************\n";

		for(auto &pp : existing_password)
		{
			cout << "-" << pp << "\n";
		};

		cout << "To quit press Y, else press N\n";
		cin >> exit;

	} while (exit == "Y" && !exit.empty());
	
	
};

#endif //USERANDPASS_H