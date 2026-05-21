#include <cstddef>
#include <string>
class User {
protected:
  size_t _id;
  std::string _name;

public:
  User(size_t ID, std::string &NAME);

  virtual void GetName() const = 0;
};
