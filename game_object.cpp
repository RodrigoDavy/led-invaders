#ifndef GAME_OBJECT_CPP
#define GAME_OBJECT_CPP

class GameObject {
public:
  int pos[2];
  bool active;

  GameObject(int x, int y) {
    pos[0] = x;
    pos[1] = y;
    active = true;
  }

  void destroy() {
    active = false;
    pos[0] = 0;
    pos[1] = 0;
  }
};

#endif