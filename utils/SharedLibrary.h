/**
 * Library to work with shared library
 *
 * Note: synchronization of this library should be performed by a client.
 * Basically client needs to syncronize reload (with write protection) and
 * any functions inside the library (with read protection).
 */

#pragma once

#include <string>
#include <functional>

#include <dlfcn.h>
#include <glog/logging.h>

namespace utils {

class SharedLibrary {
 public:
  explicit SharedLibrary(const std::string& libraryName);

  ~SharedLibrary();

  void reload();

  template <typename R, typename... Args>
  R (*loadFunction(const std::string& functionName))(Args...) {
    void* const functionPtr = dlsym(handle_, functionName.c_str());
    return reinterpret_cast<R (*)(Args...)>(functionPtr);
  }

 private:
  void init();

  void close();

  const std::string& libraryName_;

  void* handle_;
};
}

