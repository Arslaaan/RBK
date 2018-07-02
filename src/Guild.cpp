#include "Guild.h"

int num_characters = 6;

Guild::Guild(int size){
  int part = size / num_characters;
  AddtoGuild(part,"Altruist");
  AddtoGuild(part,"Rogue");
  AddtoGuild(part,"Fox");
  AddtoGuild(part,"Unpredictable");
  AddtoGuild(part,"Spiteful");
  AddtoGuild(part,"Quirky");
}

void Guild::AddtoGuild(int part,std::string str){
  for(int i = 0;i < part;++i){
    Merchant* x;
    if (str == "Altruist")
        x = new Altruist(str);
    if (str == "Rogue")
        x = new Rogue(str);
    if (str == "Fox")
        x = new Fox(str);
    if (str == "Unpredictable")
        x = new Unpredictable(str);
    if (str == "Spiteful")
        x = new Spiteful(str);
    if (str == "Quirky")
        x = new Quirky(str);
    guild.push_back(x);
  }
}

void Guild::AllTrade(){
  for(unsigned i = 0;i < guild.size();++i){
    for(unsigned j = i + 1;j < guild.size();++j){
      Trade(guild[i],guild[j]);
    }
  }
}

void Guild::ReorganizeGuild(){
  //PrintGuild();
  for(unsigned i = 0;i < guild.size();++i)
    for(unsigned j = i+1;j < guild.size();++j)
      if(guild[i]->getYearIncome() > guild[j]->getYearIncome())
        std::swap(guild[i],guild[j]);
  //PrintGuild();
  float percent = 0.2;
  int delete_size = floor(percent * guild.size());
  guild.erase(guild.begin(),guild.begin() + delete_size);
  for(unsigned i = 0;i < guild.size();++i){
    guild[i]->setGoldLastYear(guild[i]->getGold());
  }
  //PrintGuild();
  unsigned start_size = guild.size();
  for(int j = 0; j < delete_size;++j){
    AddtoGuild(1,guild[start_size - 1 - j]->getCharacter());
  }
  //PrintGuild();
}

void Guild::Trade(Merchant* x,Merchant* y){
  int num_deals = rand() % 6 + 5;
  for(int i = 0; i < num_deals;++i){
    Decision dx = x->getDecision();
    Decision dy = y->getDecision();
    ErrorHappens(dx);
    ErrorHappens(dy);
    if(dx == dy){
      if(dx == fair){
        x->AddGold(4);
        y->AddGold(4);
      }
      else{
        x->AddGold(2);
        y->AddGold(2);
      }
    }
    else{
      if(dx == fair){
        x->AddGold(1);
        y->AddGold(5);
      }
      else{
        y->AddGold(1);
        x->AddGold(5);
      }
    }
    x->Analyze(dy);
    y->Analyze(dx);
  }
  x->Refresh();
  y->Refresh();
}

void Guild::ErrorHappens(Decision& dx){
  int rnd = rand() % 100;
  if((rnd >= 95) && (rnd <= 99)){
    if(dx == fair)
      dx = unfair;
    else
      dx = fair;
  }
}

void Guild::SortforGold(){
  for(unsigned i = 0;i < guild.size();++i)
    for(unsigned j = i+1;j < guild.size();++j)
      if(guild[i]->getGold() > guild[j]->getGold())
        std::swap(guild[i],guild[j]);
}

void Guild::PrintGuild(){
  std::cout << "------------------------" << '\n';
  std::cout<< "  size guild = " << guild.size()<<std::endl;
  for(unsigned i = 0; i < guild.size(); ++i)
    guild[i]->PrintMerchant();
}
