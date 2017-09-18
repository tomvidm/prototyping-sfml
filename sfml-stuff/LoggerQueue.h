#pragma once

#include <list>
#include <string>

typedef unsigned int uint;

namespace debug
{
    class LoggerMessage
    {
    public:
        LoggerMessage(uint timestamp, std::string message);
        inline uint getTimestamp() const { return timestamp_; }
        inline std::string getMessage() const { return message_; }

    private:
        uint timestamp_;
        std::string message_;
    };

    class LoggerQueue
    {
    public:
        LoggerQueue();

        void logMessage(LoggerMessage);
        void setMaxMessageCount(int maxMessages);
        
        //void updateStringRepr();
        std::string getStringRepr() const;
        void updateStringRepr();

    private:
        uint maxMessages_;

        std::string stringRepr_;
        std::list<LoggerMessage> logMessages_;
    };
}

