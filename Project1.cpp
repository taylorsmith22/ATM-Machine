//-----------------------------------------------------------------------
//                        Smith State Bank Inc.
// Author: Taylor Smith
// 02/14/20
// CS 215 - Section 001
// Description: This program acts as an ATM and gives the user options to 
// deposit or withdraw money and displays their account.

#include <iomanip>;
#include <string>;
#include <iostream>;
using namespace std;

int main() {
	string accountNumber; // Creates a string to hold the user's account number
	double accountBalance; // Creates a double to hold the user's account balance
	string atmOption; // Creates string to hold the user's option
	double deposit; // Creates a double to hold the value of the user's deposit
	double withdrawal; // Creates a double to hold the value of the user's withdraw

	while (1 == 1) {
		cout << fixed << setprecision(2);

		cout << "___________________________" << endl; // Prints the Smith State Bank logo
		cout << "|                         |" << endl;
		cout << "|     Smith State Bank    |" << endl;
		cout << "|       CS215 - 001       |" << endl;
		cout << "|_________________________|" << endl;

		cout << "Enter account number:  "; // Asks the user to input their account number
		cin >> accountNumber; // accountNumber holds the value the user inputs for their account number
		if (accountNumber == "shutdown") {
			cout << "Shutting down...bye!" << endl; // Ends the program if the user inputs "shutdown" into the account number
			return 0; 
		}
		cout << "Enter account balance: "; // Asks the user to input their account balance
		cin >> accountBalance; // accountBalance holds the value the user inputs for their account balance

		cout << "B - Balance Inquiry" << endl; // Gives the user options to recieve a balance inquiry, deposit, or withdrawal from their account
		cout << "D - Deposit" << endl;
		cout << "W - Withdrawal" << endl;
		cout << "Choose an option: ";
		cin >> atmOption; // atmOption holds the option that the user chooses

		while ((atmOption != ("B")) && (atmOption != ("D") && atmOption != ("W"))) { // Prints an error message if the user does not choose one of the three options
			cout << "\"" << atmOption << "\""<<  "is an invalid option. Enter B, D or W." << endl; 
			cout << "Choose an option:  ";
			cin >> atmOption;
		}
		if (atmOption == "B") {
			cout << "___________________________" << endl; // Prints the Smith State Bank logo
			cout << "|                         |" << endl;
			cout << "|     Smith State Bank    |" << endl;
			cout << "|_________________________|" << endl;
			cout << "Account:    " << accountNumber << endl; // Prints the user's account number
			cout << "Balance:    $" << setw(8) << accountBalance << endl << endl; // Prints the user's account balance
		}
		else if (atmOption == "D") {
			cout << "Enter deposit amount: "; // Asks the userhow much money they want to deposit
			cin >> deposit; // deposit holds the value of the amount the user wants to deposit
			cout << "___________________________" << endl; // Prints the Smith State Bank logo
			cout << "|                         |" << endl;
			cout << "|     Smith State Bank    |" << endl;
			cout << "|_________________________|" << endl;
			cout << "Account:    " << accountNumber << endl; // Prints the user's account number
			cout << "Prev Bal:   $" << setw(8) << accountBalance << endl; // Prints the user's account balance
			cout << "Deposit:    $" << setw(8) << deposit << endl; // Prints how much the user is depositing into their account
			cout << "New Bal:    $" << setw(8) << accountBalance + deposit << endl << endl; // Calculates and prints the user's new balance
		}
		else if (atmOption == "W") {
			cout << "Enter withdrawal amount: "; // Asks the user to input how much money they to withdraw from their account
			cin >> withdrawal; // withdrawal holds the vale that the user inputs to withdraw from their account
			if (withdrawal > accountBalance) { // Prints an error statement if the user inputs a number that is greater than their account balance
				cout << "Insufficient Funds. Current Balance is $" << setw(8) << accountBalance << endl;
				while (withdrawal > accountBalance) { // Continues to print the error message as long as the withdrawal amount is greater than the account balance
					cout << "Enter withdrawal amount: ";
					cin >> withdrawal;
					cout << "Insufficient Funds. Current Balance is $" << setw(8) << accountBalance << endl;
				}
			}
			else {
				cout << "___________________________" << endl; // Prints the Smith State Bank logo
				cout << "|                         |" << endl;
				cout << "|     Smith State Bank    |" << endl;
				cout << "|_________________________|" << endl;
				cout << "Account:    " << accountNumber << endl; // Prints the user's account number
				cout << "Prev Bal:   $" << setw(8) << accountBalance << endl; // Prints the user's account balance
				cout << "Withdrawn:  $" << setw(8) << withdrawal << endl; // Prints the withdrawal amount
				cout << "New Bal:    $" << setw(8) << accountBalance - withdrawal << endl << endl; // Calculates and prints the user's new account balance
			}
		}
		
	}

	system("pause");
	return 0;
}