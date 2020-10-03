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

int main(){
	std::string login;
	std::string password;
	bool exist;
	std::string option = start();
	//user wants to login
	if (option == "l"){
		Users currentUser;
		std::cout << "Please enter login" << std::endl;
		std::cin >> login;
		std::cout << "Please enter password: " << std::endl;
		std::cin >> password;
		currentUser.setUser(login, password);
		exist = currentUser.checkUser();
		if (exist == true){
			currentUser.loginUser();
		}
		else {
			std::cout << "The user you entered doesn't exist" << std::endl;
		}
	} 
	//user wants to register
	else if (option == "c"){
		Users currentUser;
		std::cout << "Please enter desired login" << std::endl;
		std::cin >> login;
		std::cout << "Please enter desired password" << std::endl;
		std::cin >> password;
		currentUser.setUser(login, password);
		exist = currentUser.checkUser();
		if (exist == false){
			currentUser.registerUser();
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
