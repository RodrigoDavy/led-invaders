#include <Arduino.h>
#include "game_object.cpp"

class Renderer {
public:
  byte frame[8][12] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };

  void draw(GameObject* objects[], int numObjects) {
    drawGameObjects(objects, numObjects);
  }

  void draw(GameObject object) {
    drawGameObject(object);
  }

  void resetFrame() {
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 12; x++) {
        frame[y][x] = 0;
      }
    }
  }

private:
  void drawGameObject(GameObject object) {
    if (object.active) {
      setGameObject(object.pos[0], object.pos[1]);
    }
  }

  void drawGameObjects(GameObject* objects[], int numObjects) {
    for (int i = 0; i < numObjects; ++i) {
      if (objects[i]->active) {
        setGameObject(objects[i]->pos[0], objects[i]->pos[1]);
      }
    }
  }

  void setGameObject(int pos_x, int pos_y) {
    frame[pos_y][pos_x] = 1;
  }
};