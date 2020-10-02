#include "users.h"
#include <string>
#include <iostream>
#include <fstream>

Users::Users(std::string a, std::string b){
	setUser(a, b);
}

Users::setUser(std::string a, std::string b){
	login = a;
	password = b;
}

Users::registerUser(){

}

Users::loginUser(){
	
}