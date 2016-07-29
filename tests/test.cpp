#include <logs/logger.h>
#include <logs/stream_sink.h>
#include <logs/registry.h>

auto&& logger = sdukshis::logs::Registry::logger("test");

int main()
{
    /* code */
    return 0;
}