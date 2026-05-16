#include "newPlayer.h"

int main() {

  Player myPlayer = Player(0, "Jakob");

  myPlayer.test = 10.f;
  myPlayer.AddPoints(20);
  myPlayer.GetValue();

  myPlayer.AddPoints(12);
  myPlayer.GetValue();

  NewPlayer player2 = NewPlayer(10, "Jonas", 10.f);
  player2.GetValue();
  player2.GetTest();

  return 0;
}
