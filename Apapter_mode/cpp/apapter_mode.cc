#include <iostream>

class Lion {
 public:
  virtual void Roar() { std::cout << "I am a Lion." << std::endl; }
};

class Hunter {
 public:
  void Hunt(Lion* const lion) { Lion lion_temp; lion->Roar(); }
};

class WildDog {
 public:
  void Bark() { std::cout << "I am a wild dog." << std::endl; }
};

class WildDogAdapter : public Lion {
 public:
  void Roar() { wild_dog_.Bark(); }

 private:
  WildDog wild_dog_;
};

int main(int argc, const char** argv) {
  // WildDogAdapter wild_dog_adapter;
  // Lion* lion;
  // lion = &wild_dog_adapter;
  
  Hunter hunter;
  hunter.Hunt(new WildDogAdapter);
}
