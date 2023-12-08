#include "horde.cpp"
#include "player.cpp"

class CollisionManager {
  public:

  Horde& horde;
  Player& player;

  CollisionManager(Player &p, Horde &h) : player(p), horde(h) {
    
  }

  void process() {
    collisionGameObjectHorde(player);
    collisionGameObjectHorde(player.projectile, true);
  }

  private:

  void collisionGameObjectHorde(GameObject &game_object, bool kill_enemy = false) {
    GameObject& enemy_game_object = horde.findGameObjectByPosition(game_object.pos[0], game_object.pos[1]);

    if (!(enemy_game_object.active && game_object.active)) { return; }

    game_object.destroy();
    if(kill_enemy) { enemy_game_object.destroy(); }
  }
};