
#include<iostream>
#include <vector>
#include <memory>
// using namespace std;

class Animal{
    public:
    virtual ~Animal() = default;
    virtual void speak() const{
   std::cout<<"Some animal \n ";
    }
};

class Dog: public Animal{
    public:
    void speak() const override{
        std::cout<<"Woof\n";
    }
};

class Cat: public Animal{
    public:
    void speak() const override{
        std::cout<< "Meow!\n";
    }
};

int main(){

    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Dog>());
    zoo.push_back(std::make_unique<Cat>());

    for(const auto& a : zoo){
        a->speak();

    }
    return 0;
}
