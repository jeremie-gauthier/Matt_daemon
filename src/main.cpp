#include "common.hpp"

static bool isRoot()
{
  return getuid() == 0;
}

void eventLoop()
{
  std::ofstream myfile("example.txt");

  while (true)
  {
    if (isRoot())
    {
      myfile << "Root" << std::endl;
    }
    else
    {
      myfile << "Not root" << std::endl;
    }
    sleep(1);
  }

  myfile.close();
}

int main(void)
{
  const bool is_root_user = isRoot();

  if (is_root_user)
  {
    std::cout << "You are root user.\n";
  }
  else
  {
    std::cout << "You are not root user.\n";
  }

  std::cout << "Hello World!" << std::endl;

  const pid_t pid = fork();
  if (pid == 0)
  {
    eventLoop();
  }
  else
  {
    std::cout << "PID: " << pid << std::endl;
  }
  return 0;
}
