#pragma once

class Rogue: public Merchant{
public:
  Rogue(std::string c) : Merchant(c) {};

  Decision getDecision(){
    return unfair;
  }

};
