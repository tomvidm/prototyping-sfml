#pragma once

#include <SFML/Graphics.hpp>

namespace game
{
    class Sprite : public sf::Sprite
    {
    private:
        virtual void update(float dt);
    };
}