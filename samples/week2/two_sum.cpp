
#include <iostream>
#include <unordered_map>
#include <vector>
std::vector<int> twoSum(std::vector<int> &nums, int target) {

  std::unordered_map<int, int> mp;

  for (int i = 0; nums.size(); i++) {
    int compliment = target - nums[i];

    if (mp.find(compliment) != mp.end()) {
      return {mp[compliment], i};
    }

    mp[nums[i]] = i;
  }
  return {};
}

void PrintVector(std::vector<int> &v) {
  std::cout << "[";
  std::cout << v[0] << "," << v[1];
  std::cout << "]" << "\n";
}

int main() {

  std::vector<int> nums = {2, 7, 11, 15};
  int target1 = 9;
  int target2 = 22;

  std::vector<int> res1 = twoSum(nums, target1);
  std::vector<int> res2 = twoSum(nums, target2);

  std::cout << "Result 1: ";
  PrintVector(res1);

  std::cout << "Result 2: ";
  PrintVector(res2);

  return 0;
}
