#include <iostream>
#include <memory>
#include <vector>
#include <filesystem>

#include "Game.h"

int main() {
    std::cout << "Current path: " << std::filesystem::current_path() << "\n";
    Game game = Game("2hu");
    game.Run();
    return 0;
}
