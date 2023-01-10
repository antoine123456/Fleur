// bouquet.cpp
#include <climits>
#include <iostream>

using namespace std;

#include "bouquet.h"

/// @brief Constructeur de la classe bouquet
/// @param flowers {vector<Flower>} fleurs contenues dans le Bouquet
/// @param price {float} prix du bouquet
/// @param timeToMake {int} temps de fabrication
/// @param id {int} identificateur
/// @param expirationDate {int} date d'expiration (-1 pour la fleur la plus courte echeance)
Bouquet::Bouquet(const std::vector<Flower> &flowers, float price,
                 int timeToMake, int id, int expirationDate)
    : flowers_(flowers),
      price_(price),
      timeToMake_(timeToMake),
      expirationDate_(expirationDate),
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
const std::vector<Flower> &Bouquet::get_flowers() const
{
  return flowers_;
}

/// @brief Renvoit le prix du Bouquet
/// @return price {float}
float Bouquet::get_price() const
{
  return price_;
}

/// @brief Renvoit le temps de confection du bouquet
/// @return timeToMake {int}
int Bouquet::get_timeToMake() const
{
  return timeToMake_;
}

/// @brief Renvoit l'identificateur du bouquet
/// @return id {int}
int Bouquet::get_id() const
{
  return id_;
}

/// @brief Determine la date d'expiration du bouquet à partir des durees de vie des fleurs
/// @tparam {private}
void Bouquet::calcExpDate()
{
  int expiTmp = INT_MAX;
  for (Flower &flower : flowers_)
  {
    int lifeTmp = flower.get_lifetime();
    if (lifeTmp < expiTmp)
    {
      expiTmp = lifeTmp;
    }
  }
  expirationDate_ = expiTmp;
}

/// @brief Renvoit la date d'expiration du Bouquet
/// @return expirationDate {int}
int Bouquet::get_expirationDate()
{
  if (expirationDate_ < 0)
    calcExpDate();
  return expirationDate_;
}

/// @brief Change le prix du bouquet
/// @param price {int} Prix du bouquet
void Bouquet::set_price(int price)
{
  price_ = price;
}

/// @brief Présente le bouquet
void Bouquet::__repr__()
{
  cout << "Nombre de fleurs(s) du bouquet : " << flowers_.size() << endl;
  cout << "Prix du bouquet : " << price_ << endl;
  cout << "Temps de fabrication du bouquet : " << timeToMake_ << endl;
  cout << "Expiration du bouquet : " << expirationDate_ << endl;
  cout << " ___Composition___" << endl;
  for (Flower &flower : flowers_)
  {
    flower.__repr__();
  }
}