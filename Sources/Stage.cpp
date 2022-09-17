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
    Stage::fill(3, PLANK, Vector2f(20, 3), Vector2f(26, 18));
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
    Stage::_levels[3].push_back(Entity(Type(MONSTER), Vector2f(N(20), N(5))));
    Stage::_levels[3].push_back(Entity(Type(CHARACTER), Vector2f(N(5), N(3))));

    // 4
    Stage::fill(4, PLANK, Vector2f(4, 15), Vector2f(23, 15));
    Stage::fill(4, PLANK, Vector2f(18, 14), Vector2f(23, 14));
    Stage::fill(4, PLANK, Vector2f(2, 17), Vector2f(24, 17));
    Stage::fill(4, PLANK, Vector2f(3, 7), Vector2f(4, 7));
    Stage::fill(4, PLANK, Vector2f(5, 5), Vector2f(6, 14));
    Stage::fill(4, PLANK, Vector2f(9, 8), Vector2f(10, 14));
    Stage::fill(4, PLANK, Vector2f(13, 5), Vector2f(14, 14));
    Stage::fill(4, PLANK, Vector2f(25, 3), Vector2f(25, 18));
    Stage::fill(4, PLANK, Vector2f(19, 3), Vector2f(24, 12));
    Stage::fill(4, PLANK, Vector2f(2, 3), Vector2f(2, 16));
    Stage::fill(4, PLANK, Vector2f(3, 3), Vector2f(18, 3));
    Stage::_levels[4].push_back(Entity(Type(LEVER), Vector2f(N(25), N(18))));
    Stage::_levels[4].push_back(Entity(Type(MONSTER), Vector2f(N(10), N(10))));
    Stage::_levels[4].push_back(Entity(Type(MONSTER), Vector2f(N(23), N(5))));
    Stage::_levels[4].push_back(Entity(Type(MONSTER), Vector2f(N(3), N(15))));
    Stage::_levels[4].push_back(Entity(Type(MONSTER), Vector2f(N(15), N(5))));
    Stage::_levels[4].push_back(Entity(Type(COIN), Vector2f(N(2), N(13))));
    Stage::_levels[4].push_back(Entity(Type(COIN), Vector2f(N(13), N(6))));
    Stage::_levels[4].push_back(Entity(Type(KEY), Vector2f(N(20), N(6))));
    Stage::_levels[4].push_back(Entity(Type(KEY), Vector2f(N(5), N(3))));
    Stage::_levels[4].push_back(Entity(Type(DOOR), Vector2f(N(9), N(5))));
    Stage::_levels[4].push_back(Entity(Type(CHEST), Vector2f(N(8), N(18))));
    Stage::_levels[4].push_back(Entity(Type(CHARACTER), Vector2f(N(18), N(15))));

    // 5
    Stage::fill(5, PLANK, Vector2f(9, 3), Vector2f(9, 5));
    Stage::fill(5, PLANK, Vector2f(1, 3), Vector2f(8, 3));
    Stage::fill(5, PLANK, Vector2f(1, 4), Vector2f(1, 18));
    Stage::fill(5, PLANK, Vector2f(2, 18), Vector2f(28, 18));
    Stage::fill(5, PLANK, Vector2f(28, 10), Vector2f(28, 17));
    Stage::fill(5, PLANK, Vector2f(20, 10), Vector2f(27, 10));
    Stage::fill(5, PLANK, Vector2f(20, 11), Vector2f(20, 16));
    Stage::fill(5, PLANK, Vector2f(3, 16), Vector2f(19, 16));
    Stage::fill(5, PLANK, Vector2f(21, 16), Vector2f(26, 16));
    Stage::fill(5, PLANK, Vector2f(3, 5), Vector2f(3, 15));
    Stage::fill(5, PLANK, Vector2f(4, 5), Vector2f(7, 5));
    Stage::fill(5, PLANK, Vector2f(7, 6), Vector2f(7, 6));
    Stage::fill(5, PLANK, Vector2f(7, 7), Vector2f(16, 7));
    Stage::fill(5, PLANK, Vector2f(10, 5), Vector2f(18, 5));
    Stage::fill(5, PLANK, Vector2f(18, 6), Vector2f(18, 14));
    Stage::fill(5, PLANK, Vector2f(5, 9), Vector2f(16, 14));
    Stage::fill(5, PLANK, Vector2f(13, 8), Vector2f(13, 8));
    Stage::fill(5, PLANK, Vector2f(17, 11), Vector2f(17, 11));
    Stage::fill(5, PLANK, Vector2f(5, 7), Vector2f(5, 8));
    Stage::fill(5, PLANK, Vector2f(20, 3), Vector2f(28, 8));
    Stage::fill(5, PLANK, Vector2f(15, 3), Vector2f(19, 3));
    Stage::fill(5, PLANK, Vector2f(15, 4), Vector2f(15, 4));
    Stage::fill(5, PLANK, Vector2f(12, 3), Vector2f(12, 4));
    Stage::fill(5, PLANK, Vector2f(2, 13), Vector2f(2, 13));
    Stage::fill(5, PLANK, Vector2f(10, 17), Vector2f(10, 17));
    Stage::fill(5, DOOR, Vector2f(24, 14), Vector2f(24, 14));
    Stage::_levels[5].push_back(Entity(Type(LEVER), Vector2f(N(7), N(14))));
    Stage::_levels[5].push_back(Entity(Type(KEY), Vector2f(N(5), N(7))));
    Stage::_levels[5].push_back(Entity(Type(KEY), Vector2f(N(28), N(10))));
    Stage::_levels[5].push_back(Entity(Type(CHEST), Vector2f(N(26), N(2))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(10), N(10))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(20), N(5))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(15), N(11))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(25), N(6))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(15), N(19))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(1), N(15))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(1), N(5))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(3), N(7))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(20), N(15))));
    Stage::_levels[5].push_back(Entity(Type(MONSTER), Vector2f(N(10), N(7))));
    Stage::_levels[5].push_back(Entity(Type(PLANK), Vector2f(N(4), N(10))));
    Stage::_levels[5].push_back(Entity(Type(COIN), Vector2f(N(3), N(6))));
    Stage::_levels[5].push_back(Entity(Type(COIN), Vector2f(N(25), N(7))));
    Stage::_levels[5].push_back(Entity(Type(COIN), Vector2f(N(15), N(13))));
    Stage::_levels[5].push_back(Entity(Type(COIN), Vector2f(N(10), N(16))));
    Stage::_levels[5].push_back(Entity(Type(CHARACTER), Vector2f(N(9), N(5))));

    // 6
    Stage::fill(6, PLANK, Vector2f(1, 3), Vector2f(28, 12));
    Stage::fill(6, PLANK, Vector2f(6, 15), Vector2f(6, 18));
    Stage::fill(6, PLANK, Vector2f(7, 15), Vector2f(8, 15));
    Stage::fill(6, PLANK, Vector2f(7, 18), Vector2f(8, 18));
    Stage::fill(6, PLANK, Vector2f(8, 17), Vector2f(8, 17));
    Stage::fill(6, PLANK, Vector2f(11, 15), Vector2f(11, 18));
    Stage::fill(6, PLANK, Vector2f(12, 15), Vector2f(13, 15));
    Stage::fill(6, PLANK, Vector2f(12, 18), Vector2f(13, 18));
    Stage::fill(6, PLANK, Vector2f(13, 17), Vector2f(13, 17));
    Stage::fill(6, KEY, Vector2f(24, 10), Vector2f(24, 10));
    Stage::fill(6, DOOR, Vector2f(24, 4), Vector2f(24, 4));
    Stage::fill(6, COIN, Vector2f(5, 5), Vector2f(7, 7));
    Stage::fill(6, PLANK, Vector2f(22, 13), Vector2f(25, 14));
    Stage::_levels[6].push_back(Entity(Type(CHARACTER), Vector2f(N(20), N(18))));
    Stage::_levels[6].push_back(Entity(Type(CHARACTER), Vector2f(N(22), N(18))));
    Stage::_levels[6].push_back(Entity(Type(CHARACTER), Vector2f(N(24), N(18))));
    Stage::_levels[6].push_back(Entity(Type(CHARACTER), Vector2f(N(21), N(17))));
    Stage::_levels[6].push_back(Entity(Type(CHARACTER), Vector2f(N(23), N(17))));
    Stage::_levels[6].push_back(Entity(Type(CHARACTER), Vector2f(N(24), N(14))));

    return true;
}
