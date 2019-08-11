/**
 * use c++ 11
 **/
#include <iostream>
#include <vector>

class Observer
{
  public:
    void update(int value);

    bool operator==(const Observer &o)
    {
        
    }
};

class DrinkingMode : public Observer
{
  public:
    void update(int value)
    {
        if(value >= 100)
        {
            std::cout << "can be Drinking " << std::endl;
        }
    }
};

class WashingMode : public Observer
{
  public:
    void update(int value)
    {
        if(value > 40 && value < 60)
        {
            std::cout << "can be Washing " << std::endl;
        }
    }
};

class Observable
{
  public:
    
    void addObserver(Observer observer)
    {
        observers_.push_back(observer);        
    }

    void removeObserver(Observer observer)
    {
        auto itr = observers_.begin();

        while(itr != observers_.end())
        {
            if(*itr == observer)
            {
                observers_.erase(itr);
            }
            itr++;
        }
    }

    void notifyObserver(int value)
    {
        auto itr = observers_.begin();

        while(itr != observers_.end())
        {
            itr->update(value);
            itr++;
        }
    }

  private:
    std::vector<Observer> observers_;  
};

class HotWater : public Observable
{
  public:
    HotWater() : temperature_(0) {}
    HotWater(int temp) : temperature_(temp) {}
    ~HotWater() {}

    inline void setTempurature(int temperature) 
    {
        temperature_ = temperature; 
        this->notifyObserver(temperature);    
    } 
    inline int temperature() { return temperature_; }
    
  private:
    int temperature_;
};


int main(int argc, const char** argv)
{
    HotWater hotWater(10);

    WashingMode wash;
    DrinkingMode drink;

    hotWater.addObserver(wash);
    hotWater.addObserver(drink);


}