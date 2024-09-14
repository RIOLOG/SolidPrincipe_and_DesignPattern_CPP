/*The Prototype Design Pattern is a creational design pattern that allows 
you to create new objects by copying or cloning existing 
objects (prototypes), rather than creating new instances from scratch. 
This pattern is particularly useful when object creation is costly, 
or when you want to avoid subclassing in a hierarchy.*/


#include<iostream>
#include<unordered_map>
#include<string>
#include<memory>
using namespace std;

//BULLET of Base ProtoType:
class Bullet{

    protected:
        string _bulletName;
        float _speed;
        float _direction;

    public:
        Bullet() {}

        Bullet (string bulletName, float speed):
        _bulletName(bulletName), _speed(speed)
        {}


        virtual ~Bullet() {}
        virtual unique_ptr<Bullet> clone() = 0;


        void fire(float direction)
        {
            _direction = direction;
            cout<<"Name"<<":"<<_bulletName<<endl;
            cout<<"Speed"<<":"<<_speed<<endl;
            cout<<"Direction"<<":"<<_direction<<endl;
        }
};


//Simple Bullet is a Concrete Prototype:
class SimpleBullet: public Bullet{
    public:
    SimpleBullet(string bulletName, float speed): Bullet(bulletName, speed)
    {}

    unique_ptr<Bullet> clone() override{
        return make_unique<SimpleBullet>(*this);
    }
};


//GOod Bullet is the Concete Prototype:
class GoodBullet: public Bullet {
    public:
    GoodBullet(string bulletName, float speed): Bullet(bulletName, speed)
    {}

    unique_ptr <Bullet> clone() override {
        return make_unique<GoodBullet>(*this);
    }
};


//ENUM of bullet type:
enum BulletType {
    SIMPLE,
    GOOD
};


//Bullet Factory is the Clinet:
class BulletFactory {

    private:
        unordered_map<BulletType, unique_ptr<Bullet>, hash<int>> mapBullets;

    public:
        //PROTOTYPE OF PREDEFIEND BULLETS:
        BulletFactory()
        {
            mapBullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50);
            mapBullets[GOOD] = make_unique<GoodBullet>("Good Bullet", 75);
        }

        unique_ptr<Bullet> createBullet(BulletType BulletType)
        {
            return mapBullets[BulletType] -> clone();
        }
};


int main()
{
    // Object
    BulletFactory bulletFactory;

    // bullet of type simple:
    auto Bullet = bulletFactory.createBullet(SIMPLE);
    Bullet -> fire(80);

    //bullet of type good:
    Bullet = bulletFactory.createBullet(GOOD);
    Bullet -> fire(100);

    //Simple bullet again:
    Bullet = bulletFactory.createBullet(SIMPLE);
    Bullet -> fire(75);
}


// Name:Simple Bullet
// Speed:50
// Direction:80
// Name:Good Bullet
// Speed:75
// Direction:100
// Name:Simple Bullet
// Speed:50
// Direction:75
