#include "LoggerQueue.h"

namespace debug
{
    LoggerMessage::LoggerMessage(uint timestamp, std::string message)
    {
        timestamp_ = timestamp;
        message_ = message;
    }

    LoggerQueue::LoggerQueue()
    {
        maxMessages_ = 10;
        uint currentTime = 0;
    }

    void LoggerQueue::logMessage(LoggerMessage newMessage)
    {
        logMessages_.push_back(newMessage);

        if (logMessages_.size() > maxMessages_)
        {
            logMessages_.pop_front();
        }
    }

    void LoggerQueue::setMaxMessageCount(int maxMessages)
    {
        maxMessages_ = maxMessages;
    }

    std::string LoggerQueue::getStringRepr() const
    {
        return stringRepr_;
    }

    void LoggerQueue::updateStringRepr()
    {
        std::string newStringRepr = "";

        for (auto i : logMessages_)
        {
            newStringRepr = newStringRepr + std::to_string(logMessages_.size()) + "/" + std::to_string(maxMessages_) + "\t" + i.getMessage() + "\n";
        }

        stringRepr_ = newStringRepr;
    }
}

