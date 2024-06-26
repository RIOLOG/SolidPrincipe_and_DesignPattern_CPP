#include <iostream>
using namespace std;

#include "object.cpp"


class ToyFactory{
    static Toy* createToy(int type){

        Toy* toy = NULL;

        switch(type) {

            case 1: {
                toy = new Car;
                break;
            }

            case 2: {
                toy = new Bike;
                break;
            }

            case 3: {
                toy = new Plane;
                break;
            }

            default:{
                cout << "Invalid toy or type re - enter type" << endl;
                return NULL;
            }
        }

        toy -> prepareParts();
        toy -> combineParts();
        toy -> applyLabel();

        return toy;
    }
}