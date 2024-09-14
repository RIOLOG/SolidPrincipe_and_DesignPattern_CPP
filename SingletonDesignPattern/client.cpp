#include <bits/stdc++.h>
using namespace std;

class Singleton {
    static Singleton* _instance;  // Static instance variable
    Singleton() {}  // Private constructor

public:
    // Static method to get the instance of the class
    static Singleton* getInstance() {
        if (_instance == nullptr) {
            _instance = new Singleton();
        }
        return _instance;
    }
};

// Initialize the static member
Singleton* Singleton::_instance = nullptr;

void makeInstance() {
    Singleton* single = Singleton::getInstance();
    cout << "Address of Singleton object in makeInstance: " << single << endl;
}

int main() {
    Singleton* mingle = Singleton::getInstance();
    cout << "Address of Singleton object in main: " << mingle << endl;

    makeInstance();  // This will show the same address

    return 0;
}


//we have created two instance of same class
//but we have same memory assigned to both.
//that mean same object is created for multiple class;
