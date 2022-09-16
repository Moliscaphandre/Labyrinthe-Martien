#include "../Headers/Stage.hpp"

using namespace sf;
using namespace std;

map < unsigned int, vector < Entity > > Stage::_levels;

void Stage::fill(unsigned int index, Type type, Vector2f a, Vector2f b) {
    for (int x(a.x); x <= b.x; x++) {
        for (int y(a.y); y <= b.y; y++) {
            Stage::_levels[index].push_back(Entity(Type(type), Vector2f(N(x), N(y))));
        }
    }
}

bool Stage::loadStages() {
    // 0
    Stage::fill(0, PLANK, Vector2f(1, 13), Vector2f(3, 14));
    Stage::fill(0, PLANK, Vector2f(1, 15), Vector2f(20, 15));
    Stage::fill(0, PLANK, Vector2f(10, 10), Vector2f(10, 14));
    Stage::fill(0, PLANK, Vector2f(8, 5), Vector2f(12, 9));
    Stage::_levels[0].push_back(Entity(Type(KEY), Vector2f(N(10), N(8))));
    Stage::_levels[0].push_back(Entity(Type(COIN), Vector2f(N(10), N(6))));
    Stage::fill(0, PLANK, Vector2f(21, 14), Vector2f(23, 16));
    Stage::_levels[0].push_back(Entity(Type(DOOR), Vector2f(N(22), N(15))));
    Stage::_levels[0].push_back(Entity(Type(CHARACTER), Vector2f(N(2), N(14))));

    // 1
    Stage::fill(1, PLANK, Vector2f(10, 15), Vector2f(22, 15));
    Stage::fill(1, PLANK, Vector2f(5, 13), Vector2f(9, 13));
    Stage::_levels[1].push_back(Entity(Type(LEVER), Vector2f(N(6), N(13))));
    Stage::fill(1, PLANK, Vector2f(10, 5), Vector2f(10, 14));
    Stage::fill(1, PLANK, Vector2f(11, 5), Vector2f(25, 5));
    Stage::_levels[1].push_back(Entity(Type(COIN), Vector2f(N(25), N(5))));
    Stage::_levels[1].push_back(Entity(Type(DOOR), Vector2f(N(22), N(7))));
    Stage::fill(1, PLANK, Vector2f(15, 9), Vector2f(27, 13));
    Stage::_levels[1].push_back(Entity(Type(KEY), Vector2f(N(16), N(12))));
    Stage::_levels[1].push_back(Entity(Type(MONSTER), Vector2f(N(26), N(12))));
    Stage::_levels[1].push_back(Entity(Type(CHARACTER), Vector2f(N(22), N(15))));

    // 2
    Stage::fill(2, PLANK, Vector2f(1, 7), Vector2f(23, 7));
    Stage::fill(2, PLANK, Vector2f(1, 8), Vector2f(1, 18));
    Stage::fill(2, PLANK, Vector2f(2, 18), Vector2f(3, 18));
    Stage::fill(2, PLANK, Vector2f(4, 10), Vector2f(10, 18));
    Stage::fill(2, PLANK, Vector2f(11, 12), Vector2f(20, 12));
    Stage::fill(2, PLANK, Vector2f(15, 13), Vector2f(22, 16));
    Stage::fill(2, PLANK, Vector2f(22, 10), Vector2f(22, 12));
    Stage::fill(2, PLANK, Vector2f(14, 3), Vector2f(19, 5));
    Stage::fill(2, PLANK, Vector2f(4, 5), Vector2f(6, 6));
    Stage::_levels[2].push_back(Entity(Type(PLANK), Vector2f(N(15), N(6))));
    Stage::_levels[2].push_back(Entity(Type(KEY), Vector2f(N(22), N(10))));
    Stage::_levels[2].push_back(Entity(Type(KEY), Vector2f(N(18), N(4))));
    Stage::_levels[2].push_back(Entity(Type(CHEST), Vector2f(N(5), N(9))));
    Stage::_levels[2].push_back(Entity(Type(LEVER), Vector2f(N(16), N(16))));
    Stage::_levels[2].push_back(Entity(Type(DOOR), Vector2f(N(5), N(3))));
    Stage::_levels[2].push_back(Entity(Type(COIN), Vector2f(N(10), N(10))));
    Stage::_levels[2].push_back(Entity(Type(MONSTER), Vector2f(N(10), N(10))));
    Stage::_levels[2].push_back(Entity(Type(CHARACTER), Vector2f(N(22), N(7))));

    // 3
    Stage::fill(3, PLANK, Vector2f(3, 3), Vector2f(16, 18));
    Stage::fill(3, PLANK, Vector2f(17, 3), Vector2f(26, 6));
    Stage::_levels[3].push_back(Entity(Type(LEVER), Vector2f(N(14), N(18))));
    Stage::_levels[3].push_back(Entity(Type(KEY), Vector2f(N(26), N(5))));
    Stage::_levels[3].push_back(Entity(Type(DOOR), Vector2f(N(18), N(15))));
    Stage::_levels[3].push_back(Entity(Type(COIN), Vector2f(N(3), N(11))));
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(3), N(11))));
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(4), N(13))));
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(5), N(15))));
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(6), N(17))));
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(7), N(19))));
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(15), N(5))));
    Stage::_levels[3].push_back(Entity(Type(CHARACTER), Vector2f(N(5), N(3))));

    return true;
}
