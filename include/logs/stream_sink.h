#ifndef SDUKSHIS_LOGS_STREAM_SINK_H
#define SDUKSHIS_LOGS_STREAM_SINK_H

#include <ostream>
#include <iomanip>

#include "sink.h"

namespace sdukshis {
namespace logs {

class StreamSink : public Sink {
public:
    StreamSink(std::ostream &stream)
        : stream_{stream} {}

    void store(const Log &log) {
        stream_ << log.level << ": " << log.message << std::endl;
    }

private:
    std::ostream &stream_;
};
}
}
#endif