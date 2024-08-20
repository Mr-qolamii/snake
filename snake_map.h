#ifndef _snake_map_h
#define _snake_map_h

#include "snake.h"
#include "macros.h"

class SnakeMap
{
public:
  SnakeMap(Snake *snake);
  void redraw();
  pair<int, int> snake_food;
  void update_snake_food(bool force_update);
  void update_score();
  void clear_map();
private:
  void update_snake_head(Snake *snake);
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Snake *snake;
};




#endif