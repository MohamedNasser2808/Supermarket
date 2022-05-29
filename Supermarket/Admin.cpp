#include "Admin.h"

using namespace std;

Admin::Admin(string mail, int pass) {
	email = mail;
	password = pass;
	isLogged = false;
}

bool Admin::checkLogManager(string mail, int pass) {
	if (mail == email && pass == password) {
		return true;
	}
	else if (mail == email || pass == password) {
		return false;
	}
	else {
		return false;
	}
}

void Admin::creation(int ID, string IDStr, string as) {
	system("CLS");

	cin.ignore();
	cout << "\n\n\t\t\tEnter Your Name ->: "; getline(cin, cName);
	cout << "\n\t\t\tEnter Your Age ->: "; cin >> cAge;
	cout << "\n\t\t\tEnter Your Gender ->: "; cin >> cGender;
	cout << "\n\t\t\tEnter Your Phone Number ->: "; cin >> cNumber;
	cout << "\n\t\t\tEnter Your Email ->: "; cin >> cMail;
	cout << "\n\t\t\tEnter Your Password ->: "; cin >> cPass;
	cout << "\n\t\t\t\t--------------------------------------------------------------\n";

	ofstream cFiles;
	cFiles.open("C:/Supermarket_Files/Admin/" + IDStr);
	cFiles << "Logged In As : " << as << endl
		<< "Name :->  " << cName << endl
		<< "Age :->  " << cAge << endl
		<< "Gender :->:  " << cGender << endl
		<< "Phone Number :->  " << cNumber << endl
		<< "Email :->  " << cMail << endl
		<< "Password :->  " << cPass << endl;
	cFiles.close();

	ofstream save_clients_ID;
	save_clients_ID.open("C:/Supermarket_Files/Admin/Clients_Data.txt", ios::app);
	save_clients_ID << "\t\t\t\tLogged As [ " << as << " ] =>>  ID [ " << ID << " ] =>>  Pasword [ " << cPass << " ]" << endl;
	save_clients_ID.close();

	this_thread::sleep_for(1000ms);
	cout << "\n\t\t\t\t\t\tSUCCESSFULLY CREATE NEW " << as << endl;
	cout << "\n\t\t\t\t\t\tRemember :-> Your ID Is :> [ " << ID << " ]\n";
	cout << "\n\t\t\t\t--------------------------------------------------------------\n";
}

void Admin::createClients() {
	int counterIDs = 0, arrNums[2], ID;

	srand(time(NULL)); /// Initialize The Random Number Generator

	for (int i = 0; i < 2; i++) {
		arrNums[i] = rand() % 100 + 1; /// Generate ID In Only (2) Number
	}
	for (int j = 0; j < 2; j++) {
		ID = arrNums[j];
	}

	string IDStr = to_string(ID);
	IDStr += ".dat";

	cout << "\n\n\n\n\t\t\tWhat Do You Want To Sign Up As [ Cashier, Seller, Supplier, Customer ]\n\n\n\t\t\t\t\t\tYour Choice :-> ";
	cin >> choiceLog;

	if (choiceLog == "Cashier" || choiceLog == "cashier") {
		this->creation(ID, IDStr, "Cashier");
	}
	if (choiceLog == "Seller" || choiceLog == "seller") {
		this->creation(ID, IDStr, "Seller");
	}
	if (choiceLog == "Supplier" || choiceLog == "supplier") {
		this->creation(ID, IDStr, "Supplier");
	}
	if (choiceLog == "Customer" || choiceLog == "customer") {
		this->creation(ID, IDStr, "Customer");
	}
}

void Admin::Display_Clients() {
	ifstream insert_clients("C:/Supermarket_Files/Admin/Clients_Data.txt");
	char data;
	while (insert_clients) {
		data = insert_clients.get();
		cout << data;
	}
}

void Admin::checkLoggingIn() {
	//cout << "\n\n\n\t\tWhat Do You Want To Login As [ Cashier, Seller, Supplier, Customer ]\n\n\t\t\tYour Choice :-> ";
	//cin >> choiceLog;

	//if (choiceLog == "Cashier" || choiceLog == "cashier") {

	//}
	//if (choiceLog == "Seller" || choiceLog == "seller") {

	//}
	//if (choiceLog == "Supplier" || choiceLog == "supplier") {

	//}
	//if (choiceLog == "Customer" || choiceLog == "customer") {

	//}

	int ID;
	string PassID;

	cout << "\n\nEnter the ID :-> "; cin >> ID;

	string IDPass = to_string(ID);
	IDPass += ".dat";


	ifstream file("C:/Supermarket_Files/Admin/" + IDPass), getPass("C:/Supermarket_Files/Admin/" + IDPass);
	
	if (file.is_open()) {
		cout << "ID Entered Successfully Exists";

		/*cout << "\n\nEnter Password of ID [ " << ID << " ] :-> "; cin >> PassID;*/

		string word, t, q, filename;

		file.open(filename.c_str());

		while (getPass >> word) {
			cout << word << endl;
		}

	}
	else {
		cout << "Error, ID Is Not Present\n";
	}

	file.close();
}

Admin::~Admin() {
}
