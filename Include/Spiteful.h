#pragma once

class Spiteful: public Merchant{
  bool trust;
public:
  Spiteful(std::string c) : Merchant(c) {
    trust = true;
  };

  Decision getDecision(){
    if (trust)
      return fair;
    else
      return unfair;
  }

  void Analyze(Decision t){
    if (t == unfair)
      trust = false;
  }

  void Refresh(){
    trust = true;
  }

};
