#include <iostream>
#include <vector>

int main() {
  int myInt = 1000;
  int *myPtr = &myInt;

  std::cout << myPtr << "\n";
  std::cout << *myPtr << "\n";

  return 0;
}
