//The Interface Segregation Principle (ISP) states that clients should not be forced to depend on interfaces they do not use. In other words, it's better to have many small, specific interfaces rather than a single large, general-purpose interface.

#include<iostream>
using namespace std;


// Specific interfaces with Specific Functionality:
class IPrinter {
    public:
        virtual void printDocument(const string &doc) = 0;
};

class IScanner {
    public:
        virtual void scanDocument(const string &doc) = 0;
};


//Derived class Printer:
class Printer: public IPrinter {
    public:
        void printDocument(const string &doc) override {
            cout << "Printing document: " << doc << endl;
        }
};

//Derived class Scanner:
class Scanner: public IScanner {
    public:
        void scanDocument(const string &doc) override {
            cout << "Scanner document: " << doc << endl;
        }
};


// Derived class: MultiFunctionPrinter that implements multiple interfaces
class MultiFunctionPrinter : public IPrinter, public IScanner{
    public:
        void printDocument(const string &doc) override {
            cout << "Printing document: " << doc << endl;
        }
    
        void scanDocument(const string &doc) override {
            cout << "Scanning document: " << doc << endl;
        }
};

int main()
{
    Printer p;
    Scanner s;
    MultiFunctionPrinter m;
    
    p.printDocument("Ankit.pdf");
    s.scanDocument("Rishu.jpg");
    
    m.printDocument("Ankit.pdf");
    m.scanDocument("Rishu.jpg");
}