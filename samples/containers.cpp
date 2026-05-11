#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void PrintArray(int nums[5]) {
  for (int i = 0; i < 5; i++) {
    std::cout << nums[i] << "\n";
  }
}

void PrintVector(std::vector<int> nums) {
  for (int x : nums) {
    std::cout << x << "\n";
  }
}

void PrintMap(std::unordered_map<std::string, int> map) {
  for (auto x : map) {
    std::cout << x.first << " " << x.second << "\n";
  }
}

int main() {
  int nums[5] = {10, 5, 20, 30, 20};
  PrintArray(nums);

  std::cout << "-------------------------------\n";

  std::vector<int> vec_nums = {60, 20, 30};
  PrintVector(vec_nums);

  std::cout << "-------------------------------\n";
  std::unordered_map<std::string, int> my_map = {{"Jakob", 20},
                                                 {"Tristan", 24}};

  PrintMap(my_map);

  return 0;
}
