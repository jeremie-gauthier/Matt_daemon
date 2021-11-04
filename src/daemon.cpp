#include "daemon.hpp"

static void quitEventLoop(int signo)
{
  switch (signo)
  {
  case SIGTERM:
    Tintin_reporter::info("Received SIGTERM. Exiting...");
    break;
  case SIGINT:
    Tintin_reporter::info("Received SIGINT. Exiting...");
    break;
  case SIGQUIT:
    Tintin_reporter::info("Received SIGQUIT. Exiting...");
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
  std::signal(SIGINT, quitEventLoop);
  std::signal(SIGQUIT, quitEventLoop);

  Listener listener;

  try
  {
    listener.listen();
  }
  catch (const std::exception &e)
  {
    const std::string error(e.what());
    Tintin_reporter::error(error);
    return quitEventLoop(-1);
  }

  // while (true)
  // {
  //   Tintin_reporter::info("daemon is running");
  //   sleep(1);
  // }
}
