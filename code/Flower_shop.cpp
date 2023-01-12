// Flower_Shop.cpp

#include "Flower_Shop.h"

#include <algorithm>
#include <iostream>

using namespace std;

/// @brief Constructeur de la classe magasin de fleurs
/// @param age {int} Temps de vie du magasin
/// @deprecated Initialise l'age à 4 pour la démo
Flower_Shop::Flower_Shop() : age_(4) {}

/// @brief Ajoute un bouquet au magasin de fleurs, (ajoute un bouquet au vecteur des bouquets en vente)
/// @param bouquet {Bouquet} Bouquet à ajouter au magasin de fleurs
void Flower_Shop::add_bouquet(const Bouquet &bouquet)
{
    bouquets_.push_back(bouquet);
}

/// @brief Vente d'un bouquet par le magasin de fleurs (ajoute le bouquet au vecteur des bouquets vendus et supprime des bouquets en vente)
/// @param bouquet {Bouquet} Bouquet à vendre
void Flower_Shop::sell_bouquet(const Bouquet &bouquet)
{
    int id = bouquet.get_id();
    bouquets_.erase(remove_if(bouquets_.begin(), bouquets_.end(), [&id](const Bouquet &b)
                              { return b.get_id() == id; }),
                    bouquets_.end());
    soldBouquets_.push_back(bouquet);
}

/// @brief Passage de la date d'expiration du bouquet
/// @param bouquet {Bouquet} Bouquet arrivé â expiration
void Flower_Shop::mark_as_expired(Bouquet &bouquet)
{
    bouquet.set_price(bouquet.get_price() * 0.5); // Mettre en solde à 50%
}

/// @brief Retourne les bouquets en vente au magasin de fleurs
/// @return bouquets {vector<Bouquet>}
const std::vector<Bouquet> &Flower_Shop::get_bouquets() const
{
    return bouquets_;
}

/// @brief Retourne les bouquet vendus par le magasin de fleurs
/// @return sold_bouquets {vector<Bouquet>}
const std::vector<Bouquet> &Flower_Shop::get_soldBouquets() const
{
    return soldBouquets_;
}

/// @brief Fonctionnement du magasin de fleur (passage du temps et soldage en consequence)
void Flower_Shop::perf_cycle()
{
    for (Bouquet &bouquet : bouquets_)
    {
        bouquet.age();
        age_++;
        // Vérification si le bouquet doit être mis en solde
        int tmpAge = bouquet.get_expirationDate();
        if (tmpAge < age_)
        {
            mark_as_expired(bouquet);
        }
    }
}

/// @brief Présente le magasin de fleurs
void Flower_Shop::__repr__()
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
    int tmpSellLen = soldBouquets_.size();
    if (tmpSellLen > 0)
    {
        cout << "Nombre de bouquets vendus : " << tmpSellLen << endl;
        for (Bouquet &bouquet : soldBouquets_)
        {
            bouquet.__repr__();
        }
    }
}