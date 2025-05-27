#include "Touch.h"
#include "Remote.h"

class Game {
private:
  Touch path;
  Touch startPoint;
  Touch endPoint;
  Remote remote;
  byte playTime = 10;

  void inGame(byte playTime) {
    unsigned long lastPrintTimer = millis();
    unsigned long timer;
    Serial.println("Game started");
    Serial.println(playTime);
    while (1) {
      timer = millis();
      if (timer - lastPrintTimer >= 1000) {
        Serial.println(--playTime);
        lastPrintTimer = timer;
      }
      if (path.isTouching() || playTime == 0) {
        whenLose();
        return;
      }
      if (endPoint.isTouching()) {
        whenWin();
        return;
      }
    }
  }

  void whenWin() {
    Serial.println("hay");
  }

  void whenLose() {
    Serial.println("non");
  }

public:
  Game(byte startPointReadPin, byte pathReadPin, byte endPointReadPin, byte IR_RECEIVE_PIN)
    : startPoint(startPointReadPin), path(pathReadPin), endPoint(endPointReadPin), remote(IR_RECEIVE_PIN) {
  }

  void startRemote() {  //must call in setup()
    remote.begin();
  }

  void runGame() {
    if (remote.hasSignal()) {
      if (remote.decodeSignal() == 'p') {
        if (!startPoint.isTouching()) {
          Serial.println("Please start at start point");
        } else {
          inGame(playTime);
        }
      }
    }
  }
};
