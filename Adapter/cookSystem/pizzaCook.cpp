#include<iostream>
using namespace std;

class cookSystem{
    public:
        virtual void cook() = 0;
        virtual void serve() = 0;
};

class pizzaSystem{
    public:
        void bake() {
            cout<<"Baking Pizza"<<endl;
        }
        void serverPizza() {
            cout<<"Serving Pizza"<<endl;
        }

};

class rollSystem{
    public:
        void roll() {
            cout<<"Rolling roll"<<endl;
        }
        void serverRoll() {
            cout<<"Serving Roll"<<endl;
        }
};

class currySystem{
    public:
        void cookCurry() {
            cout<<"Cooking the curry"<<endl;
        }
        void serverCurry() {
            cout<<"Serving the curry"<<endl;
        }
};


class pizzaAdapter:public cookSystem {
    private:
        pizzaSystem *pizza;
    public:
        pizzaAdapter(pizzaSystem *p):pizza(p){

        }

        void cook() {
            pizza->bake();
        }

        void serve() {
            pizza->serverPizza();
        }
};

class rollAdapter:public cookSystem {
    private:
        rollSystem *roll;
    public:
        rollAdapter(rollSystem *r):roll(r){

        }

        void cook() {
            roll->roll();
        }

        void serve() {
            roll->serverRoll();
        }
};

class curryAdapter:public cookSystem {
    private:
        currySystem *curry;
    public:
        curryAdapter(currySystem *c):curry(c){

        }

        void cook() {
            curry->cookCurry();
        }

        void serve() {
            curry->serverCurry();
        }
};


int main() {
    pizzaSystem *pizza;
    rollSystem *roll;
    currySystem *curry;

    cookSystem *p1 = new pizzaAdapter(pizza);
    cookSystem *r1 = new rollAdapter(roll);
    cookSystem *c1 = new curryAdapter(curry);

    p1->cook();
    p1->serve();

    r1->cook();
    r1->serve();

    c1->cook();
    c1->serve();

    return 0;
}