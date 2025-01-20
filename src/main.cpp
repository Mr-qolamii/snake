#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "../include/input.h"
#include "../include/snake.h"
#include "../include/snake_map.h"
#include <utility>
#include "../include/macros.h"

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_enter_off();
}

void start_game(){
    while (1){
        Clear();
        snake.update_movement();
        snake_map.clear_map();
        if (snake.is_game_end()) {
            cout << "GAME OVER" << endl;
            snake = Snake();
            snake_map = SnakeMap(&snake);
            usleep(1000 * 1000);
            start_game();
        }
        snake_map.redraw();

        usleep(PAUSE_LENGTH);

        snake.validate_direction();
    }
}

int main()
{
    input_enter_off();
    start_game();
    return 0;
}
