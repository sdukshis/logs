#ifndef SDUKSHIS_LOGS_LOG_H
#define SDUKSHIS_LOGS_LOG_H

#include <chrono>
#include <string>

#include "level.h"
#include "config.h"

namespace sdukshis {
namespace logs {

struct Log {
    using timestamp = std::chrono::system_clock::time_point;
    timestamp ts;
    Level level;
    Pid pid;
    Tid tid;
    std::string group;
    std::string subgroup;
    std::string message;
};
}
}
#endif