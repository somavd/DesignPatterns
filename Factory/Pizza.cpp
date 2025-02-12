#include<iostream>

using namespace std;

class Pizza {
    protected:
        string name;
    public:
        Pizza() {
            name = "Unknown";
        }
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
        virtual void eat() = 0;        
};

class cheesePizza : public Pizza {
    public:
        cheesePizza() {
            name = "Cheese";
        }
        void prepare() {
            cout<<"Preparing "<<name<<" Pizza"<<endl;
        }
        void bake() {
            cout<<"Baking "<<name<<" Pizza"<<endl;
        }
        void cut() {
            cout<<"Cutting "<<name<<" Pizza"<<endl;
        }
        void box() {
            cout<<"Boxing "<<name<<" Pizza"<<endl;
        }
        void eat() {
            cout<<"Eating "<<name<<" Pizza"<<endl;
        }
};

class veggiePizza : public Pizza {
    public:
        veggiePizza() {
            name = "Veggie";
        }
        void prepare() {
            cout<<"Preparing "<<name<<" Pizza"<<endl;
        }
        void bake() {
            cout<<"Baking "<<name<<" Pizza"<<endl;
        }
        void cut() {
            cout<<"Cutting "<<name<<" Pizza"<<endl;
        }
        void box() {
            cout<<"Boxing "<<name<<" Pizza"<<endl;
        }
        void eat() {
            cout<<"Eating "<<name<<" Pizza"<<endl;
        }
};

class pizzaFactory {
    public:
    Pizza *createPizza(string type) {
        if(type == "cheese")
            return new cheesePizza();
        else if(type == "veggie")
            return new veggiePizza();
        return NULL;
    }
};

class pizzaStore{
    private:
    pizzaFactory factory;
    public:
    pizzaStore(pizzaFactory f) {
        factory = f;
    }
    Pizza *orderPizza(string type) {
        Pizza *p = factory.createPizza(type);
        p->prepare();
        p->bake();
        p->cut();
        p->box();
        return p;
    }
};

int main() {
    pizzaFactory f;
    pizzaStore *ps = new pizzaStore(f);
    Pizza *p = ps->orderPizza("cheese");
    p->eat();

    Pizza *p1 = ps->orderPizza("veggie");
    p1->eat();
    return 0;
}