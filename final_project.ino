#include "Game.h"

#define START_POINT_READ_PIN 12
#define PATH_READ_PIN 11
#define END_POINT_READ_PIN 10
#define IR_RECEIVE_PIN 2

Game game(START_POINT_READ_PIN, PATH_READ_PIN, END_POINT_READ_PIN, IR_RECEIVE_PIN);

void setup() {
  Serial.begin(9600);
  game.startRemote();
}

void loop() {
  game.runGame();
}
