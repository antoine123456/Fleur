// bouquet.cpp
#include <climits>
#include <iostream>

using namespace std;

#include "bouquet.h"

/// @brief Constructeur de la classe bouquet
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

/// @brief Renvoit les fleurs contenues dans le bouquet
/// @return flowers {vector<Flower>}
const std::vector<Flower> &Bouquet::flowers() const
{
  return flowers_;
}

/// @brief Renvoit le prix du Bouquet
/// @return price {float}
float Bouquet::price() const
{
  return price_;
}

/// @brief Renvoit le temps de confection du bouquet
/// @return time_to_make {int}
int Bouquet::time_to_make() const
{
  return time_to_make_;
}

/// @brief Renvoit l'identificateur du bouquet
/// @return id {int}
int Bouquet::get_id() const
{
  return id_;
}


/// @brief Determine la date d'expiration du bouquet à partir des durees de vie des fleurs
/// @tparam {private}
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

/// @brief Renvoit la date d'expiration du Bouquet
/// @return expiration_date {int}
int Bouquet::expiration_date()
{
  if (expiration_date_ < 0) calc_exp_date();
  return expiration_date_;
}

/// @brief Change le prix du bouquet
/// @param price {int} Prix du bouquet
void Bouquet::set_price(int price){
  price_ = price;
}

/// @brief Présente le bouquet
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