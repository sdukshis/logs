#ifndef SDUKSHIS_LOGS_NULL_H
#define SDUKSHIS_LOGS_NULL_H

#include "sink.h"

namespace sdukshis {
namespace logs {

class Null : public Sink {
public:
    void store(const Log &) override {}
};
}
}
#endif