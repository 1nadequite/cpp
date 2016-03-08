#include "SharedLibrary.h"

namespace utils {

SharedLibrary::SharedLibrary(const std::string& libraryName)
  : libraryName_(libraryName), handle_(nullptr) {
  init();
}

SharedLibrary::~SharedLibrary() {
  close();
}

void SharedLibrary::reload() {
  close();
  init();
}

void SharedLibrary::init() {
  handle_ = dlopen(libraryName_.c_str(), RTLD_LAZY);
}

void SharedLibrary::close() {
  if (handle_) {
    dlclose(handle_);
    handle_ = nullptr;
  }
}
}

