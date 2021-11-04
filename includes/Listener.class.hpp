#ifndef LISTENER_CLASS_HPP
#define LISTENER_CLASS_HPP

#include "common.hpp"
#include "Tintin_reporter.class.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h> // bzero

#include <sys/select.h>

#define PORT 4242
#define MAX_CLIENTS 3
#define BUFFER_SIZE 1024

class Listener
{
public:
  Listener(void) throw(std::runtime_error);
  Listener(const Listener &listener) = delete;

  ~Listener(void);

  Listener &operator=(const Listener &rhs) = delete;

  void listen(void) throw(std::runtime_error);

private:
  struct sockaddr_in socket_in;

  int socket_fd;
  // int active_conn;
  int clients[MAX_CLIENTS];
  fd_set read_fds;

  int updateSockets(void);
  void handleNewConnection(void) throw(std::runtime_error);
  void handleSockOperation(void);
  int registerNewSocket(const int new_socket);
};

#endif
