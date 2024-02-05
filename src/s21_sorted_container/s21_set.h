#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

#include "../s21_sequential_container/s21_vector.h"
#include "binary_tree.h"

namespace s21 {
template <class Key>
class set : public BTree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BTree<Key, Key>::iterator;
  using const_iterator = typename BTree<Key, Key>::const_iterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Key>::Node;

  set() : BTree<Key, Key>(){};
  set(std::initializer_list<value_type> const &items);
  set(const set &s) : BTree<Key, Key>(s){};
  set(set &&s) = default;
  ~set() = default;

  std::pair<iterator, bool> insert(const_reference value);

  template <class... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
};

template <class Key>
set<Key>::set(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); i++)
    BTree<Key, Key>::BTInsert(*i, *i);
}

template <class Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const_reference value) {
  std::pair<iterator, bool> return_value;
  Node *insert_node = BTree<Key, Key>::BTInsert(value, value);
  return_value.first = iterator(insert_node);
  return_value.second = (insert_node != nullptr);
  return return_value;
}

template <class Key>
template <class... Args>
s21::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args &&...args) {
  s21::vector<std::pair<iterator, bool>> insert_results{};
  for (const auto &arg : {args...}) insert_results.push_back(insert(arg));
  return insert_results;
}
}  // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
