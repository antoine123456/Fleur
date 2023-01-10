// bouquet.h

#ifndef BOUQUET_H_
#define BOUQUET_H_

#include <vector>

#include "flower.h"

/// @brief Implémente la classe Bouquet
/// @param flowers {vector<Flower>} fleurs composant le bouquet
/// @param price {int} prix du bouquet
/// @param timeToMake {int} temps de fabrication du bouquet
/// @param id {int} identificateur du bouquet
/// @param expirationDate {int} date d'expiration du bouquet
class Bouquet
{
public:
    Bouquet(const std::vector<Flower> &flowers, float price, int timeToMake, int id, int expirationDate);

    void age();

    const std::vector<Flower> &get_flowers() const;

    float get_price() const;

    void set_price(int price);

    int get_timeToMake() const;

    int get_expirationDate();

    int get_id() const;

    void __repr__();

    ~Bouquet(){};

private:
/// @brief flowers_ {vector<Flower>} fleurs composant le bouquet
    std::vector<Flower> flowers_;
/// @brief price_ {int} prix du bouquet
    float price_;
/// @brief timeToMake_ {int} temps de fabrication du bouquet
    int timeToMake_;
/// @brief id_ {int} identificateur du bouquet
    int id_;
/// @brief expirationDate_ {int} date d'expiration du bouquet
    int expirationDate_;
    void calcExpDate();
};

#endif // BOUQUET_H_
