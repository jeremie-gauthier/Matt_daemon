#include "Listener.class.hpp"

// CTORS / DTORS

Listener::Listener(void) throw(std::runtime_error)
{
  socklen_t sockaddrSize = sizeof(struct sockaddr);
  bzero(&this->socket_in, sockaddrSize);
  this->socket_in.sin_family = AF_INET;
  this->socket_in.sin_addr.s_addr = htonl(INADDR_ANY);
  this->socket_in.sin_port = htons(PORT);

  this->srv_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (this->srv_socket_fd == -1)
    throw std::runtime_error("socket() failed");

  int opt = 1;
  if (setsockopt(this->srv_socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt,
                 sizeof(opt)) != 0)
    throw std::runtime_error("setsockopt() failed");

  if (bind(this->srv_socket_fd, (struct sockaddr *)&this->socket_in, sockaddrSize) == -1)
    throw std::runtime_error("bind() failed");

  bzero(this->clients, sizeof(this->clients));
}

Listener::~Listener(void)
{
  close(this->srv_socket_fd);
}

// OPERATORS

// MEMBER FUNCTIONS

int Listener::updateSockets(void)
{
  int max_fd = this->srv_socket_fd;

  // FD_ZERO() efface un ensemble.
  FD_ZERO(&this->read_fds);

  // FD_SET() ajoute un descripteur de fichier dans un ensemble.
  FD_SET(this->srv_socket_fd, &this->read_fds);

  //add child sockets to set
  for (int i = 0; i < MAX_CLIENTS; i++)
  {
    int client_sock_fd = this->clients[i];

    //if valid socket descriptor then add to read list
    if (client_sock_fd > 0)
      FD_SET(client_sock_fd, &this->read_fds);
    if (client_sock_fd > max_fd)
      max_fd = client_sock_fd;
  }

  return max_fd;
}

int Listener::registerNewSocket(const int client_socket_fd)
{
  //add new socket to array of sockets
  for (int i = 0; i < MAX_CLIENTS; i++)
  {
    //if position is empty
    if (this->clients[i] == 0)
    {
      this->clients[i] = client_socket_fd;
      Tintin_reporter::log("Register incoming connection");
      return i;
    }
  }
  return -1;
}

void Listener::handleNewConnection(void) throw(std::runtime_error)
{
  socklen_t sockaddrSize = sizeof(struct sockaddr);
  struct sockaddr_in clientSocketAddress;
  int client_socket_fd;

  // FD_ISSET() vérifie si un descripteur de fichier est contenu dans un ensemble, principalement utile après le retour de select().
  if (FD_ISSET(this->srv_socket_fd, &this->read_fds))
  {
    if ((client_socket_fd = accept(
             this->srv_socket_fd,
             (struct sockaddr *)&clientSocketAddress,
             (socklen_t *)&sockaddrSize)) < 0)
      throw std::runtime_error("accept() failed");

    if (this->registerNewSocket(client_socket_fd) < 0)
    {
      close(client_socket_fd);
      Tintin_reporter::error("Cannot register incoming connection (no space left)");
    }
  }
}

void Listener::handleSockOperation(void)
{
  char buffer[BUFFER_SIZE];

  for (int i = 0; i < MAX_CLIENTS; i++)
  {
    const int client_sock_fd = this->clients[i];

    if (client_sock_fd == 0)
      continue;

    if (FD_ISSET(client_sock_fd, &this->read_fds))
    {
      int read_bytes = recv(client_sock_fd, buffer, BUFFER_SIZE, 0);
      buffer[read_bytes - 1] = '\0';

      if (read_bytes <= 0 || strcmp(buffer, QUIT_COMMAND) == 0)
      {
        close(client_sock_fd);
        this->clients[i] = 0;
        Tintin_reporter::log("Close user connection");
      }
      else
      {
        const std::string client_msg(buffer);
        Tintin_reporter::log("User input:" + client_msg);
      }
    }
  }
}

void Listener::listen(void) throw(std::runtime_error)
{
  if (::listen(this->srv_socket_fd, MAX_CLIENTS) == -1)
    throw std::runtime_error("listen() failed");

  while (true)
  {
    const int max_fd = this->updateSockets();

    int activity = select(max_fd + 1, &this->read_fds, NULL, NULL, NULL);
    if ((activity < 0) && (errno != EINTR))
      throw std::runtime_error("select() failed");

    this->handleNewConnection();
    this->handleSockOperation();
  }
}

// NON-MEMBER FUNCTIONS
