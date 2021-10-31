#include "common.hpp"

void eventLoop()
{
  std::ofstream myfile("example.txt");

  while (true)
  {
    myfile << "Hello from daemon !" << std::endl;
    sleep(1);
  }

  myfile.close();
}
