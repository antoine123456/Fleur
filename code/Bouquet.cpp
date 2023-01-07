// bouquet.cpp
#include <climits>
#include <iostream>

using namespace std;

#include "bouquet.h"

Bouquet::Bouquet(const std::vector<Flower> &flowers, float price,
                 int time_to_make, int id,int expiration_date)
    : flowers_(flowers),
      price_(price),
      time_to_make_(time_to_make),
      expiration_date_(expiration_date),
      id_(id)
{
}

void Bouquet::age()
{
  for (Flower &flower : flowers_)
  {
    flower.age();
  }
}

const std::vector<Flower> &Bouquet::flowers() const
{
  return flowers_;
}

float Bouquet::price() const
{
  return price_;
}

int Bouquet::time_to_make() const
{
  return time_to_make_;
}

int Bouquet::get_id() const
{
  return id_;
}

void Bouquet::calc_exp_date()
{
  int expiTmp = INT_MAX;
  for (Flower &flower : flowers_)
  {
    int lifeTmp = flower.lifetime();
    if (lifeTmp < expiTmp)
    {
      expiTmp = lifeTmp;
    }
  }
  expiration_date_ = expiTmp;
}

int Bouquet::expiration_date()
{
  if (expiration_date_ < 0)
    {
    cout << "\n calc viellissement \n" << endl;
    calc_exp_date();}
  return expiration_date_;
}

void Bouquet::set_price(int price){
  price_ = price;
}

void Bouquet::__repr__()
{
  cout << "Nombre de fleurs(s) du bouquet : " << flowers_.size() << endl;
  cout << "Prix du bouquet : " << price_ << endl;
  cout << "Temps de fabrication du bouquet : " << time_to_make_ << endl;
  cout << "Expiration du bouquet : " << expiration_date_ << endl;
  cout << " ___Composition___" << endl;
  for (Flower &flower : flowers_)
  {
    flower.__repr__();
  }
}