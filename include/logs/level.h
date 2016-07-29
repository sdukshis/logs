#ifndef SDUKSHIS_LOGS_LEVEL_H
#define SDUKSHIS_LOGS_LEVEL_H

#include <ostream>
#include <cassert>

namespace sdukshis {
namespace logs {

enum class Level : std::uint8_t {
    Trace,
    Debug,
    Info,
    Warn,
    Error,
    Critical,
};

constexpr const char *str(Level level) {
    switch (level) {
    case Level::Trace:
        return "trace";
    case Level::Debug:
        return "debug";
    case Level::Info:
        return "info";
    case Level::Warn:
        return "warn";
    case Level::Error:
        return "error";
    case Level::Critical:
        return "critical";
    default:
        return "unknown";
    }
}

inline std::ostream &operator<<(std::ostream &stream, Level l) {
    return stream << str(l);
}

inline std::string to_string(Level l) {
    return std::string{str(l)};
}
}
}
#endif
