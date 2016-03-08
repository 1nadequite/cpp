/**
 * A base class for a singleton object.
 *
 * Simple implementation of CRTP.
 */

#pragma once

#include <memory>

namespace utils {

template <typename T>
class SingletonBase {
 public:
  SingletonBase() = default;
  virtual ~SingletonBase() = default;

  SingletonBase(const SingletonBase&) = delete;
  SingletonBase(SingletonBase&&) = delete;
  SingletonBase& operator=(const SingletonBase&) = delete;
  SingletonBase&& operator=(SingletonBase&&) = delete;

  static T& getInstance() {
    if (instance_ == nullptr) {
      instance_ = std::make_unique<T>();
    }
    return *instance_.get();
  }

 private:
  static std::unique_ptr<T> instance_;
};

template <typename T>
std::unique_ptr<T> SingletonBase<T>::instance_ = nullptr;

}

