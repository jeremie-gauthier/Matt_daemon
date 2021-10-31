#include "common.hpp"

static bool isRoot()
{
  return getuid() == 0;
}

int main(void)
{
  const bool isRootUser = isRoot();

  if (isRootUser)
  {
    std::cout << "You are root user.\n";
  }
  else
  {
    std::cout << "You are not root user.\n";
  }

  std::cout << "Hello World!" << std::endl;
  return 0;
}
