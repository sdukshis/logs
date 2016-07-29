#ifndef SDUKSHIS_LOGS_SINK_H
#define SDUKSHIS_LOGS_SINK_H

#include "log.h"

namespace sdukshis {
namespace logs {

class Sink {
public:
    virtual ~Sink() {}

    virtual void store(const Log &) = 0;
};
}
}
#endif