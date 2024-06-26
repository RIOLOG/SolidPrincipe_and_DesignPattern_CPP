#include<iostream>
#include<string>

using namespace std;

class GameSetting {
    static GameSetting* _instance;
    int _health;
    int _moves;

    GameSetting(): _health(70), _moves(2) {}


    public:

        static GameSetting* getInstance(){
            if (_instance == NULL){
                _instance = new GameSetting();
            }
            return _instance;
        }

        void setHealth(int health)
        {
            _health = health;
        }

        int getHealth()
        {
            return _health;
        }

        void display()
        {
            cout<<"Health is"<<":"<<_health<<endl;
            cout<<"Moves is"<<":"<<_moves<<endl;
        }
};

//defining it outside the class because to assign it memory
//because it is static object:
 GameSetting* GameSetting:: _instance = NULL;


//again making the instance(object) of class:
void makeInstance()
{
    GameSetting* setting = GameSetting::getInstance();
    setting -> display();

    // cout<<"object memory for 2nd instance "<<setting<<endl;  -> 0x173eeb0
}


int main()
{
    GameSetting* setting = GameSetting::getInstance();
    setting -> display();

    // cout<<"object memory for 1st instance "<<setting<<endl;  -> 0x173eeb0

    setting -> setHealth(80);

    makeInstance();
    return 0;
}

//we have created two instance of same class
//but we have same memory assigned to both.
//that mean same object is created for multiple class;