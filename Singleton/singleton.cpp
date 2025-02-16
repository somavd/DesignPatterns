#include<iostream>

using namespace std;

class Singleton {
    private:
    static Singleton *instance;
    Singleton() {
        cout<<"Instance is created\n";
    }

    public:
    static Singleton *getInstance() {
        if(instance == NULL) {
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage() {
        cout<<"ShowMessage from singleton"<<endl;
    }
};

Singleton *Singleton::instance = NULL;

int main() {
    Singleton *o1 = Singleton::getInstance();
    o1->showMessage();

    Singleton *o2 = Singleton::getInstance();
    o2->showMessage();
    return 0;
}