#ifndef SDUKSHIS_LOGS_REGISTRY_H
#define SDUKSHIS_LOGS_REGISTRY_H

#include <string>
#include <map>
#include <tuple>

#include "logger.h"

namespace sdukshis {
namespace logs {

class Registry {
public:
    Registry(const Registry &) = delete;

    Registry(Registry &&) = default;

    Registry &operator=(const Registry &) = delete;

    Registry &operator=(Registry &&) = default;

    static Logger &logger(const std::string &name) {
        auto iter = loggers_.end();
        auto inserted = false;
        std::tie(iter, inserted) = loggers_.emplace(name, Logger{name});
        return iter->second;
    }

private:
    using storage = std::map<std::string, Logger>;
    static storage loggers_;
};
}
}
#endif