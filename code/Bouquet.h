// bouquet.h

#ifndef BOUQUET_H_
#define BOUQUET_H_

#include <vector>
#include <ctime>

#include "flower.h"

/// @brief Implémente la classe Bouquet
class Bouquet
{
public:
    Bouquet(const std::vector<Flower> &flowers, float price, int time_to_make, int id,int expiration_date);

    void age();

    const std::vector<Flower> &flowers() const;

    float price() const;

    void set_price(int price);

    int time_to_make() const;

    int expiration_date();

    int get_id() const;

    void __repr__();

    ~Bouquet(){};

private:
    std::vector<Flower> flowers_;
    float price_;
    int time_to_make_;
    int expiration_date_;
    int id_;
    void calc_exp_date();
};

#endif // BOUQUET_H_
