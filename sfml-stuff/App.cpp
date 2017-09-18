#include "App.h"

namespace game
{
    App::App()
    {
        window_.create(sf::VideoMode(1024, 768), "My window");
        ballTexture.loadFromFile("testsprite.png");
        ball.setTexture(ballTexture);
        ball.setScale(0.4f, 0.4f);
    }

    void App::start()
    {
        logger.logMessage(debug::LoggerMessage(0, "Main loop starting..."));
        while (window_.isOpen())
        {
            loop();
        }
    }

    void App::loop()
    {
        while (window_.pollEvent(event_))
        {
            if (event_.type == sf::Event::Closed)
            {
                window_.close();
            }
        }

        if (frameTimer_.getElapsedTime().asMicroseconds() > framePeriod_)
        {
            frameTimer_.restart();
            logger.update();

            render();
        }
    }

    void App::render()
    {
        window_.clear();
        window_.draw(ball);
        window_.draw(logger);
        window_.display();
    }
}