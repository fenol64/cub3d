#include "headers/cube.h"

int main(int c, char **v)
{
    t_cube cube;

    if (!main_handler(c, v, &cube))
        return (1);
    return (0);
}