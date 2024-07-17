// The Decorator Pattern is a structural design pattern in 
// software engineering that enables the dynamic addition 
// of new behaviors or responsibilities to individual objects 
// without altering their underlying class structure.



#include <iostream>
#include <string>

using namespace std;

//base class:
class IceCream {
    public:
        virtual string getDescription() const = 0;
        virtual double cost() const = 0;
};


// Concrete Component - the basic ice cream class.
class VanillaIceCream : public IceCream {
    public:
        string getDescription() const override {
            return "Vanilla Ice Cream";
        }

        double cost () const override { 
            return 160.00 ;
        }
};


// Decorator - abstract class that extends IceCream:
class IceCreamDecorator: public IceCream {
    protected:
        IceCream* iceCream;

    public:
        IceCreamDecorator (IceCream* ic): iceCream(ic)   {}

        string getDescription() const override {
            return iceCream -> getDescription();
        }

        double cost () const override {
            return iceCream -> cost();
        }
};


// Concrete Decorator - adds chocolate topping.
class ChocolateDecorator: public IceCreamDecorator {
    public:
        ChocolateDecorator(IceCream* ic): IceCreamDecorator(ic) { }

        string getDescription() const override {
            return iceCream -> getDescription() + "with chocolate";
        } 

        double cost() const override {
            return iceCream -> cost() + 100.00;
        }
};


int main() 
{
    //Creating a Vanilla Ice Cream:
    IceCream* vanillaIceCream = new VanillaIceCream();
    cout<<"Order: "<<vanillaIceCream->getDescription()<<", CostL Rs. "<<vanillaIceCream -> cost()<<endl;

     // Wrap it with ChocolateDecorator
    IceCream* chocolateIceCream = new ChocolateDecorator(vanillaIceCream);
    cout << "Order: " << chocolateIceCream->getDescription()<< ", Cost: Rs." << chocolateIceCream->cost() << endl;


    delete vanillaIceCream;
    delete chocolateIceCream;
    return 0;
}