#include <chrono>
#include <iostream>
#include <thread>

// hpp
class Singleton {
 protected:
  Singleton(const std::string value) : value_(value) {counter++;}
  std::string value_;
  static Singleton* singleton_;

  public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;
    static Singleton* GetInstance(const std::string& value){
        if (singleton_ == nullptr) {
        singleton_ = new Singleton(value);
      }
      return singleton_;
    };
    static void PrintAlgo() {
        std::cout << "Imprime desde la clase" << std::endl;
    }
    static size_t counter;
    std::string value() const { return value_; }
};

// cpp
Singleton* Singleton::singleton_ = nullptr;
size_t Singleton::counter = 0;



int main() {
  std::cout << "Hay " << Singleton::counter << " singletons" << std::endl;
  Singleton *m = Singleton::GetInstance("Muzzarella");
  std::cout << "Hay " << Singleton::counter << " singletons" << std::endl;
  Singleton *p = Singleton::GetInstance("Primavera");
  std::cout << "Hay " << Singleton::counter << " singletons" << std::endl;

  std::cout << m->value() << std::endl;
  std::cout << p->value() << std::endl;

  Singleton::PrintAlgo();

  return 0;
}