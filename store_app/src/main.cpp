#include "book.hpp"
#include "book_store.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

int main() {

  size_t id = 10;
  float weight = 110.2f;
  float height = 12.4f;
  std::string name = "Lord of the Rings";
  std::string type = "Book";
  std::string publisher = "Test";
  std::string author = "J.R.R. Tolkien";

  Book myBook = Book(id, weight, height, name, type, publisher, author);
  myBook.GetItemInfo();

  //-----------

  size_t bookStoreId = 12;
  std::string bookStoreName = "Jakob's Books";
  std::unordered_map<std::string, Item *> items;
  std::string bookStoreTypes = "Fantasy Books";

  BookStore myStore =
      BookStore(bookStoreId, bookStoreName, items, bookStoreTypes);

  myStore.AddItem(name, &myBook);

  return 0;
}
