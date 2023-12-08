#ifndef PROJECTILE_CPP
#define PROJECTILE_CPP

#include "game_object.cpp"

class Projectile : public GameObject {
  public:

  int distance;

  Projectile(int dist) : GameObject(0,0) {
    active = false;
    distance = dist;
  }

  void activate(int x, int y) {
    if(active) { return; }

    active = true;
    pos[0] = x;
    pos[1] = y;
  }

  void move() {
    if(!active) { return; }

    pos[1] = pos[1] + distance;

    if(pos[1] < 0 || pos[1] > 7) { destroy(); }
  }
};

#endif