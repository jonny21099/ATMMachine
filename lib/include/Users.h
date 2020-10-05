#include <string>

class Users{
public:
	Users();
	void setUser(std::string a, std::string b);
	bool checkUser();
	void registerUser();
	int loginUser();
	void saveChanges(float amount);

private:
	std::string login;
	std::string password;
	std::string amount;
};