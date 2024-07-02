#include<iostream>
using namespace std;

//SUBSYSTEM -> 1:
class Engine {
    public:

        void Start ()
        {
            cout<<"Engine Started"<<endl;
        }

        void Stop ()
        {
            cout<<"Engine Stop"<<endl;
        }
};

//SUBSYSTEM -> 2:
class Lights {
    public:

        void TurnOn() 
        {
            cout<<"Light on"<<endl;
        }

        void TurnOff()
        {
            cout<<"Light off"<<endl;
        }
};


//FACADE
//Now Facade will call the subsystem 1 & 2:

class Car {
    private:
        Engine engine;
        Lights lights;

    public:
        void StartCar ()
        {
            engine.Start();
            lights.TurnOn();
            cout<<"Car Ready to Drive"<<endl;
        }

        void StopCar ()
        {
            engine.Stop();
            lights.TurnOff();
            cout<<"Car has Stopped"<<endl;
        }
};

int main()
{
    //using the FACADE to start and stop the car:
    Car car;

    car.StartCar();
    car.StopCar();

    return 0;
}