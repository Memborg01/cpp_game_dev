#include <iostream>
#include <typeindex>
#include <memory>
#include <unordered_map>

struct Component {
  virtual ~Component() = default;
};

struct EatingComponent: public Component {
  void Eat() {
    std::cout << "Eating...\n";
  }
};

struct FlyingComponent: public Component {
  void Fly() {
    std::cout << "Flying...\n";
  }
};

struct Entity {
  private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

  public:

};

int main () {
  
  return 0;
}
