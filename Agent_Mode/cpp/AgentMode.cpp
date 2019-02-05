#include <iostream>

class ReceiveParcel
{
  public:
    ReceiveParcel(std::string name) : name_(name) {}

    std::string getName(void)const { return name_; } 
    virtual void receive(std::string praceContent) = 0;

  private:
    std::string name_;
};

class TonyReception : public ReceiveParcel
{
  public:
    TonyReception(std::string name, std::string phoneNum) : ReceiveParcel(name) , phoneNum_(phoneNum) {}

    std::string getPhoneNum() { return phoneNum_; }
    void receive(std::string peaceContent)
    {
        std::cout << "货物主人:" << getName() << ", 手机号：" << getPhoneNum() << std::endl;   
        std::cout << "接收到：" << peaceContent << std::endl;
    }
  private:
    std::string phoneNum_;
};

class WendyReception : public ReceiveParcel
{
  public:
    WendyReception(std::string name, ReceiveParcel& receiveParcel) : 
        ReceiveParcel(name) ,
        receiveParcel_(&receiveParcel)        
        {}

    void receive(std::string peaceContent)
    {
       if(receiveParcel_ != nullptr) 
       {
           preReceive();
           receiveParcel_->receive(peaceContent);
           afterReceive();
       }
    }
  private:
    inline void preReceive()
    {
        std::cout << "我是" << receiveParcel_->getName() << "的朋友， 我来帮他拿快递！" << std::endl; 
    }

    inline void afterReceive()
    {
        std::cout << "代收人" << getName() << std::endl;
    }

    std::string phoneNum_;
    ReceiveParcel* receiveParcel_;
};

int main(int argv, const char **argc)
{
    TonyReception tony("Tony", "12345678");
    WendyReception wendy("wendy", tony);

    wendy.receive("玩具");
}