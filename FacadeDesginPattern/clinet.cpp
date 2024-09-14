/*The Facade Design Pattern is a structural design pattern that 
provides a simplified interface to a complex subsystem, making it easier 
for clients to interact with it. The idea is to hide the complexities of 
the system by providing a higher-level interface, or "facade," that 
interacts with multiple classes behind the scenes.*/

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
