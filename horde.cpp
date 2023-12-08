#ifndef HORDE_CPP
#define HORDE_CPP

#include "enemy.cpp"

#define number_of_rows 8
#define number_of_lines 4
#define total_number number_of_rows * number_of_lines

class Horde {
public:
  int total_number_of_enemies = total_number;
  int frame_counter;
  Enemy* enemies[total_number];
  Enemy null_enemy = Enemy(-1, -1);


  Horde() {
    initializeEnemies();
  }

  ~Horde() {
    deleteEnemies();
  }

  GameObject& findGameObjectByPosition(int x, int y) {
    for (int i = 0; i < total_number_of_enemies; ++i) {
      if (!enemies[i]->active) { continue; }

      if (enemies[i]->pos[0] == x && enemies[i]->pos[1] == y) {
        return *enemies[i];
      }
    }

    return null_enemy;
  }

  bool enemyInLastLine() {
    for (int i = 0; i < total_number_of_enemies; ++i) {
      if (!enemies[i]->active) { continue; }

      if (enemies[i]->pos[1] == 7) {
        return true;
      }
    }

    return false;
  }

  int numActiveEnemies() {
    int count = 0;

    for (int i = 0; i < total_number_of_enemies; ++i) {
      if (enemies[i]->active) { count++; }
    }

    return count;
  }

  void move(int framerate) {
    frame_counter++;

    if (frame_counter % (framerate / 4 + frameDelay(framerate)) == 0) {
      if (canMoveHorizontally()) {
        moveHorizontally();
      } else {
        moveVertically();
      }

      frame_counter = 0;
    }
  }

  void reset() {
    deleteEnemies();
    initializeEnemies();
  }

private:
  int distance = 1;

  bool canMoveHorizontally() {
    if (distance > 0) { return canMoveRight(); }

    return canMoveLeft();
  }

  bool canMoveLeft() {
    for (int i = 0; i < total_number_of_enemies; ++i) {
      if (enemies[i]->active && enemies[i]->pos[0] <= 0) {
        return false;
      }
    }

    return true;
  }

  bool canMoveRight() {
    for (int i = total_number_of_enemies - 1; i >= 0; --i) {
      if (enemies[i]->active && enemies[i]->pos[0] >= 11) {
        return false;
      }
    }

    return true;
  }

  void deleteEnemies() {
    for (int i = 0; i < total_number_of_enemies; i++) {
      delete enemies[i];
    }
  }

  int frameDelay(int framerate) {
    return ((int)numActiveEnemies() * (framerate) / total_number_of_enemies);
  }

  void initializeEnemies() {
    int enemy_space = 1;
    int start_pos[2] = { 2, 0 };

    for (int y = 0; y < number_of_lines; y++) {
      for (int x = 0; x < number_of_rows; x++) {
        enemies[x + y * number_of_rows] = new Enemy(start_pos[0] + x * enemy_space, start_pos[1] + y);
      }
    }

    null_enemy.destroy();
  }

  void moveHorizontally() {
    for (int i = 0; i < total_number_of_enemies; ++i) {
      enemies[i]->moveHorizontally(distance);
    }
  }

  void moveVertically() {
    distance = distance * -1;

    for (int i = 0; i < total_number_of_enemies; ++i) {
      enemies[i]->moveVertically();
    }
  }
};

#endif