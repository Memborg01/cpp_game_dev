#include "component.hpp"
#include "entities.hpp"

int main() {

  Person person1;
  person1._weight = 110.1f;
  person1._name = "Jonas";
  person1.AddComponent<EatingComponent>();

  if (auto *e = person1.GetComponent<EatingComponent>()) {
    e->Eat();
  }

  Animal animal1;
  animal1._weight = 210.3f;
  animal1._species = "Feline";
  animal1.AddComponent<EatingComponent>();
  animal1.AddComponent<FlyingComponent>();

  if (auto *e = animal1.GetComponent<EatingComponent>()) {
    e->Eat();
  }

  if (auto *e = animal1.GetComponent<FlyingComponent>()) {
    e->Fly();
  }

  return 0;
}
