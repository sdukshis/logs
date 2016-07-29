#ifndef SDUKSHIS_LOGS_LOGGER_H
#define SDUKSHIS_LOGS_LOGGER_H

#include <memory>

#include "log.h"
#include "level.h"
#include "sink.h"

namespace sdukshis {
namespace logs {

class Logger {
public:
    explicit Logger(const std::string &name,
                    const std::shared_ptr<Sink> &sink = std::shared_ptr<Sink>(),
                    Level level = Level::Info)
        : name_{name}
        , sink_{sink}
        , level_{level} {}

    Logger(const Logger &) = delete;

    Logger(Logger &&) = default;

    ~Logger() = default;

    Logger &operator=(const Logger &) = delete;

    Logger &operator=(Logger &&) = default;

    Level level() const {
        return level_;
    }

    std::string name() const {
        return name_;
    }

    void level(Level new_level) {
        level_ = new_level;
    }

    std::shared_ptr<Sink> sink() const {
        return sink_;
    }

    void sink(const std::shared_ptr<Sink> &sink) {
        sink_ = sink;
    }

    void log(Level level, const std::string &message) {
        Log l;
        l.ts = Log::timestamp::clock::now();
        l.level = level;
        l.group = name_;
        l.message = message;
        if (sink_) {
            sink_->store(l);
        }
    }

private:
    std::string name_;
    std::shared_ptr<Sink> sink_;
    Level level_;
};
}
}
#endif