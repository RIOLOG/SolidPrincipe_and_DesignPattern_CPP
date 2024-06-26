#include<iostream>
using namespace std;

//OUR END PRODUCT:
class Plane {
    string _plane;
    string _body;
    string _engine;

    public:
        Plane(string planType): _plane(planType) {}

        void setEngine(string type)
        {
            _engine = type; 
        }
        void setBody(string body)
        {
            _body = body;
        }
        string getEngine()
        {
            return _engine;
        }

        string getBody()
        {
            return _body;
        }

        void show() {
            cout<<"PLANE TYPE"<<":"<<_plane<<endl;
            cout<<"Body Type"<<":"<<_body<<endl;
            cout<<"Engine Type"<<":"<<_engine<<endl;
        }
};


//Plane Builder Abstract class for creating Plane:
//ALl Builder should have atleast these methods:

class PlaneBuilder {
    protected:
        Plane *_plane;

    public:
        virtual void getPartsDone() = 0;
        virtual void buildBody() = 0;
        virtual void buildEngine() = 0;

        Plane *getPlane()
        {
            return _plane;
        }
};


//PlaneBuilder concrete class:
//type of plane to build:
class PropellerBuilder: public PlaneBuilder {
public:
    void getPartsDone(){
        _plane = new Plane("Propeller Builder");
    }
    void buildEngine(){
        _plane->setEngine("Propeller Engine");
    }
    void buildBody(){
        _plane->setBody("Propeller Body");
    }
};


//PlaneBuilder concrete class:
//type of plane to build:
class JetBuilder: public PlaneBuilder {
public:
    void getPartsDone(){
        _plane = new Plane("Jet Builder");
    }
    void buildEngine(){
        _plane->setEngine("Jet Engine");
    }
    void buildBody(){
        _plane->setBody("Jet Body");
    }
};


//MAIN METHOD OF ADAPTER DESGIN PATTERN:
// Defines steps and tells to the builder that build in given order.

class Director {
    PlaneBuilder *builder;

    public:
        Plane* createPlane(PlaneBuilder *builder)
        {
            builder -> getPartsDone();
            builder -> buildBody();
            builder -> buildEngine();
            return builder -> getPlane();
        }
};


//Main Function:
int main(){
    Director dir;

    JetBuilder jb;
    PropellerBuilder pb;

    Plane *jet = dir.createPlane(&jb);
    Plane *pro = dir.createPlane(&pb);

    jet -> show();

    cout<<"------------------------------"<<endl;

    pro -> show();

    //DeAllocating Memory:
    delete jet;
    delete pro;

    return 0;
}



