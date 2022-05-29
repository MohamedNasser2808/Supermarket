#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

static bool isLogged;

class Admin {
private:
	unsigned cNumber;
	string email, cMail, cGender, cName, choiceLog;
	int password, cAge, cPass;

public:
	Admin(string mail, int pass);
	bool checkLogManager(string mail, int pass);
	void creation(int ID, string IDStr, string as);
	void createClients();
	void Display_Clients();
	void checkLoggingIn();

	~Admin();
};
