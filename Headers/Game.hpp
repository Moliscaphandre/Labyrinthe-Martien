#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "Stage.hpp"

class Game {
public:
    Game();
    ~Game();
    bool canMove(Type type, sf::Vector2f position);
    void move();
    void checkItems();
    void changeLevel(unsigned int index);
    void run();
private:
    sf::RenderWindow _window;
    std::vector < Entity > _entities;
    unsigned int _level, _lifes, _coins, _keys;
    sf::RenderTexture _render;
    sf::Sound _coin;
    sf::Sprite _background;
    sf::Clock _cAnim, _cMove;
    sf::Text _infos, _text;
};

#endif
