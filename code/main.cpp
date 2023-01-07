#include <ctime>
#include <iostream>

#include "Flower.h"
#include "Bouquet.h"
#include "Flower_shop.h"

using namespace std;

int main()
{
  // Création d'une rose et d'un bouquet de roses
  Flower rose("Rose", 0, 5, 1);

  Bouquet bouquet({rose}, 10, 30, 1, -1);

  // Création d'un magasin de fleurs
  FlowerShop flower_shop;

  // Ajout du bouquet de roses au magasin
  flower_shop.add_bouquet(bouquet);

  // Une age s'écoule
  flower_shop.cycle();

  flower_shop.__repr__();
  cout << "===========" << endl;

  // Une age s'écoule
  flower_shop.cycle();

  flower_shop.__repr__();
  cout << "===========" << endl;

  // Vente du bouquet
  flower_shop.sell_bouquet(flower_shop.bouquets()[0]);
  flower_shop.__repr__();
  cout << "===========" << endl;

  return 0;
}