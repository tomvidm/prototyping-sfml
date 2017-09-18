#pragma once

#include <SFML/Graphics.hpp>

#include "LoggerQueue.h"

namespace debug
{
    class Logger : public sf::Drawable, public sf::Transformable
    {
    public:
        Logger();

        void logMessage(LoggerMessage);

        virtual void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        LoggerQueue loggerQueue_;
        sf::Font font_;
        sf::Text text_;
    };
}