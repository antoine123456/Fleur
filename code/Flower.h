#ifndef FLOWER_H_
#define FLOWER_H_

#include <string>

/// @brief Implémente la classe fleur
/// @param name {string} nom de la fleur
/// @param age {int} age de la fleur
/// @param lifetime {int} durée de vie de la fleur
/// @param id {int} identificateur de la fleur
class Flower
{
public:
  Flower(const std::string &name, int age, int lifetime, int id);

  void age();

  const std::string &get_name() const;

  int get_age() const;

  int get_lifetime() const;

  void __repr__();

  int get_id() const;

  ~Flower(){};
private:
/// @brief  name_ {string} nom de la fleur
  std::string name_;
/// @brief age_ {int} age de la fleur
  int age_;
/// @brief lifetime_ {int} durée de vie de la fleur
  int lifetime_;
/// @brief id_ {int} identificateur de la fleur
  int id_;
};

#endif // FLOWER_H_