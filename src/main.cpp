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

  const int fd = open(LOCK_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  const int lock = flock(fd, LOCK_EX | LOCK_NB);

  if (lock && errno == EWOULDBLOCK)
  {
    std::cout << "Only one instance of matt_daemon is possible" << std::endl;
    close(fd);
    return -1;
  }

  const pid_t pid = fork();
  if (pid == 0)
  {
    eventLoop();
  }
  else
  {
    dprintf(fd, "%d", pid);
    close(fd);
  }
  return 0;
}
