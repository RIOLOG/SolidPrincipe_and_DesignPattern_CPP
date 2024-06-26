#include<iostream>
using namespace std;

#include "ToyFactory.cpp"

int main() {
    
    //CLIENT CODE STARTS:
    int type;

    while(1){
        cout << endl << "Enter type or Zero for exit" << endl;
        cin >> type;

        if (!type){
            break;
        }

        //creating a object as per clinet entering the type:
        Toy *obj = ToyFactory::createToy(type);

        if (obj){
            v -> showProduct();
            delete v;
        }
    }

    cout << "Exit..." << endl;

    return 0;
}
