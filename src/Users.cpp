#include "Users.h"
#include <string>
#include <iostream>
#include <fstream>

Users::Users(){}
void Users::setUser(std::string a, std::string b){
	login = a;
	password = b;
}

//bug with not actually creating the file if it exists
bool Users::checkUser(){
	std::string user;
	std::string pass;
	std::fstream outfile;
	outfile.open("accounts.txt", std::fstream::in|std::fstream::out);
	if (outfile.is_open()){
		while (std::getline(outfile,user)){
			std::getline(outfile,pass);
			if (user == login && pass == password){
				return true;
			}	
		}
		outfile.close();
		return false;
	}
	else{
		outfile << "testing\n";
		outfile.close();
		return false;
	}
}

void Users::registerUser(){
	std::ofstream editfile;
	editfile.open("accounts.txt", std::ios_base::app);
	editfile << login << '\n';
	editfile << password << '\n';
}

void Users::loginUser(){
	//login and retrieve atm information
}