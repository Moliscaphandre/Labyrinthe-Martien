#include "../Headers/Game.hpp"

using namespace sf;
using namespace std;

Game::Game() : _level(0), _lifes(3), _coins(0), _keys(0) {
    this->_window.create(VideoMode(WIDTH, HEIGHT), "Labyrinthe Martien", Style::Close);
    this->_window.setFramerateLimit(1000);
    this->_infos.setFont(Entity::_font);
    this->_infos.setCharacterSize(SIZE);
    this->_render.create(WIDTH, HEIGHT);
    this->_background.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));
    this->_coin.setBuffer(Entity::_buffer);
}

Game::~Game() {}

void Game::run() {
    srand(time(NULL));
    Entity::_music.play();

    this->_window.setIcon(SIZE, SIZE, Entity::_icon.getPixelsPtr());
    this->_background.setTexture(Entity::_back);
    this->changeLevel(this->_level);
    Event event;
    while (this->_window.isOpen()) {
        while (this->_window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed: {
                    this->_window.close();
                    break;
                }
                default: {
                    break;
                }
            }
        }
        if (this->_cMove.getElapsedTime().asMilliseconds() > MOVE) {
            this->moveHero();
            this->moveSpiders();
            this->_cMove.restart();
        }
        if (this->_cAnim.getElapsedTime().asMilliseconds() > ANIMATION) {
            for (unsigned int i(0); i < this->_entities.size(); i++)
                this->_entities[i].anime();
            this->_cAnim.restart();
        }
        this->checkItems();
        this->_render.clear();
        Sprite render(this->_render.getTexture());
        this->_window.clear();
        this->_window.draw(this->_background);
        for (vector < Entity > ::iterator it = this->_entities.begin(); it != this->_entities.end(); it++) {
            if (it->getActive())
                this->_window.draw(*it);
        }
        if (this->_level >= LEVELS) {
            this->_infos.setCharacterSize(SIZE*3);
            this->_infos.setFillColor(Color(175, 45, 45));
            this->_infos.setPosition(WIDTH/3, HEIGHT/3);
            this->_infos.setString("Game Over !");
            Entity::_music.stop();
        } else {
            this->_infos.setString("                Niveau: " + std::to_string(this->_level+1) + "                Vie(s): " + std::to_string(this->_lifes)
            + "                Clé(s): " + std::to_string(this->_keys) + "                Pièce(s): " + std::to_string(this->_coins));
        }
        //this->_window.draw(render, &Tile::_shader);
        this->_window.draw(this->_infos);
        this->_window.display();
    }
}

void Game::changeLevel(unsigned int index) {
    if (this->_lifes <= 0 || index >= LEVELS) {
        this->_background.setTextureRect(IntRect(0, HEIGHT, WIDTH, HEIGHT));
        this->_lifes = 3;
        index = LEVELS;
    }
    this->_entities.clear();
    this->_level = index;
    this->_entities = Stage::_levels[index];
}

void Game::checkItems() {
    bool lever = false;
    for (vector < Entity > ::iterator it = this->_entities.begin(); it != this->_entities.end(); it++) {
        if (it->getType() == CHARACTER && it->getActive() == true) {
            for (vector < Entity > ::iterator jt = this->_entities.begin(); jt != this->_entities.end(); jt++) {
                if (jt->getType() == PLANK || jt->getType() == MONSTER || jt->getActive() != true) continue;
                Vector2f position = jt->getPosition();
                if (it->getPosition().x >= position.x && it->getPosition().x <= position.x+SIZE)
                if (it->getPosition().y >= position.y && it->getPosition().y <= position.y+SIZE) {
                    Type type = jt->getType();
                    switch (type) {
                        case COIN: {
                            this->_coin.play();
                            this->_coins++;
                            jt->setActive(false);
                            break;
                        }
                        case KEY: {
                            this->_keys++;
                            jt->setActive(false);
                            break;
                        }
                        case LEVER: {
                            lever = true;
                            jt->setActive(false);
                            break;
                        }
                        case CHEST: {
                            if (this->_keys > 0) {
                                this->_coin.play();
                                this->_coins += 5;
                                this->_keys--;
                                jt->setActive(false);
                            }
                            break;
                        }
                        case DOOR: {
                            if (this->_keys > 0) {
                                this->changeLevel(this->_level+1);
                                this->_keys--;
                                return;
                            }
                            break;
                        }
                        default: { break; }
                    }
                }
            }
        }
    }
    if (lever) {
        for (vector < Entity > ::iterator kt = this->_entities.begin(); kt != this->_entities.end(); kt++) {
            if (kt->getType() == DOOR) {
                Vector2f o = kt->getPosition();
                for (int x = -1; x < 2; x++) {
                    for (int y = -1; y < 2; y++) {
                        this->_entities.insert(this->_entities.begin(), Entity(Type(PLANK), Vector2f(o.x+x*SIZE, o.y+y*SIZE)));
                    }
                }
                break;
            }
        }
    }
}

bool Game::canMove(Type type, Vector2f position) {
    bool check = false;
    for (vector < Entity > ::iterator it = this->_entities.begin(); it != this->_entities.end(); it++) {
        if (type == it->getType()) continue;
        if (position.x >= it->getPosition().x && position.x <= it->getPosition().x+SIZE)
        if (position.y >= it->getPosition().y && position.y <= it->getPosition().y+SIZE) {
            switch (it->getType()) {
                case PLANK: {
                    check = true;
                    break;
                }
                case CHARACTER: {
                    this->_lifes--;
                    this->_coins = 0;
                    this->changeLevel(this->_level);
                    return false;
                }
                case MONSTER: {
                    this->_lifes--;
                    this->_coins = 0;
                    this->changeLevel(this->_level);
                    return false;
                }

            }
        }

    }
    return check;
}

void Game::moveSpiders() {
    for (vector < Entity > ::iterator it = this->_entities.begin(); it < this->_entities.end(); it++) {
        if (it->getType() == MONSTER) {
            Vector2f m = it->getPosition();
            switch (it->getDirection()) {
                case RIGHT: {
                    it->setRotation(-90);
                    if (canMove(MONSTER, Vector2f(m.x+1, m.y))) it->move(Vector2f(0.5, 0));
                    else it->setDirection(Direction(rand()%4));
                    break;
                }
                case BOTTOM: {
                    it->setRotation(0);
                    if (canMove(MONSTER, Vector2f(m.x, m.y+1))) it->move(Vector2f(0, 0.5));
                    else it->setDirection(Direction(rand()%4));
                    break;
                }
                case LEFT: {
                    it->setRotation(-270);
                    if (canMove(MONSTER, Vector2f(m.x-1, m.y))) it->move(Vector2f(-0.5, 0));
                    else it->setDirection(Direction(rand()%4));
                    break;
                }
                case TOP: {
                    it->setRotation(180);
                    if (canMove(MONSTER, Vector2f(m.x, m.y-1))) it->move(Vector2f(0, -0.5));
                    else it->setDirection(Direction(rand()%4));
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
}

void Game::moveHero() {
    for (vector < Entity > ::iterator it = this->_entities.begin(); it < this->_entities.end(); it++) {
        if (it->getType() == CHARACTER) {
            Vector2f pos = it->getSprite().getPosition();
            if (Keyboard::isKeyPressed(Keyboard::Left))
                if (this->canMove(CHARACTER, Vector2f(pos.x-1, pos.y))) it->move(Vector2f(-1, 0));
            if (Keyboard::isKeyPressed(Keyboard::Right))
                if (this->canMove(CHARACTER, Vector2f(pos.x+1, pos.y))) it->move(Vector2f(1, 0));
            if (Keyboard::isKeyPressed(Keyboard::Up))
                if (this->canMove(CHARACTER, Vector2f(pos.x, pos.y-1))) it->move(Vector2f(0, -1));
            if (Keyboard::isKeyPressed(Keyboard::Down))
                if (this->canMove(CHARACTER, Vector2f(pos.x, pos.y+1))) it->move(Vector2f(0, 1));
        }
    }
}
