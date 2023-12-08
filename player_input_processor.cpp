#include <Arduino.h>
#include "player.cpp"

const int right_button = 2;
const int left_button = 3;
const int shoot_button = 4;

class PlayerInputProcessor {
public:
  PlayerInputProcessor() {
    pinMode(right_button, INPUT);
    pinMode(left_button, INPUT);
    pinMode(shoot_button, INPUT);
  }

  void process(Player &player) {
    if (buttonDown(left_button)) {
      leftButtonDown(player);
    }

    if (buttonDown(right_button)) {
      rightButtonDown(player);
    }

    if (buttonDown(shoot_button)) {
      shootButtonDown(player);
    }
  }

private:
  bool buttonDown(int button) {
    return (digitalRead(button) == digitalRead(button) == digitalRead(button) == HIGH);
  }

  void leftButtonDown(Player &player) {
    player.move(-1);
  }

  void rightButtonDown(Player &player) {
    player.move(1);
  }

  void shootButtonDown(Player &player) {
    player.shoot();
  }
};