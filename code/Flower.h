#ifndef FLOWER_H_
#define FLOWER_H_

#include <string>

/// @brief Implémente la classe fleur
/// @param name {String}
class Flower {
 public:
  Flower(const std::string& name, int age, int lifetime, int id);

  void age();

  const std::string& name() const;

  int age() const;

  int lifetime() const;

  void __repr__();

  int get_id() const;

  private:
  std::string name_;
  int age_;
  int lifetime_;
  int id_;
};

#endif  // FLOWER_H_
