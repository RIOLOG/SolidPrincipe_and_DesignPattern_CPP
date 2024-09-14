/*The Adapter Design Pattern is a structural design pattern that allows 
objects with incompatible interfaces to work together. 
The Adapter pattern acts as a bridge between two objects or systems by 
converting one interface into another, making it possible for systems 
or classes that otherwise wouldn't be able to interact to communicate 
effectively. */

#include<iostream>
#include<memory>
using namespace std;

//INTERFACE / CLASS 1:
class IndianSocket{
    public:
    virtual void indiancharge() = 0;
};


//INTERFACE / CLASS 2:
class USASocket {
    public:
    void usacharge()
    {
        cout<<"USA PLUG IS CHARGING"<<endl;
    }
}


//MAKING ADAPTER FOR MAKING both INTERFACE/CLASS COMPATIBLE:-
class SocketAdapter: public IndianSocket, public USASocket{
    public:
    void indiancharge() {
        usacharge();
    }
};


// MAIN FUNCTION FOR CLIENT:
int main() {

    // This line creates a smart pointer (unique_ptr) to a new SocketAdapter object.
    // The unique_ptr is used to manage the lifetime of the SocketAdapter instance automatically,
    // ensuring that it is properly deleted when no longer needed.

    unique_ptr<IndianSocket> socket = make_unique<SocketAdapter>();
    socket->indiancharge();
    return 0;
}
