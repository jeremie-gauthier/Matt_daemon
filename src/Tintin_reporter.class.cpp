#include "Tintin_reporter.class.hpp"

// CTORS / DTORS

Tintin_reporter::Tintin_reporter(void)
{
  if (stat(LOG_FILE_DIR, NULL) == -1)
    mkdir(LOG_FILE_DIR, 0755);
  this->log_file.open(LOG_FILE, std::ios::out | std::ios::app);
}

Tintin_reporter::~Tintin_reporter(void)
{
  this->log_file.close();
}

// OPERATORS

// MEMBER FUNCTIONS

//  PRIVATE

static const std::string twoDigits(int n)
{
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(2) << n;
  return ss.str();
}

void Tintin_reporter::write(const std::string &message)
{
  const time_t now = time(0);
  const tm *ltm = localtime(&now);

  this->log_file
      << "["
      << twoDigits(ltm->tm_mday) << "/" << twoDigits(1 + ltm->tm_mon) << "/" << (1900 + ltm->tm_year)
      << "-"
      << twoDigits(ltm->tm_hour) << ":" << twoDigits(ltm->tm_min) << ":" << twoDigits(ltm->tm_sec)
      << "]"
      << message
      << std::endl;
}

// NON-MEMBER FUNCTIONS
