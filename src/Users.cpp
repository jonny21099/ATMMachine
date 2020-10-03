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
	outfile.open("accounts.txt", std::ios::out | std::ios::in);
	if (outfile.is_open()){
		while (std::getline(outfile,user)){
			std::getline(outfile,pass);
			if (user == login && pass == password){
				return true;
			}
			else if (user == "test" && pass == "pass"){
				std::cout << "it worked" << std::endl;
			}
			else{
				std::cout << "didn't work as intendded" << std::endl;
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
}

void Users::loginUser(){
}