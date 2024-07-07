//The Dependency Inversion Principle (DIP) states that high-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces). 


#include<iostream>
#include<string>
using namespace std;

//Abstraction:
class IPaymentProcessor {
    public:
        virtual void processPayment(const string &amount) = 0; 
        virtual ~IPaymentProcessor() = default; 
};

//Low Level Module:
class PayPalProcessor: public IPaymentProcessor {
    public:
        void processPayment(const string &amount) override {
             cout << "Processing payment through PayPal: " << amount << endl;
        }
};

// Another Low-level module
class StripeProcessor : public IPaymentProcessor {
public:
    void processPayment(const string &amount) override {
        cout << "Processing payment through Stripe: " << amount << endl;
    }
};


//High level module:
// => High level module/class shoud depend on Abstract class(interface) not on a specific class(low level module):

class ShoppingCart {
    IPaymentProcessor &paymentProcessor;  // Dependency on abstraction
    
    public:
        ShoppingCart(IPaymentProcessor &processor) : paymentProcessor(processor) {}
        
        void checkout(const string &amount) {
        paymentProcessor.processPayment(amount);
    }
};

int main() 
{
    PayPalProcessor paypal;
    StripeProcessor stripe;

    ShoppingCart cart1(paypal); // Injecting PayPalProcessor dependency
    cart1.checkout("$100");

    ShoppingCart cart2(stripe); // Injecting StripeProcessor dependency
    cart2.checkout("$150");

    return 0;
}

