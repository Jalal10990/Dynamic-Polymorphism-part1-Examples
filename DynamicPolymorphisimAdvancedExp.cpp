
// We’ll use a vector to store multiple different objects.

// We’ll use smart pointers (unique_ptr) for automatic memory management.

#include<iostream>
#include<vector>
#include<memory>

class Shape{
    public:
    virtual ~Shape() = default; //virtual destructor
    virtual void draw() const {
        std::cout<< "Drawing a generic shape.\n";
    }
};

class Circle : public Shape{
    public:
    void draw() const override{
        std::cout<<"drawing a circle.\n";
    }
};
class Square: public Shape{
    public:
    void draw() const override {
        std::cout << "Drawing a square.\n";
    }

};
int main(){
  //A vector to store different shapes
  std::vector<std::unique_ptr<Shape>> Shapes;

  // add different shapes to the list
  Shapes.push_back(std::make_unique<Circle>());
  Shapes.push_back(std::make_unique<Square>());

  //Draw all shapes (dynamic polymorphism in action)
  for(const auto& Shape: Shapes){
    Shape->draw(); //// calls the correct derived function
    
  }

    return 0;
}