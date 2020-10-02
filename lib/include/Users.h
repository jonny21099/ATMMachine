#include <string>
class Users{
public:
	Users(std::string a, std::string b);
	void setUser(std::string a, str::string b);
	void registerUser();
	void loginUser();
	
private:
	std::string login;
	std::string password;
};