#include <string>

class Users{
public:
	Users();
	void setUser(std::string a, std::string b);
	bool checkUser();
	void registerUser();
	void loginUser();

private:
	std::string login;
	std::string password;
};