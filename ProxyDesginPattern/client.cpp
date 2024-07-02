#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

//INTERFACE CLASS
class Database {
    public:
        virtual void query(const string& sql)   const = 0;
};

//Real Database for execution
class RealDatabase: public Database {
    public:
        void query(const string& sql) const override {
            cout<<"Executing Query: "<<sql<<endl;
        }
};

//Proxy Database for validation:
//user thinks it is a real database:

class DatabaseProxy : public Database {

    private:
        vector<string> allowedUsers;
        shared_ptr<RealDatabase> realDatabase;

    public:
    DatabaseProxy(const vector<string>& allowedUsers) : 
    allowedUsers(allowedUsers), realDatabase(make_shared<RealDatabase>()) {}


    void query(const string& sql)  const override {
        if (isUserAllowedToQuery()) {
            realDatabase -> query(sql);
        }
        else{
            cout<<"Access Denied"<<endl;
        }
    }

    private:
    bool isUserAllowedToQuery() const {
        return true;
    }
};

int main() {
    vector<string> allowedUsers = {"admin"};
    DatabaseProxy databaseProxy(allowedUsers);

    databaseProxy.query("select * from employee()");
    databaseProxy.query("Insert into employee VALUES ('John', 'Doe', '30')");

    return 0;
}
    