#include <logs/registry.h>

using sdukshis::logs::Registry;

std::unique_ptr<Registry::storage> Registry::loggers_;
