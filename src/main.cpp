#include "Merchant.h"
#include "Guild.h"
#include <ctime>

int main(int argc,char** argv){
  int years = atoi(argv[1]);
  srand(std::time(0));
  Guild guild(60);
  for(int i = 0; i < years;++i){
    guild.AllTrade();
    guild.ReorganizeGuild();
  }
  guild.SortforGold();
  guild.PrintGuild();
  return 0;
}
