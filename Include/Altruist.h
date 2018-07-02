#pragma once

class Altruist: public Merchant{
public:
  Altruist(std::string c) : Merchant(c) {};

  Decision getDecision(){
    return fair;
  }

};
