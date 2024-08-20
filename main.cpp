#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include <utility>
#include "macros.h"

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;

    if (snake.snake_head.first < 0 || snake.snake_head.first >= MAP_HEIGHT || snake.snake_head.second < 0 || snake.snake_head.second >= MAP_WIDTH)
    {
        result = true;
    }
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void start_game()
{
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            cout << "GAME OVER" << endl;
            snake = Snake();
            snake_map = SnakeMap(&snake);
            usleep(1000*1000);
            initialize();
            start_game();
            break;
        }
        snake_map.redraw();

        usleep(PAUSE_LENGTH);

        snake.validate_direction();
    }
}

int main()
{
    initialize();
    start_game();
    return 0;
}
