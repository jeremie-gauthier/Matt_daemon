#include "daemon.hpp"

static void quitEventLoop(int signo)
{
  switch (signo)
  {
  case SIGTERM:
    Tintin_reporter::info("received SIGTERM. Exiting...");
    break;
  case SIGINT:
    Tintin_reporter::info("received SIGINT. Exiting...");
    break;
  case SIGQUIT:
    Tintin_reporter::info("received SIGQUIT. Exiting...");
    break;
  default:
    Tintin_reporter::info("Exiting...");
    break;
  }

  std::remove(LOCK_FILE);
  std::exit(0);
}

void eventLoop()
{
  std::signal(SIGTERM, quitEventLoop);

  while (true)
  {
    Tintin_reporter::info("daemon is running");
    sleep(1);
  }
}
