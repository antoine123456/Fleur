#include <ctime>
#include <iostream>

#include "Flower.h"
#include "Bouquet.h"
#include "Flower_Shop.h"

using namespace std;

int main()
{
  // Création d'une rose et d'un bouquet de roses
  Flower rose("Rose", 0, 5, 1);

  Bouquet bouquet({rose}, 10, 30, 1, -1);

  // Création d'un magasin de fleurs
  Flower_Shop Flower_Shop;

  // Ajout du bouquet de roses au magasin
  Flower_Shop.add_bouquet(bouquet);

  // Une age s'écoule
  Flower_Shop.perf_cycle();

  Flower_Shop.__repr__();
  cout << "===========" << endl;

  // Une age s'écoule
  Flower_Shop.perf_cycle();

  Flower_Shop.__repr__();
  cout << "===========" << endl;

  // Vente du bouquet
  Flower_Shop.sell_bouquet(Flower_Shop.get_bouquets()[0]);
  Flower_Shop.__repr__();
  cout << "===========" << endl;

  return 0;
}