#include<iostream>
using namespace std;

class Duck {
    public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallarDuck: public Duck {
    public:
        void quack() {
            cout<<"Quack"<<endl;
        }
        void fly() {
            cout<<"Duck I'm FLying"<<endl;
        }
};

class Turkey{
    public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey: public Turkey {
    public:
        void gobble() {
            cout<<"Gobble"<<endl;
        }
        void fly() {
            cout<<"Turkey Flying"<<endl;
        }
};

class TurkeyAdapter: public Duck {
    private:
        Turkey *turkey;
    public:
        TurkeyAdapter(Turkey *t):turkey(t) {
        }

        void quack() {
            turkey->gobble();
        }
        void fly() {
            turkey->fly();
        }
};


int main() {
    Duck *d = new MallarDuck();
    d->quack();
    d->fly();

    Turkey *t = new WildTurkey();
    //t->quack();    //-> It will throw error
    //t->fly();
    Duck *adapter = new TurkeyAdapter(t);
    adapter->quack();
    adapter->fly();

    return 0;
}
