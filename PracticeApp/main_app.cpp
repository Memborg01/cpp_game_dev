#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

void AddEntity(std::vector<std::string> &players, std::string &player) {
  players.push_back(player);
  std::cout << "Player added to the database\n";
}

void PrintPlayerLength(const std::string &player) {
  std::cout << player.length() << "\n";
}

void InsertIntoMap(
    std::string region_name,
    std::unordered_map<std::string, std::vector<std::string>> &map,
    std::vector<std::string> &players) {

  map.insert(
      std::pair<std::string, std::vector<std::string>>(region_name, players));
}

int main(int argc, char *argv[]) {

  std::unordered_map<std::string, std::vector<std::string>> map{};

  std::string player1 = "Jakob";
  std::string player2 = "Jonas";
  std::string player3 = "Tristan";

  std::vector<std::string> europe_players{};

  AddEntity(europe_players, player1);
  AddEntity(europe_players, player2);
  AddEntity(europe_players, player3);

  std::cout << "---------------------\n";

  for (const std::string &player : europe_players) {
    PrintPlayerLength(player);
  }

  std::cout << "---------------------\n";

  std::string player4 = "Josh";
  std::string player5 = "Ming";
  std::string player6 = "Ping";

  std::vector<std::string> asian_players{};

  AddEntity(asian_players, player4);
  AddEntity(asian_players, player5);
  AddEntity(asian_players, player6);

  InsertIntoMap("Europe", map, europe_players);
  InsertIntoMap("Asia", map, asian_players);

  for (auto &m : map) {
    std::cout << m.first << "\n";
    std::cout << "***********\n";
    for (auto &player : m.second) {
      std::cout << player << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
