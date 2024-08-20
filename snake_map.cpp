#include "snake_map.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include "macros.h"

using namespace std;

SnakeMap::SnakeMap(Snake *snake)
{
    this->snake = snake;
    clear_map();
    srand(time(NULL));
    update_snake_food(true);
}

void SnakeMap::redraw(void)
{
    clear_map();
    for (int i = 0; i < MAP_END; i++)
    {
        cout << endl;
    }
    update_score();
    vector<pair<int, int>> snake_parts = snake->snake_parts;
    for (int i = 0; i < snake_parts.size(); i++)
    {
        pair<int, int> tmp = snake_parts[i];
        map_array[tmp.first][tmp.second] = SNAKE_CHAR;
    }
    update_snake_head(snake);
    update_snake_food(false);
    map_array[snake_food.first][snake_food.second] = SNAKE_FOOD_CHAR;
    for (int i = MAP_HEIGHT - 1; i >= 0; i--)
    {
        for (int j = MAP_WIDTH-1; j >= 0; j--)
        {
            if (map_array[i][j] == SNAKE_HEAD_WEST)
                cout << "\033[0;32m" << map_array[i][j] << ' ';
            
            else if (map_array[i][j] == SNAKE_CHAR)
                cout << "\033[1;32m" << map_array[i][j] << ' ';
            
            else if (map_array[i][j] == SNAKE_FOOD_CHAR)
                 cout << "\033[1;31m" << map_array[i][j] << ' ';
            
            else
                cout << "\033[0;0m" << map_array[i][j] << ' ' ;

            
        }
        cout << endl;
    }
}

void SnakeMap::update_snake_food(bool force_update)
{
    if (snake->food_eaten || force_update)
    {
        while (true)
        {
            int random_i = rand() % MAP_WIDTH;
            int random_j = rand() % MAP_HEIGHT;
            if (map_array[random_i][random_j] == MAP_CHAR)
            {
                snake_food = make_pair(random_i, random_j);
                snake->set_snake_food(snake_food);
                snake->food_eaten = false;
                break;
            }
        }
    }
}

void SnakeMap::clear_map()
{
    for (int i = MAP_HEIGHT-1; i >= 0; i--)
    {
        for (int j = MAP_WIDTH-1; j >= 0 ; j--)
        {
            map_array[i][j] = MAP_CHAR;
        }
    }
}

void SnakeMap::update_snake_head(Snake *snake)
{
    char snake_head_char = SNAKE_CHAR;

    switch (snake->get_direction())
    {
    case West:
        snake_head_char = SNAKE_HEAD_WEST;
        break;
    case North:
        snake_head_char = SNAKE_HEAD_NORTH;
        break;
    case East:
        snake_head_char = SNAKE_HEAD_EAST;
        break;
    case South:
        snake_head_char = SNAKE_HEAD_SOUTH;
        break;
    }
    pair<int, int> snake_head = snake->snake_head;
    map_array[snake_head.first][snake_head.second] = snake_head_char;
}

void SnakeMap::update_score(void)
{
    cout << "Score:" << snake->length * 5 - 15 << endl;
}