#define _CRT_SECURE_NO_WARNINGS     //To remove warning messages

#include <iostream>
#include <string>
#include <direct.h>
#include <fstream>
#include <thread>

#include "admin.h"

using namespace std;

int Terminate = 1;
int choice;
bool isLog = false;

static Admin admin("email@gmail.com", 123456);

void Folders_Files() {
	_mkdir("C:/Supermarket_Files");
	_mkdir("C:/Supermarket_Files/admin");
	_mkdir("C:/Supermarket_Files/Products");
}

void adminSwitcher(int main()) { /// ======================>> admin Switcher <<====================
	string mail;  int pass;

	system("CLS");
	cout << "\n\n\n"
		<< "\t\t\t\t\tEnter [ 1 ] -> to: Login (Manager) :"
		<< "\n\n\t\t\t\t\tEnter [ 2 ] -> to: Login (Clients) :";
	this_thread::sleep_for(500ms);
	cout << "\n\n\n\t\t\t\t\t\t)-> Choice : ";
	cin >> choice;

	while (choice != 1 && choice != 2) {
		cout << "\n\n\n\t\t\t\t\t\tInvalid Input !!\n";
		this_thread::sleep_for(2000ms);
		cout << "\n\n\t\t\t\tYour Choice ->: ";
		cin >> choice;
	}

	if (choice == 1) { /// ======================>> Choice Manager <<=====================
		system("CLS");

		if (isLog == true) {
			cout << "\n\n\n\t\t\t\t\tYou Are Already Logged In !!\n";
			this_thread::sleep_for(3000ms);
			main();
		}

		cout << "\n\n\t\tEnter the Email ->: "; cin >> mail;
		cout << "\n\t\tEnter the Password (Numbers) =>: "; cin >> pass;

		if (admin.checkLogManager(mail, pass) == 0) {
			cout << "\n\n\t\t\t\t\tInvalid Email or Password\n";
			this_thread::sleep_for(3000ms);
			main();
		}

		if (admin.checkLogManager(mail, pass) == 1) {
			isLog = true;

			cout << "\n\n\t\tSUCCESSFULLY LOGGED IN ( Manager )\n";  this_thread::sleep_for(3000ms);
			main();
		}
	}

	if (choice == 2) { /// ======================>> Choice Clients <<=====================
		system("CLS");

		admin.createClients();
		cout << "\n\n\t\t\t\t\tTo Return Main Menu =>> Enter [1] :->  "; cin >> choice;

		if (choice == 1)
			main();
		else
			Terminate = 0;
	}
}

void display_clients(int main()) { /// ======================>> Display Clients Record <<====================
	string cChoice;
	system("CLS");

	cout << "\n\n\n\t\t\t\t\t\tClients Record :\n\n\n";
	admin.Display_Clients();
	cout << "\n\t----------------------------------------------------------------------------------------------------\n";
	cout << "\n\n\t\t\t\tDo You Want To Return Main Menu [ Yes , No ]  ->: "; cin >> cChoice;

	if (cChoice == "Y" || cChoice == "y" || cChoice == "YES" || cChoice == "yes")
		main();
	else
		Terminate = 0;
}

int main() {
	Folders_Files();

	do {
		system("CLS");
		system("color 06");

		cout << "\n\t\t"
			<< "\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\t\t"
			<< "\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\t\t"
			<< "\t\t\t@@@@@ --------> WELCOME to: <-------- @@@@@\n\t\t"
			<< "\t\t\t@@@@-> Supermarket Management System <-@@@@\n\t\t"
			<< "\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\t\t"
			<< "\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

		cout << "\n\n"
			<< "\t\t Enter [1]-> to :-> admin"
			<< "\n\n\t\t\t\t\t\t-> Your Choise is: ";

		cin >> choice;

		while (choice != 0 && choice != 1 && choice != 2 && choice != 3) {
			system("CLS");
			cout << "\n\n\n\t\t\t\t\t\tInvalid Input !!\n";
			this_thread::sleep_for(2000ms);
			cout << "\n\t\tEnter -> Your Choise :-> ";
			cin >> choice; cout << endl;
		}

		if (choice == 0) {
			Terminate = 0;
		}

		if (choice == 1) {
			adminSwitcher(main);
		}

		if (choice == 2) {
			display_clients(main);
		}

		if (choice == 3) {
			system("CLS");
			admin.checkLoggingIn();
			cout << "\n\n-----------------------\n\n";
			return 0;
		}
	} while (Terminate != 0);

	return 0;
}