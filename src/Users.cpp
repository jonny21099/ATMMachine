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

int Users::loginUser(){
	//login and retrieve atm information
	std::ifstream readfile;
	readfile.open("accounts.txt");
	std::cout << "\nYou have successfully logged in" << std::endl;
	readfile.close();
	return std::stof(amount);
}

void Users::saveChanges(float amount){
	std::ofstream outfile;
	std::ifstream infile;
	std::string user;
	std::string pass;
	std::string temp;
	std::string newamount;
	newamount = std::to_string(amount);
	infile.open("accounts.txt");
	outfile.open("temp.txt", std::ios_base::app);
	while (std::getline(infile, user)){
		std::getline(infile, pass);
		std::getline(infile, temp);
		//if username and password found, return true;
		outfile << user << '\n';
		outfile << pass << '\n';
		if (user == login && pass == password){
			outfile << amount << '\n';
		}
		else {
			outfile << temp << '\n';
		}
	}
	infile.close();
	outfile.close();
	remove("accounts.txt");
	rename("temp.txt","accounts.txt");
}
