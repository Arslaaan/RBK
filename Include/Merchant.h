#pragma once

#include <string>
#include <iostream>

//решение торговать честно или нет
enum Decision{
  fair,
  unfair
};

//класс Торговец
//от него наследуются все стратегии поведения
class Merchant{
  std::string name_class;//хранится имя класса,нужно для печати
  int gold;//золото,накопленное за все время
  int gold_in_last_year;//золото,накопленное к концу предыдущего хода
public:
  Merchant(std::string c);

  //выдает решение торговца(fair или unfair)
  virtual Decision getDecision();
  //анализирует решение оппонента
  virtual void Analyze(Decision t);
  //после завершения 5-10 сделок с некоторым торговцем
  //нужно восстановить исходные параметры,перед торговлей со следующим
  virtual void Refresh();
  //печать стратегии и золота этого торговца
  void PrintMerchant();
  //возвращает имя класса
  std::string getCharacter();
  //возвращает золото
  int getGold();
  //добавляет золото после сделки
  void AddGold(int g);
  //устанавливает значение gold_in_last_year
  void setGoldLastYear(int g);
  //выдает прибыль за текущий год
  int getYearIncome();

  virtual ~Merchant();

};
