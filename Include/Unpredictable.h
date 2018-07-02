#pragma once

class Unpredictable: public Merchant{
public:
  Unpredictable(std::string c) : Merchant(c) {};

  Decision getDecision(){
    if (rand() % 2 == 0)
      return fair;
    return unfair;
  }

};
