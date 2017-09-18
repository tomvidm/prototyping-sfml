#pragma once

#include "ResourceHandler.h"

#include <SFML/Graphics.hpp>

namespace resources
{
    class TextureHandler : public ResourceHandler<sf::Texture>
    {
    public:
        bool loadResourceFromFile(std::string resourceFileName);
    };
}

