#include "../Headers/Game.hpp"

int main() {
    Game game;
    if (Entity::load() && Stage::loadStages()) {
        game.run();
    } else {
        return 1;
    }
    return 0;
}
