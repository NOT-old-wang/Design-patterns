#include <iostream>
#include <string>

class Coffee
{
  public:
    Coffee() = delete;
    Coffee(Coffee &) = delete;
    Coffee(std::string name) : name_(name) {}

    std::string getName() { return name_; }
    virtual void getTaste() = 0;
    
  private:
    std::string name_;
};

class CoffeeLatte : public Coffee
{
  public:
    CoffeeLatte() : Coffee("拿铁") {}
    void getTaste() 
    {
        std::cout << "轻柔而香醇。" << std::endl;
    }
};

class MochaCoffee : public Coffee
{
  public:
    MochaCoffee() : Coffee("摩卡") {}
    void getTaste()
    {
        std::cout << "丝滑与醇厚。" << std::endl;
    }
};

enum class COFFEE
{
    LATTE = 0,
    MOCHA
};

class CoffeeMaker
{
  public:
    CoffeeMaker() : coffee_(nullptr) {}
    
    inline void setCoffeeType(COFFEE type) { coffeeType_ = type; }
    void makeCoffee()
    {
        switch(coffeeType_)
        {
        case COFFEE::LATTE: coffee_ = &coffeeLatte_;  
            break;
    
        case COFFEE::MOCHA: coffee_ = &mochaCoffee_;
            break;

        default:
            break;
        }

        std::cout << coffee_->getName() << ": ";
        coffee_->getTaste();
    } 

  private:
    COFFEE coffeeType_;

    Coffee* coffee_;  
    CoffeeLatte coffeeLatte_;
    MochaCoffee mochaCoffee_;
};
int main(int argc, const char ** agrv)
{
    CoffeeMaker cofferMaker;
    
    cofferMaker.setCoffeeType(COFFEE::LATTE);
    cofferMaker.makeCoffee();

    cofferMaker.setCoffeeType(COFFEE::MOCHA);
    cofferMaker.makeCoffee();
}