#include <iostream>
#include <string>

// two method
const constexpr unsigned char kmethod = 1;

class Coffee {
 public:
  Coffee() = delete;
  Coffee(Coffee&) = delete;
  Coffee(std::string name) : name_(name) {}

  std::string GetName() { return name_; }
  virtual void GetTaste() = 0;

 private:
  std::string name_;
};

class Latte : public Coffee {
 public:
  Latte() : Coffee("拿铁") {}
  void GetTaste() { std::cout << "轻柔而香醇。" << std::endl; }
};

class Mocha : public Coffee {
 public:
  Mocha() : Coffee("摩卡") {}
  void GetTaste() { std::cout << "丝滑与醇厚。" << std::endl; }
};

#if 0
enum class COFFEE { LATTE = 0, MOCHA };

class CoffeeMaker {
 public:
  CoffeeMaker() : coffee_(nullptr) {}

  inline void SetCoffeeType(COFFEE type) { coffee_type_ = type; }
  void MakeCoffee() {
    switch (coffee_type_) {
      case COFFEE::LATTE:
        coffee_ = &latte_coffee_;
        break;

      case COFFEE::MOCHA:
        coffee_ = &mocha_coffee_;
        break;

      default:
        break;
    }

    std::cout << coffee_->GetName() << ": ";
    coffee_->GetTaste();
  }

 private:
  COFFEE coffee_type_;

  Coffee* coffee_;
  Latte latte_coffee_;
  Mocha mocha_coffee_;
};
#endif

#if 1
class CoffeeMakerInterface {
 public:
  inline void MakeCoffee() {
    Coffee* coffee = this->SetCoffeeType();
    std::cout << coffee->GetName() << ": ";
    coffee->GetTaste();
  }

  virtual Coffee* SetCoffeeType() = 0;
};

template <typename Coffee>
class CoffeeMaker : public CoffeeMakerInterface {
 protected:
  Coffee* SetCoffeeType() override { return new Coffee(); }
};
#endif

int main(int argc, const char** agrv) {
// method 1
#if 0
  {
    CoffeeMaker coffee_maker;

    coffee_maker.SetCoffeeType(COFFEE::LATTE);
    coffee_maker.MakeCoffee();

    coffee_maker.SetCoffeeType(COFFEE::MOCHA);
    coffee_maker.MakeCoffee();
  }
#endif
// method 2
#if 1
  {
    // CoffeeMakerInterface* latte = new CoffeeMaker<Latte>();
    // CoffeeMaker<Latte> latte_coffee_maker;
    // latte_coffee_maker.MakeCoffee();

    // CoffeeMaker<Mocha> mocha_coffee_maker;
    // mocha_coffee_maker.MakeCoffee();
  }
#endif
}