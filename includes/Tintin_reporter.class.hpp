#ifndef TINTIN_REPORTER_CLASS_HPP
#define TINTIN_REPORTER_CLASS_HPP

#include "common.hpp"
#include <ctime>
#include <sstream>

// #define LOG_FILE_PARENT_DIR "/var"
#define LOG_FILE_DIR "log"
#define LOG_FILE_NAME "matt_daemon.log"
// #define LOG_FILE "/var/log/matt_daemon.log"

#define LOG_FILE_PARENT_DIR "."
#define LOG_FILE "./log/matt_daemon.log"

class Tintin_reporter
{
public:
  static Tintin_reporter &getInstance()
  {
    static Tintin_reporter instance;
    return instance;
  }

  static void info(const std::string &message)
  {
    Tintin_reporter::getInstance().write(" [ INFO ] " + message);
  }

  static void log(const std::string &message)
  {
    Tintin_reporter::getInstance().write(" [ LOG ] " + message);
  }

  static void error(const std::string &message)
  {
    Tintin_reporter::getInstance().write(" [ ERROR ] " + message);
  }

  Tintin_reporter(const Tintin_reporter &tintin_reporter) = delete;
  Tintin_reporter &operator=(const Tintin_reporter &rhs) = delete;

private:
  Tintin_reporter(void);
  ~Tintin_reporter(void);

  std::ofstream log_file;

  void write(const std::string &message);
};

#endif
