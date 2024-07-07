//The Single Responsibility Principle (SRP) -> a class should have only one reason to change.

#include<iostream>
#include<string>

using namespace std;

//class for handling for login functionality:
class LoginService {
    public:
        void login(string username, string password)
        {
            cout<<"User Logged in: "<<username<<" "<<password<<endl;
        }
};

//class for handling for Register functionality:
class RegisterService {
    public:
        void registerUser(string username, string password)
        {
              cout<<"Register Logged in: "<<username<<" "<<password<<endl;
        }
};

// Main Function:
int main() {
    LoginService loginservice;
    RegisterService registerservice;
    
    registerservice.registerUser("Ankit", "123");
    loginservice.login("Ankit", "123");
    
    return 0;
}