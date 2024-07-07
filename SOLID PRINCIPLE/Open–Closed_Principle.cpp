//Open–Closed Principle (OCP) -> states that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. 

//In this initial implementation, the Discount class has methods for calculating discounts for regular and VIP customers. To add a new type of discount, we would need to modify this class.

//Refactored Implementation (Follows OCP):

#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

//this the base/main class for customer discounts:
class CustomerDiscount {
    public:
        virtual double calculateDiscount(double price) const = 0;
};


// Derived class for regular customer discount
class RegularCustomer: public CustomerDiscount{
    public:
         double calculateDiscount(double price)  const override {
             return price * 0.2;
         }
};

// Derived class for VIP customer discount
class VIPCustomer: public CustomerDiscount{
    public:
         double calculateDiscount(double price)  const override {
             return price * 0.3;
         }
};

//function to calculate the discount using a type of customer 
double getDiscount(const CustomerDiscount& customerType, double price){
    return customerType.calculateDiscount(price);
}

int main()
{
    double price = 100.0;
    
    RegularCustomer rc;
    VIPCustomer vipc;
    
    cout<<"Discount for Regular Customer"<<getDiscount(rc, price)<<endl;
    
    cout<<"Discount for VIP Customer"<<getDiscount(vipc, price)<<endl;
    
    return 0;
}



