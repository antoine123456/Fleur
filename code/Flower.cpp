#include "Flower.h"
#include <iostream>

using namespace std;

/// @brief Constructeur de la classe fleur
/// @param name {string} Nom de la fleur
/// @param age {int} Age de la fleur
/// @param lifetime {int} Duree de vie de la fleur
/// @param id {int} Identifiant de la fleur
Flower::Flower(const std::string &name, int age, int lifetime, int id) : name_(name), age_(age), lifetime_(lifetime), id_(id) {}

/// @brief Incrémente l'age de la fleur
void Flower::age()
{
  age_++;
}

/// @brief Retourne le nom de la fleur
/// @return name {string}
const std::string &Flower::get_name() const
{
  return name_;
}

/// @brief Retourne l'age de la fleur
/// @return age {int}
int Flower::get_age() const
{
  return age_;
}

/// @brief Retourne la durée de vie de la fleur
/// @return lifetime
int Flower::get_lifetime() const
{
  return lifetime_;
}

/// @brief Retourne l'Identifiant
/// @return id
int Flower::get_id() const
{
  return id_;
}

/// @brief Présente la fleur
void Flower::__repr__()
{
  cout << " - Nom de la fleur : " << name_ << endl;
  cout << " - Age de la fleur : " << age_ << endl;
  cout << " - Durée de vie de la fleur : " << lifetime_ << endl;
}