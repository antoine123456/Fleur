// bouquet.cpp
#include <climits>
#include <iostream>

using namespace std;

#include "bouquet.h"

/// @brief Implémentation de la classe bouquet
/// @param flowers {vector<Flower>} fleurs contenues dans le Bouquet
/// @param price {float} prix du bouquet
/// @param time_to_make {int} temps de fabrication
/// @param id {int} identificateur
/// @param expiration_date {int} date d'expiration (-1 pour la fleur la plus courte echeance)
Bouquet::Bouquet(const std::vector<Flower> &flowers, float price,
                 int time_to_make, int id,int expiration_date)
    : flowers_(flowers),
      price_(price),
      time_to_make_(time_to_make),
      expiration_date_(expiration_date),
      id_(id)
{
}

/// @brief Viellissement des fleurs du Bouquet selon la methode 'age' de la classe 'fleur'
void Bouquet::age()
{
  for (Flower &flower : flowers_)
  {
    flower.age();
  }
}

/// @brief Fleurs contenues dans le bouquet
/// @return flowers {vector<Flower>}
const std::vector<Flower> &Bouquet::flowers() const
{
  return flowers_;
}

/// @brief Prix du Bouquet
/// @return price {float}
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