#include <sstream>

#include <gtest/gtest.h>

#include <logs/logger.h>
#include <logs/stream_sink.h>
#include <logs/registry.h>

using namespace sdukshis::logs;

auto&& logger = Registry::logger("test");

TEST(logs, stream_sink) {
    std::stringstream ss;
    auto stream_sink = std::make_shared<StreamSink>(ss);
    logger.sink(stream_sink);
    logger.log(Level::Info, "Hello, world");

    ASSERT_STREQ("info: Hello, world\n", ss.str().c_str());
}
