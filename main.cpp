/* Imports */

#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/* Jump to main function */

/* params: loginMode (register or login */
void login(const char loginMode)
{
	/* Switch for loginMode = 1 or loginMode = 2 */
	switch(loginMode) {
		/* loginMode = 1? */
		case '1':
			{
				/* databases in append mode */
				std::ofstream nameDB("names.txt", std::ios_base::app);
				std::ofstream passDB("pass.txt", std::ios_base::app);
				
				/* username & password */
				string username;
				string password;

				/* Add account */
				cout << "Register" << endl;

				cout << "Enter a username: " << endl;
				cin >> username;	
				cout << "Enter a password: " << endl;
				cin >> password;	

				/* Write to DBs */
				nameDB << username << endl;
				passDB << password << endl;
			}
			break;
			
		/* loginMode = 2? */
		case '2':
			{
				/* DBs */
				std::ifstream nameDB("names.txt");
				std::ifstream passDB("pass.txt");
				
				/* user input username & password */
				string uiUsername;
				string uiPassword;
				
				/* field input username & password */
				string fUsername;
				string fPassword;
				
				/* bools for usernameCorrect and passwordCorrect */
				bool usernameCorrect, passwordCorrect;

				/* Login */
				cout << "Login" << endl;

				cout << "Enter your username: " << endl;
				cin >> uiUsername;
				cout << "Enter your password: " << endl;
				cin >> uiPassword;

				/* Loop over usernames and set username to fUsername */
				while(std::getline(nameDB, fUsername))
				{
					/* Sets username to correct/incorrect */
					if(uiUsername == fUsername) 
					{
						usernameCorrect = true;	
						break;
					} else
					{
						usernameCorrect = false;	
					}
				}

				/* Same here */
				while(std::getline(passDB, fPassword))
				{
					if(uiPassword == fPassword)
					{
						passwordCorrect = true;	
						break;
					}
					else {
						passwordCorrect = false;	
					}
				}

				/* 
				If username and password are correct, say hi to user,
				else, no.
				*/
				if(usernameCorrect && passwordCorrect)
				{
					cout << "Hello, " << uiUsername << "!" << endl;	
				} else 
				{
					cout << "I couldn't find that account." << endl;
				}
			}
			break;
	}
}

int main()
{
	/* New variable mode */
	char mode; 
	
	/* Introduction */
	cout << "Hi! Welcome to my login system!" << endl;
	cout << "Enter a mode: " << endl;
	cout << "1 = Register" << endl << "2 = Login" << endl;
	
	/* Set mode to user input */
	cin >> mode;

	/* Calls login function */
	login(mode);
	
	/* Jump to login function up */
	
	return 0;
}
