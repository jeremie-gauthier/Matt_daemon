#include "common.hpp"
#include "Tintin_reporter.class.hpp"

void eventLoop()
{
  while (true)
  {
    Tintin_reporter::info("daemon is running");
    sleep(1);
  }
}
