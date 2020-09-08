#include <iostream>
#include"allegroinit.h"
#include "game.h"



int main()
{
    Game *game = new Game();
    game->init();
    delete game;
    return 0;
}
END_OF_MAIN()




