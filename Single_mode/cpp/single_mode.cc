#include <iostream>

class Singleton {
 public:
  static Singleton &Instance() {
    static Singleton instance;
    return instance;
  }
  void Count() { std::cout << count_ << std::endl; }

  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

 private:
  Singleton() : count_(0) { count_++; }
  uint32_t count_;
};

int main(int argc, const char **argv) {
  Singleton::Instance().Count();
  Singleton::Instance().Count();
}