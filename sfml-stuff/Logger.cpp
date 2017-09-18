#include "Logger.h"

namespace debug
{
    Logger::Logger()
    {
        font_.loadFromFile("courier.ttf");
        text_.setFont(font_);
        text_.setString(loggerQueue_.getStringRepr());
        text_.setCharacterSize(16);
        text_.setFillColor(sf::Color::Red);
    }

    void Logger::logMessage(LoggerMessage message)
    {
        loggerQueue_.logMessage(message);
    }

    void Logger::update()
    {
        loggerQueue_.updateStringRepr();
        text_.setString(loggerQueue_.getStringRepr());
    }

    void Logger::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(text_, states);
    }
}