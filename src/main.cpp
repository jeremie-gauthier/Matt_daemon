#include "common.hpp"
#include "daemon.hpp"

static bool isRoot()
{
  return getuid() == 0;
}

static bool checkRoot()
{
  if (!isRoot())
  {
    std::cerr << "Permission denied" << std::endl;
    return false;
  }
  return true;
};

static int checkDaemonLockFile()
{
  const int pid_lock_file = open(LOCK_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  const int lock = flock(pid_lock_file, LOCK_EX | LOCK_NB);

  if (lock && errno == EWOULDBLOCK)
  {
    std::cerr << "matt_daemon is already running" << std::endl;
    close(pid_lock_file);
    return -1;
  }
  return pid_lock_file;
}

static bool startDaemon(const int pid_lock_file)
{
  const pid_t pid = fork();

  if (pid == -1)
  {
    std::cerr << "Cannot create daemon process" << std::endl;
    return false;
  }

  if (pid == 0)
  {
    eventLoop();
  }
  else
  {
    dprintf(pid_lock_file, "%d", pid);
    close(pid_lock_file);
  }
  return true;
}

int main(void)
{
  if (!checkRoot())
    return EXIT_FAILURE;

  const int pid_lock_file = checkDaemonLockFile();
  if (pid_lock_file == -1)
    return EXIT_FAILURE;

  if (!startDaemon(pid_lock_file))
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
