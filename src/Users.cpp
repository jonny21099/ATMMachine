#include "Users.h"
#include <string>
#include <iostream>
#include <fstream>

Users::Users(){}
//set user with the provided login and password
void Users::setUser(std::string a, std::string b){
	login = a;
	password = b;
}

//check if user exists in the txt file
bool Users::checkUser(){
	std::string user;
	std::string pass;
	std::fstream outfile;
	std::string temp;
	//open the file if exists, else creates one
	outfile.open("accounts.txt", std::fstream::in|std::fstream::out);
	if (outfile.is_open()){
		while (std::getline(outfile, user)){
			std::getline(outfile, pass);
			//if username and password found, return true;
			if (user == login && pass == password){
				std::getline(outfile, amount);
				return true;
			}
			std::getline(outfile, temp);	
		}
		outfile.close();
		return false;
	}
	return false;
}

//opens the text file for writing and add the login password and base amount to text
void Users::registerUser(){
	std::ofstream editfile;
	editfile.open("accounts.txt", std::ios_base::app);
	editfile << login << '\n';
	editfile << password << '\n';
	editfile << "0" << '\n';
	editfile.close();
}

float Users::loginUser(){
	//return amount in user account
	std::cout << "\nYou have successfully logged in" << std::endl;
	return std::stof(amount);
}

void Users::saveChanges(float amount){
	std::ofstream outfile;
	std::ifstream infile;
	std::string user;
	std::string pass;
	std::string temp;
	std::string newamount;
	//convert amount to string type for text
	newamount = std::to_string(amount);
	//copy all content into temp except new value
	infile.open("accounts.txt");
	outfile.open("temp.txt", std::ios_base::app);
	//get username password and amount
	while (std::getline(infile, user)){
		std::getline(infile, pass);
		std::getline(infile, temp);
		//copy to temp username and password
		outfile << user << '\n';
		outfile << pass << '\n';
		//if the login and password is the same as user change amount
		if (user == login && pass == password){
			outfile << amount << '\n';
		}
		//otherwise amount is same
		else {
			outfile << temp << '\n';
		}
	}
	infile.close();
	outfile.close();
	//remove the old file and rename new file 
	remove("accounts.txt");
	rename("temp.txt","accounts.txt");
}
