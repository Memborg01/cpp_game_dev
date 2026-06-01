
#include <iostream>
#include <memory>
#include <utility>

class Resource {
private:
  int id;

public:
  Resource(int id) : id(id) { std::cout << "Resource: " << id << " aquired\n"; }

  ~Resource() { std::cout << "Resource " << id << " destroyed\n"; }

  void use() { std::cout << "Using resource: " << id << "\n"; }
};

// unique ptrs
void uniquePtrExample() {
  std::cout << "\n ---- Unique Pointer Example ----\n";
  std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>(1);
  ptr1->use();

  // transfer ownership
  std::unique_ptr<Resource> ptr2 = std::move(ptr1);
  ptr2->use();
}

void sharedPointerExample() {
  std::cout << "\n ---- Shared Pointer Example ----\n";

  std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(2);
  std::cout << "Use count: " << ptr1.use_count() << "\n";

  {
    std::shared_ptr<Resource> ptr2 = ptr1;
    std::cout << "Use count: " << ptr1.use_count() << "\n";
  }

  std::cout << "Use count: " << ptr1.use_count() << "\n";
}

void weakPointerExample() {
  std::cout << "\n ---- Weak Pointer Example ----\n";

  std::shared_ptr<Resource> shared = std::make_shared<Resource>(3);
  std::weak_ptr<Resource> weak = shared;

  std::cout << "Use count: " << shared.use_count() << "\n";

  if (auto temp = weak.lock()) {
    temp->use();
  } else {
    std::cout << "Resource expired!\n";
  }

  shared.reset();

  if (weak.expired()) {
    std::cout << "Resource is now expired";
  }
}

int main() {
  uniquePtrExample();
  sharedPointerExample();
  weakPointerExample();
  return 0;
}
