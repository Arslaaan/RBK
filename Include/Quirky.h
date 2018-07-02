#pragma once

#include <vector>

class Quirky: public Merchant{
  std::vector<Decision> first_deals;
  bool trust;
  Decision last_opponent_step;
  bool its_fifth_deal;
public:
  Quirky(std::string c) : Merchant(c) {
    first_deals.push_back(fair);
    first_deals.push_back(fair);
    first_deals.push_back(unfair);
    first_deals.push_back(fair);
    trust = true;
    its_fifth_deal = true;
    last_opponent_step = fair;
  };

  Decision getDecision(){
    if(!first_deals.empty()){
      Decision tmp = first_deals.back();
      first_deals.pop_back();
      return tmp;
    }
    else{
      if (trust){
        if(its_fifth_deal){
          its_fifth_deal = false;
          return fair;
        }
        return last_opponent_step;
      }
      else{
        return unfair;
      }
    }
  }

  void Analyze(Decision t){
    if(t == unfair)
      trust = false;
    last_opponent_step = t;
  }

  void Refresh(){
    trust = true;
    last_opponent_step = fair;
    its_fifth_deal = true;
    first_deals.push_back(fair);
    first_deals.push_back(fair);
    first_deals.push_back(unfair);
    first_deals.push_back(fair);
  }

};
