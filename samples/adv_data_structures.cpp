#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

// struct Dummy {
//   int val;
// };
//
// struct Test {
//   int num;
//   std::string name;
//   float f_num;
//   Dummy dm;
// };

union Holder {
  int32_t num;
  uint16_t low_num;
  uint8_t really_low_num;
};

enum Levels { FOREST, MOUNTAIN, HELL, SNOW };

int main() {

  Holder test;
  test.num = 10;
  test.low_num = 16;
  test.really_low_num = 4;

  std::cout << sizeof(test) << "\n";
  std::cout << "------------------" << "\n";

  enum Levels myLevel = HELL;
  std::cout << myLevel << "\n";

  return 0;
}
