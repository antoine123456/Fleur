// flowershop.cpp

#include "Flower_shop.h"

#include <algorithm>
#include <iostream>

using namespace std;

/// @brief Constructeur de la classe magasin de fleurs
/// @deprecated Initialise l'age à 4 pour la démo
FlowerShop::FlowerShop() : age_(4) {}

/// @brief Ajoute un bouquet au magasin de fleurs, au vecteur des bouquets en vente
/// @param bouquet {Bouquet} Bouquet à ajouter au magasin de fleurs
void FlowerShop::add_bouquet(const Bouquet &bouquet)
{
    bouquets_.push_back(bouquet);
}

/// @brief Vente d'un bouquet par le magasin de fleurs, ajoute le bouquet au vecteur des bouquets vendus et supprime des bouquets en vente
/// @param bouquet {Bouquet} Bouquet à vendre
void FlowerShop::sell_bouquet(const Bouquet &bouquet)
{
    int id = bouquet.get_id();
    bouquets_.erase(remove_if(bouquets_.begin(), bouquets_.end(), [&id](const Bouquet &b)
                              { return b.get_id() == id; }),
                    bouquets_.end());
    sold_bouquets_.push_back(bouquet);
}

/// @brief Passage de la date d'expiration du bouquet
/// @param bouquet {Bouquet} Bouquet arrivé â expiration
void FlowerShop::mark_as_expired(Bouquet &bouquet)
{
    bouquet.set_price(bouquet.price() * 0.5); // Mettre en solde à 50%
}

/// @brief Retourne les bouquets en vente au magasin de fleurs
/// @return bouquets {vector<Bouquet>}
const std::vector<Bouquet> &FlowerShop::bouquets() const
{
    return bouquets_;
}

/// @brief Retourne les bouquet vendus par le magasin de fleurs
/// @return sold_bouquets {vector<Bouquet>}
const std::vector<Bouquet> &FlowerShop::sold_bouquets() const
{
    return sold_bouquets_;
}

/// @brief Fonctionnement du magasin de fleur (passage du temps et soldage en consequence)
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

/// @brief Présente le magasin de fleurs
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