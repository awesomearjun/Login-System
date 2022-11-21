#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void login(const char loginMode) {
	switch(loginMode) {
		case '1':
			{
				std::ofstream nameDB("names.txt", std::ios_base::app);
				std::ofstream passDB("pass.txt", std::ios_base::app);
				string username;
				string password;

				cout << "Register" << endl;

				cout << "Enter a username: " << endl;
				cin >> username;	
				cout << "Enter a password: " << endl;
				cin >> password;	

				nameDB << username << endl;
				passDB << password << endl;
			}
			break;	
		case '2':
			{
				std::ifstream nameDB("names.txt");
				std::ifstream passDB("pass.txt");
				string uiUsername;
				string uiPassword;
				string fUsername;
				string fPassword;
				bool usernameCorrect, passwordCorrect;

				cout << "Login" << endl;

				cout << "Enter your username: " << endl;
				cin >> uiUsername;
				cout << "Enter your password: " << endl;
				cin >> uiPassword;

				while(std::getline(nameDB, fUsername)) {
					if(uiUsername == fUsername) {
						usernameCorrect = true;	
						break;
					} else {
						usernameCorrect = false;	
					}
				}

				
				while(std::getline(passDB, fPassword)) {
					if(uiPassword == fPassword) {
						passwordCorrect = true;	
						break;
					} else {
						passwordCorrect = false;	
					}
				}

				if(usernameCorrect && passwordCorrect) {
					cout << "Hello, " << uiUsername << "!" << endl;	
				} else  {
					cout << "I couldn't find that account." << endl;
				}
			}
			break;
	}
}

int main() {
	char mode; 
	cout << "Hi! Welcome to my login system!" << endl;
	cout << "Enter a mode: " << endl;
	cout << "1 = Register" << endl << "2 = Login" << endl;
	cin >> mode;

	login(mode);
	
	return 0;
}
