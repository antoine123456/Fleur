// flowershop.cpp

#include "Flower_shop.h"

#include <algorithm>
#include <iostream>

using namespace std;

/// @brief Constructeur de la classe magasin de fleurs
FlowerShop::FlowerShop() : age_(4) {}

void FlowerShop::add_bouquet(const Bouquet &bouquet)
{
    bouquets_.push_back(bouquet);
}

void FlowerShop::sell_bouquet(const Bouquet &bouquet)
{
    int id = bouquet.get_id();
    bouquets_.erase(remove_if(bouquets_.begin(), bouquets_.end(), [&id](const Bouquet &b)
                              { return b.get_id() == id; }),
                    bouquets_.end());
    sold_bouquets_.push_back(bouquet);
}

void FlowerShop::mark_as_expired(Bouquet &bouquet)
{
    bouquet.set_price(bouquet.price() * 0.5); // Mettre en solde à 50%
}

const std::vector<Bouquet> &FlowerShop::bouquets() const
{
    return bouquets_;
}

const std::vector<Bouquet> &FlowerShop::sold_bouquets() const
{
    return sold_bouquets_;
}

void FlowerShop::cycle()
{
    for (Bouquet &bouquet : bouquets_)
    {
        bouquet.age();
        age_++;
        // Vérification si le bouquet doit être mis en solde
        int tmpAge = bouquet.expiration_date();
        if (tmpAge < age_)
        {
            mark_as_expired(bouquet);
        }
    }
}

void FlowerShop::__repr__()
{
    int tmpAvaLen = bouquets_.size();
    if (tmpAvaLen > 0)
    {
        cout << "Nombre de bouquets disponibles : " << tmpAvaLen << endl;
        for (Bouquet &bouquet : bouquets_)
        {
            bouquet.__repr__();
        }
    }
    int tmpSellLen = sold_bouquets_.size();
    if (tmpSellLen > 0)
    {
        cout << "Nombre de bouquets vendus : " << tmpSellLen << endl;
        for (Bouquet &bouquet : sold_bouquets_)
        {
            bouquet.__repr__();
        }
    }
}