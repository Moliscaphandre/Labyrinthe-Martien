#include "../Headers/Entity.hpp"

using namespace sf;
using namespace std;

Texture Entity::_textures;
Image Entity::_icon;
Font Entity::_font;
Texture Entity::_back;
Shader Entity::_shader;
Music Entity::_music;
SoundBuffer Entity::_buffer;

bool Entity::load() {
    if (! _textures.loadFromFile("Textures/Tiles.png"))
        return false;
    if (! _icon.loadFromFile("Textures/Icon.png"))
        return false;
    if (! _font.loadFromFile("Fonts/CreditRiver.ttf"))
        return false;
    if (! _back.loadFromFile("Textures/Background.png"))
        return false;
    if (! _music.openFromFile("Sounds/Mijn.wav"))
        return false;
    if (! _buffer.loadFromFile("Sounds/Coin.wav"))
        return false;
    /*if (! Tile::_shader.loadFromFile("Data/Shaders/Shader.frag", Shader::Fragment))
        return false;*/
    return true;
}

Entity::Entity(Type type, Vector2f position) : _down(true), _active(true) {
    this->_direction = RIGHT;
    this->_anim = 0;
    this->_type = type;
    this->_sprite.setTexture(Entity::_textures);
    this->_sprite.setPosition(position);
    switch (type) {
        case PLANK: {
            unsigned int random = rand() % 40;
            if (random < 30)
                this->_sprite.setTextureRect(IntRect(0, 0, SIZE, SIZE));
            else if (random < 35)
                this->_sprite.setTextureRect(IntRect(0, SIZE, SIZE, SIZE));
            else if (random < 38)
                this->_sprite.setTextureRect(IntRect(0, SIZE*3, SIZE, SIZE));
            else
                this->_sprite.setTextureRect(IntRect(0, SIZE*2, SIZE, SIZE));
            break;
        }
        case CHARACTER: {
            this->_sprite.setOrigin(SIZE/2, SIZE/2);
            this->_sprite.setTextureRect(IntRect(SIZE, 0, SIZE, SIZE));
            break;
        }
        case MONSTER: {
            this->_sprite.setOrigin(SIZE/2, SIZE/2);
            this->_sprite.setTextureRect(IntRect(SIZE*2, 0, SIZE, SIZE));
            break;
        }
        case COIN: {
            this->_sprite.setTextureRect(IntRect(SIZE*3, 0, SIZE, SIZE));
            break;
        }
        case KEY: {
            this->_sprite.setTextureRect(IntRect(SIZE*4, 0, SIZE, SIZE));
            break;
        }
        case CHEST: {
            this->_sprite.setTextureRect(IntRect(SIZE*5, 0, SIZE, SIZE));
            break;
        }
        case LEVER: {
            this->_sprite.setTextureRect(IntRect(SIZE*6, 0, SIZE, SIZE));
            break;
        }
        case DOOR: {
            this->_sprite.setTextureRect(IntRect(SIZE*7, 0, SIZE, SIZE));
            break;
        }
        default: {
            break;
        }
    }
}

void Entity::anime() {
    if (this->_type == PLANK || this->_type == KEY || this->_type == CHEST || this->_type == LEVER || this->_type == DOOR) return;
    if (this->_anim >= NUMBER) {
        this->_anim = 1;
        if (this->_down == true) this->_down = false;
        else this->_down = true;
    } else this->_anim++;
    if (this->_down)
        this->_sprite.setTextureRect(IntRect(this->_sprite.getTextureRect().left, this->_anim*SIZE, SIZE, SIZE));
    else
        this->_sprite.setTextureRect(IntRect(this->_sprite.getTextureRect().left, (NUMBER-this->_anim)*SIZE, SIZE, SIZE));
}

Entity::~Entity() {}
