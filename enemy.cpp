#ifndef ENEMY_CPP
#define ENEMY_CPP

#include "game_object.cpp"

class Enemy : public GameObject {
  using GameObject::GameObject;

public:
  void moveHorizontally(int distance) {
    if (active) {
      pos[0] = pos[0] + distance;
    }
  }

  void moveVertically() {
    if (active) {
      pos[1] = pos[1] + 1;
    }
  }
};

#endif