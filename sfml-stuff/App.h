#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Logger.h"
#include "Sprite.h"

#include <vector>

namespace game
{
    typedef unsigned int uint;

    class App
    {
    public:
        App();

        game::Sprite ball;
        sf::Texture ballTexture;

        void start();
    private:
        bool isRunning;

        sf::RenderWindow window_;

        sf::Event event_;

        sf::Clock frameTimer_;
        uint framePeriod_ = 16667;

        debug::Logger logger = debug::Logger();

        void loop();
        void render();
    };
}