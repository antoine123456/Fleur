// flowershop.h

#ifndef FLOWERSHOP_H_
#define FLOWERSHOP_H_

#include <vector>

#include "Bouquet.h"

class FlowerShop {
 public:
  FlowerShop();

   void add_bouquet(const Bouquet &bouquet);

   void sell_bouquet(const Bouquet &bouquet);

   void mark_as_expired(Bouquet &bouquet);

   const std::vector<Bouquet> &bouquets() const;

   const std::vector<Bouquet> &sold_bouquets() const;

   void cycle();

   void __repr__();

   ~Flower_shop(){}

 private:
   std::vector<Bouquet> bouquets_;
   std::vector<Bouquet> sold_bouquets_;
   int age_;
};

#endif 
