#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <unistd.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>

// #define LOCK_FILE_PARENT_DIR "/var"
#define LOCK_FILE_NAME "matt_daemon.lock"
// #define LOCK_FILE "/var/lock/matt_daemon.lock"

#define LOCK_FILE_PARENT_DIR "."
#define LOCK_FILE_DIR "lock"
#define LOCK_FILE "./lock/matt_daemon.lock"

#endif
