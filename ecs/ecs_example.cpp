#include <iostream>
#include <memory>
#include <string>
#include <typeindex>
#include <unordered_map>
#include <utility>

struct Component {
  virtual ~Component() = default;
};

struct EatingComponent : public Component {
  void Eat() { std::cout << "Eating...\n"; }
};

struct FlyingComponent : public Component {
  void Fly() { std::cout << "Flying...\n"; }
};

struct Entity {
private:
  std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

public:
  template <typename T, typename... Args> void AddComponent(Args &&...args) {
    components[typeid(T)] = std::make_unique<T>(std::forward<Args>(args)...);
  }

  template <typename T> T *GetComponent() {
    auto it = components.find(typeid(T));
    if (it != components.end()) {
      return static_cast<T *>(it->second.get());
    }
    return nullptr;
  }

  template <typename T> bool HasComponent() const {
    return components.count(typeid(T)) > 0;
  }

  template <typename T> void RemoveComponent() { components.erase(typeid(T)); }
};

struct Person : public Entity {
  float _weight;
  std::string _name;
};

int main() {

  Person person1;
  person1._weight = 110.1f;
  person1._name = "Jonas";
  person1.AddComponent<EatingComponent>();

  if (auto *e = person1.GetComponent<EatingComponent>()) {
    e->Eat();
  }

  return 0;
}
