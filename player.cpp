#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "game_object.cpp"
#include "projectile.cpp"

class Player : public GameObject {
  using GameObject::GameObject;

public:
  Projectile projectile = Projectile(-1);

  void move(int distance) {
    int new_pos;

    if (!active) { return; }
    
    new_pos = pos[0] + distance;

    if(new_pos >= 0 && new_pos < 12) {
      pos[0] = new_pos;
    }
  }

  void shoot() {
    projectile.activate(pos[0], pos[1]);
  }
};

#endif