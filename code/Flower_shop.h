// Flower_Shop.h

#ifndef Flower_Shop_H_
#define Flower_Shop_H_

#include <vector>

#include "Bouquet.h"

/// @brief Implémente la classe Flower_Shop
/// @param bouquets {vector<Flower>} bouquets disponibles dans le magasin
/// @param soldBouquets {vector<Flower>} bouquets vendues par magasin
class Flower_Shop
{
public:
  Flower_Shop();

  void add_bouquet(const Bouquet &bouquet);

  void sell_bouquet(const Bouquet &bouquet);

  void mark_as_expired(Bouquet &bouquet);

  const std::vector<Bouquet> &get_bouquets() const;

  const std::vector<Bouquet> &get_soldBouquets() const;

  void perf_cycle();

  void __repr__();

  ~Flower_Shop(){};

private:
  /// @brief  bouquets_ {vector<Flower>} bouquets disponibles dans le magasin
  std::vector<Bouquet> bouquets_;
  /// @brief soldBouquets_ {vector<Flower>} bouquets vendues par magasin
  std::vector<Bouquet> soldBouquets_;
  /// @brief age_ {int} Temps de vie du magasin
  int age_;
};

#endif
