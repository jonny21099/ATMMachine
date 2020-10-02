#include <iostream>
#include <string>

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
	
	std::string option = start();
	Users currentUser();
	//Check
	if (option == 'l'){

	} else if (option == 'c'){

	} else if (option == 'q'){
		return 0;
	} else {
		std::cout << "Please try again, and enter a valid input!" << std::endl;
		main();
	}
}