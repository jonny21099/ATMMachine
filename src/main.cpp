#include "Users.h"
#include <string>
#include <iostream>
#include <fstream>

std::string start(){
	std::string option;
	//Display welcome message
	std::cout << "Hello! Welcome to Mr. Martin's ATM Machine!" << std::endl;
	std::cout << "\nPlease select an option from the menu below:" << std::endl; 
	std::cout << "\nl -> Login\nc -> Create New Account\nq -> Quit\n" << std::endl;

	//Remember user input
	std::cin >> option;
	return option;
}

//deposit money
float deposit(float &amount){
	float depositAmount;
	std::cout << "Amount of deposit: $";
	std::cin >> depositAmount;
	//if entered a negative value
	if (depositAmount < 0){
		std::cout << "That is not possible!" << std::endl;
		return amount;
	}
	//otherwise add it to amount
	else {
		amount = amount + depositAmount;
		return amount;
	}
}

//withdraw money
float withdraw(float &amount){
	float withdrawAmount;
	std::cout << "Amount to withdraw: $";
	std::cin >> withdrawAmount;
	//if entered a negative value
	if (withdrawAmount < 0){
		std::cout << "That is not possible!" << std::endl;
		return amount;
	}
	//otherwise subtract it from amount
	else{
		amount = amount - withdrawAmount;
		return amount;
	}
}

//request balance
void request(float &amount){
	std::cout << "Your balance is $" << amount << std::endl; 
}

//user interaction menu
void menu(){
	std::cout << "d -> Deposit Money" << std::endl;
	std::cout << "w -> Withdraw Money" << std::endl;
	std::cout << "r -> Request Balance" << std::endl;
	std::cout << "q -> Quit" << std::endl;
}

int main(){
	std::string login;
	std::string password;
	std::string bankingOption;
	bool exist;
	bool execute = true;
	float amount;
	//create Users object
	Users currentUser;
	while(execute){
		std::string option = start();
		//user wants to login
		if (option == "l"){
			std::cout << "Please enter login" << std::endl;
			std::cin >> login;
			std::cout << "Please enter password: " << std::endl;
			std::cin >> password;
			currentUser.setUser(login, password);
			exist = currentUser.checkUser();
			if (exist == true){
				amount = currentUser.loginUser();
				break;
			}
			else {
				std::cout << "The user you entered doesn't exist" << std::endl;
			}
		} 
		//user wants to register
		else if (option == "c"){
			std::cout << "Please enter desired login" << std::endl;
			std::cin >> login;
			std::cout << "Please enter desired password" << std::endl;
			std::cin >> password;
			currentUser.setUser(login, password);
			exist = currentUser.checkUser();
			if (exist == false){
				currentUser.registerUser();
				std::cout << "Registered\n" << std::endl;
				return 0;
			}
			else {
				std::cout << "This account is registered" << std::endl;	
			}
		} 
		//user wants to quit
		else if (option == "q"){
			return 0;
		} 
		//invalid input
		else {
			std::cout << "Please try again, and enter a valid input!" << std::endl;
			main();
		}
	}

	std::cout << "Welcome to your banking page!" << '\n' << std::endl;
	std::cout << "What would you like to do?" << std::endl;

	while (execute){
		std::cout << '\n';
		menu();
		std::cin >> bankingOption;
		//deposit
		if (bankingOption == "d"){
			deposit(amount);
		}
		//withdraw
		else if (bankingOption == "w"){
			withdraw(amount);
		}
		//request balance
		else if (bankingOption == "r"){
			request(amount);
		}
		//quit
		else if (bankingOption == "q"){
			std::cout << "Thanks for using ATM, come again!" << std::endl;
			break;
		}
		//invalid input
		else{
			std::cout << "Please enter a valid input" << std::endl;
		}
	}
	//save changes to txt
	currentUser.saveChanges(amount);
}
