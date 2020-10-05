#include <iostream>
#include <string>
#include "../lib/include/Users.h"

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
	if (depositAmount < 0){
		std::cout << "That is not possible!" << std::endl;
		return amount;
	}
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
	if (withdrawAmount < 0){
		std::cout << "That is not possible!" << std::endl;
		return amount;
	}
	else{
		amount = amount - withdrawAmount;
		return amount;
	}

}

//request balance
void request(float &amount){
	std::cout << "Your balance is $" << amount << std::endl; 
}

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
		if (bankingOption == "d"){
			deposit(amount);
		}
		else if (bankingOption == "w"){
			withdraw(amount);
		}
		else if (bankingOption == "r"){
			request(amount);
		}
		else if (bankingOption == "q"){
			std::cout << "Thanks for using ATM, come again!" << std::endl;
			return 0;
		}
		else{
			std::cout << "Please enter a valid input" << std::endl;
		}
	}
	currentUser.saveChanges(amount);
}
