#include "Flower.h"
#include <iostream>

using namespace std;

Flower::Flower(const std::string &name, int age, int lifetime, int id) : name_(name), age_(age), lifetime_(lifetime), id_(id) {}

void Flower::age()
{
  age_++;
}

const std::string &Flower::name() const
{
  return name_;
}

int Flower::age() const
{
  return age_;
}

int Flower::lifetime() const
{
  return lifetime_;
}

int Flower::get_id() const
{
  return id_;
}

void Flower::__repr__()
{
  cout << " - Nom de la fleur : " << name_ << endl;
  cout << " - Age de la fleur : " << age_ << endl;
  cout << " - Durée de vie de la fleur : " << lifetime_ << endl;
}