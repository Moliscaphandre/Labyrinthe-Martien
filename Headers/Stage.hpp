#ifndef DEF_STAGE_HPP
#define DEF_STAGE_HPP

#include "Entity.hpp"

class Stage {
public:
    static std::map < unsigned int, std::vector < Entity > > _levels;
    static bool loadStages();
    static void fill(unsigned int index, Type type, sf::Vector2f a, sf::Vector2f b);
};

#endif
