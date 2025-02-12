#include<iostream>

using namespace std;

class Pet {
    protected:
        string name;
    public:
        Pet() {
            name = "unknown";
        }
        virtual void makesound() = 0;
        virtual void callPet() = 0;

};

class Dog:public Pet{
    public:
        Dog(string petName) {
            name = petName;
        }
        void makesound() {
            cout<<name<<" Makes Sound Woof Woof!"<<endl;
        }
        void callPet() {
            cout<<name<<" Coming!!!"<<endl;
        }
};

class Cat:public Pet{
    public:
    Cat(string petName) {
        name = petName;
    }
    void makesound() {
        cout<<name<<" Makes Sound Meow Meow!"<<endl;
    }
    void callPet() {
        cout<<name<<" Coming"<<endl;
    }
};

class PetFactory {
    public:
    Pet *createPet(string type, string name) {
        if(type == "dog") {
            return new Dog(name);
        }
        else if(type == "cat") {
            return new Cat(name);
        }
        return nullptr;
    }
};

class PetStore {
    private:
        PetFactory pf;
    public:
        PetStore(PetFactory p) {
            pf = p;
        }

        Pet *orderPet(string type, string name) {
            Pet *p = pf.createPet(type, name);
            p->makesound();
            return p;
        }
};

int main() {
    Pet *c;
    Pet *d;

    PetFactory pf;
    PetStore *ps = new PetStore(pf);
    c = ps->orderPet("dog", "Max");
    c->callPet();
    
    d = ps->orderPet("cat", "Lun");
    d->callPet();

    return 0;
}