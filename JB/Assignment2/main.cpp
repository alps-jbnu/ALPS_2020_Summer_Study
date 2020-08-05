#include <iostream>

#include "Game.h"

using namespace rpg_extreme;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Game& game = Game::GetInstance();
    game.Start();

    std::cout << game.GetResultToString();

    game.Shutdown();

    return 0;
}