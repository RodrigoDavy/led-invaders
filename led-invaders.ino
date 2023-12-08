#include "Arduino_LED_Matrix.h"
#include "collision_manager.cpp"
#include "enemy.cpp"
#include "horde.cpp"
#include "player.cpp"
#include "player_input_processor.cpp"
#include "renderer.cpp"

#define FRAMERATE 15

ArduinoLEDMatrix matrix;
int frame_counter = 0;
Horde horde;
Player player = Player(5,7);
CollisionManager collision_manager(player, horde);
PlayerInputProcessor player_input_processor = PlayerInputProcessor();
Renderer renderer;

void setup() {
  matrix.begin();
}

void loop(){
  game_loop();
  reset_game();
}

bool game_loop() {
  while(true) {
    process_input();
    move_objects();
    collision_manager.process();
    render();
    int status = game_status();
    if(status >= 0) { return status; }
    wait_next_frame();
  }
  
}

int game_status() {
  if(!player.active) { return 0; }
  if(horde.enemyInLastLine()) { return 0; }
  if(horde.numActiveEnemies() == 0) { return 1; }

  return -1;
}

void move_objects() {
  horde.move(FRAMERATE);
  if(frame_counter % 3 > 0) { player.projectile.move(); }
}

void wait_next_frame() {
  delay(1000/FRAMERATE);
  frame_counter++;
}

void process_input() {
  player_input_processor.process(player);
}

void render() {
  renderer.resetFrame();
  renderer.draw(reinterpret_cast<GameObject**>(horde.enemies), horde.total_number_of_enemies);
  renderer.draw(player);
  renderer.draw(player.projectile);
  matrix.renderBitmap(renderer.frame, 8, 12);
}

void reset_game() {
  horde.reset();
  player = Player(5,7);
}

