// flowershop.h

#ifndef FLOWERSHOP_H_
#define FLOWERSHOP_H_

#include <vector>

#include "Bouquet.h"

/// @brief Implémente la classe magasin de fleur
/// @param bouquets {vector<Flower>} bouquets disponibles dans le magasin
/// @param soldBouquets {vector<Flower>} bouquets vendues par magasin
class FlowerShop
{
public:
  FlowerShop();

  void add_bouquet(const Bouquet &bouquet);

  void sell_bouquet(const Bouquet &bouquet);

  void mark_as_expired(Bouquet &bouquet);

  const std::vector<Bouquet> &get_bouquets() const;

  const std::vector<Bouquet> &get_soldBouquets() const;

  void perf_cycle();

  void __repr__();

  ~FlowerShop(){};

private:
  /// @brief  bouquets_ {vector<Flower>} bouquets disponibles dans le magasin
  std::vector<Bouquet> bouquets_;
  /// @brief soldBouquets_ {vector<Flower>} bouquets vendues par magasin
  std::vector<Bouquet> soldBouquets_;
  /// @brief age_ {int} Temps de vie du magasin
  int age_;
};

#endif
