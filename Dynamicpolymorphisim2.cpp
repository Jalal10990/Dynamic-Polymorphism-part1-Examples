
#include<iostream>

class Shape{
    public:
    //virtual function - can be overridden in derived classes
    virtual void draw(){
        std::cout<<"Drawing a generic shape.\n";

    }
};

class circle : public Shape{
    public:
    void draw() override{
        std::cout<< "Drawing a circle.\n";
    }
};
class Square : public Shape{
    public:
    void draw() override {
        std::cout<<"Drawing a square.\n";
    }
};
int main(){
    Shape* shape1 = new circle(); //base pointer to  derived object
    Shape* shape2 = new Square();  

    //Dynamic Polymorphism in Action
    shape1->draw(); //calls circle draw()
    shape2->draw(); //calls square draw()

    //Even though both are Shape*, the correct version of draw() is chosen at runtime.
    delete shape1; //clean up
    delete shape2; 
    //Dynamic Polymorphism = Run-time Polymorphism
// The program decides which function to call while it is running, based on the actual object type (Circle or Square), not just the pointer type (Shape*).

    return 0;
}