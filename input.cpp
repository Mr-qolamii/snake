#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>

using namespace std;

struct termios t;

void input_enter_off()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void input_enter_on()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

enum Direction get_input()
{
    enum Direction result = East;
    switch (getchar())
    {
    case 'd':
        result = West;
        break;
    case 's':
        result = North;
        break;
    case 'a':
        result = East;
        break;
    case 'w':
        result = South;
        break;
    default:
        result = Error;
        break;
    }
    return result;
}

void input_init()
{
    
}