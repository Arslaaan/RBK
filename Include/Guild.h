#pragma once

#include "Merchant.h"
#include "Altruist.h"
#include "Rogue.h"
#include "Fox.h"
#include "Quirky.h"
#include "Spiteful.h"
#include "Unpredictable.h"
#include <vector>
#include <cmath>

//класс Гильдия
class Guild{
  //собственно гильдия
  std::vector<Merchant*> guild;
public:
  //задает размер гильдии и создает равное количество всех видов торговцев
  Guild(int size);
  //добавляет к гильдии part торговцев со стратегией str
  void AddtoGuild(int part,std::string str);
  //каждый торгует с каждым
  void AllTrade();
  //удаляет 20% гильдии с наихудшей прибылью за текущий год
  //добавляет новых членов гильдии со стратегией как у лучших
  //итоговый размер  - 60 торговцев
  void ReorganizeGuild();
  //выполняется 5-10 сделок между x и y
  void Trade(Merchant* x,Merchant* y);
  //здесь реализована возможность ошибиться с вероятностью 5%
  void ErrorHappens(Decision& dx);
  //сортирует гильдию по золоту для печати
  void SortforGold();
  //печать всех членов гильдии
  void PrintGuild();
};
