#include <iostream>
#include <string>

int lengthOfLastWord(std::string &s) {
  int i = s.length() - 1;

  while (i >= 0 && s[i] == ' ') {
    i--;
  }

  int length = 0;

  while (i >= 0 && s[i] != ' ') {
    length++;
    i--;
  }

  return length;
}

int main() {
  std::string one = "Hello World";
  std::string two = "  Aske my maaaaan  ";
  std::string three = "  Little red riding hood ";

  int oneRes = lengthOfLastWord(one);
  int twoRes = lengthOfLastWord(two);
  int threeRes = lengthOfLastWord(three);

  std::cout << "One: " << oneRes << "\n";
  std::cout << "Two: " << twoRes << "\n";
  std::cout << "Three: " << threeRes << "\n";

  return 0;
}
