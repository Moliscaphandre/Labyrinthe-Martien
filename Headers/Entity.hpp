#ifndef DEF_TILE_HPP
#define DEF_TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>

#define SIZE (32)
#define X (30)
#define Y (20)
#define WIDTH (SIZE*X)
#define HEIGHT (SIZE*Y)
#define ANIMATION (125)
#define NUMBER (3)
#define MOVE (4)
#define LEVELS (4)

#define N(x) (x*SIZE)

enum Type {PLANK, CHARACTER, MONSTER, COIN, KEY, CHEST, LEVER, DOOR};

enum Direction {RIGHT, BOTTOM, LEFT, TOP};

class Entity: public sf::Drawable {
public:
    static bool load();
    static sf::Texture _textures;
    static sf::Image _icon;
    static sf::Font _font;
    static sf::Texture _back;
    static sf::Shader _shader;
    static sf::Music _music;
    static sf::SoundBuffer _buffer;
    Entity(Type type, sf::Vector2f position);
    ~Entity();
    void anime();
    // Setters
    void setRotation(float angle) { this->_sprite.setRotation(angle); }
    void setDirection(Direction direction) { this->_direction = direction; }
    void move(sf::Vector2f offset) { this->_sprite.move(offset); }
    void setActive(bool active) { this->_active = active; }
    // Getters
    inline sf::Sprite getSprite() const { return this->_sprite; }
    inline Type getType() const { return this->_type; }
    inline Direction getDirection() const { return this->_direction; }
    inline sf::Vector2f getPosition() const { return this->_sprite.getPosition(); }
    inline bool getActive() const {return this->_active; }
private:
    // https://www.sfml-dev.org/documentation/2.0-fr/classsf_1_1Drawable.php#:~:text=sf%3A%3ADrawable%20is%20a,allows%20this%20nice%20syntax%20%22window.
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(_sprite, states);
    }
    sf::Sprite _sprite;
    Type _type;
    Direction _direction;
    unsigned int _anim;
    bool _down, _active;
};

#endif
