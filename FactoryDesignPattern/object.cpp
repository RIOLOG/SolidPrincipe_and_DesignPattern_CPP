#include < iosteam >
using namespace std;

class Toy {

protected:
    string name;
    float price;

public:
    virtual void prepareParts()  = 0;
	virtual void combineParts()  = 0;
	virtual void applyLabel()    = 0;
};

class Car: public Toy {
public:

    void prepareParts()
    {
        cout<<"Preparing Car Parts"<<endl;
    }

    void combineParts()
    {
        cout<<"Combining Car Parts"<<endl;
    }

    void applyLabel()
    {
        cout<<"Applying Car Label"<<endl;
    }
}

class Bike: public Toy {
public:

    void prepareParts()
    {
        cout<<"Preparing Bike Parts"<<endl;
    }

    void combineParts()
    {
        cout<<"Combining Bike Parts"<<endl;
    }

    void applyLabel()
    {
        cout<<"Applying Bike Label"<<endl;
    }
}

class Plane: public Toy {
public:

    void prepareParts()
    {
        cout<<"Preparing Plane Parts"<<endl;
    }

    void combineParts()
    {
        cout<<"Combining Plane Parts"<<endl;
    }

    void applyLabel()
    {
        cout<<"Applying Plane Label"<<endl;
    }
}

