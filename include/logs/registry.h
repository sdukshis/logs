#ifndef SDUKSHIS_LOGS_REGISTRY_H
#define SDUKSHIS_LOGS_REGISTRY_H

#include <string>
#include <map>
#include <tuple>
#include <memory>

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
        initialize_once();

        auto iter = loggers_->end();
        auto inserted = false;
        std::tie(iter, inserted) = loggers_->emplace(name, Logger{name});
        return iter->second;
    }

protected:
    static void initialize_once() {
        if (!loggers_) {
            loggers_ = std::make_unique<storage>();
        }        
    }

private:
    using storage = std::map<std::string, Logger>;
    static std::unique_ptr<storage> loggers_;
};
}
}
#endif