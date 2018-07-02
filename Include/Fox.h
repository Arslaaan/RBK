#pragma once

class Fox: public Merchant{
  bool first_deal;
  Decision last_opponent_step;
public:
  Fox(std::string c) : Merchant(c) {
    first_deal = true;
    last_opponent_step = fair;
  };

  Decision getDecision(){
    if(first_deal){
      first_deal = false;
      return fair;
    }
    else
      return last_opponent_step;
  }

  void Analyze(Decision t){
    last_opponent_step = t;
  }

  void Refresh(){
    first_deal = true;
  }

};
