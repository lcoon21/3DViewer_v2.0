#ifndef SINGLETON_H
#define SINGLETON_H

#include "controller.h"

namespace s21 {
class Singleton {
 public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }

  Controller& GetData() { return c_; }

 private:
  Singleton() = default;
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);

  Controller c_;
};

}  // namespace s21

#endif  // SINGLETON_H
