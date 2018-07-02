#include "Merchant.h"

Merchant::Merchant(std::string c){
    gold = 0;
    gold_in_last_year = 0;
    name_class = c;
}

Decision Merchant::getDecision(){
    return fair;
}

void Merchant::Analyze(Decision t){};

void Merchant::Refresh(){};

void Merchant::PrintMerchant(){
    std::cout << "Merchant with character " << getCharacter();
    std::cout << " gold earned: " << gold << '\n';
}

std::string Merchant::getCharacter(){
    return name_class;
}

int Merchant::getGold(){
    return gold;
}

void Merchant::AddGold(int g){
    gold += g;
  }

void Merchant::setGoldLastYear(int g){
    gold_in_last_year = g;
}

int Merchant::getYearIncome(){
    return gold - gold_in_last_year;
}

Merchant::~Merchant(){};
