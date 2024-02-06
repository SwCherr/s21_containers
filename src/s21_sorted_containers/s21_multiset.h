#ifndef CPP2_S21_CONTAINERS_SRC_S21_SORTED_CONTAINERS_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_SRC_S21_SORTED_CONTAINERS_S21_MULTISET_H_

#include <cstddef>
#include <initializer_list>
#include <utility>

#include "../s21_sequental_containers/s21_vector.h"
#include "binary_tree.h"

namespace s21 {
template <class Key>
class multiset : public BTree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BTree<Key, Key>::iterator;
  using const_iterator = typename BTree<Key, Key>::const_iterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Key>::Node;

  multiset() : BTree<Key, Key>(){};
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &s) : BTree<Key, Key>(s){};
  multiset(multiset &&s) = default;
  ~multiset() = default;

  std::pair<iterator, bool> insert(const_reference value);
  size_type count(const_reference key) const;
  std::pair<iterator, iterator> equal_range(const_reference key) const;
  iterator lower_bound(const_reference key) const;
  iterator upper_bound(const_reference key) const;

  template <class... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
};

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); i++) insert(*i);
}

template <class Key>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::insert(
    const_reference value) {
  std::pair<iterator, bool> return_value;
  Node **cur = &(BTree<Key, Key>::root_);
  Node *parent = nullptr;
  while (*cur) {
    Node &node = **cur;
    parent = *cur;
    if (value <= node.Key)
      cur = &node.Left;
    else if (value > node.Key)
      cur = &node.Right;
  }
  *cur = new Node(value, value);
  return_value.first = iterator(*cur);
  return_value.second = (*cur != nullptr);
  if (*cur) (*cur)->Parent = parent;
  return return_value;
}

template <class Key>
typename multiset<Key>::size_type multiset<Key>::count(
    const_reference key) const {
  int count = 0;
  for (auto cur = BTree<Key, Key>::begin(); cur != BTree<Key, Key>::end();
       ++cur) {
    if (key == *cur) ++count;
  }
  return count;
}

template <class Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const_reference key) const {
  std::pair<iterator, iterator> return_value;
  auto cur = this->begin();
  while (cur != this->end() && key != *cur) ++cur;
  return_value.first = iterator(cur);
  while (cur != this->end() && key == *cur) {
    return_value.second = iterator(cur);
    ++cur;
  }
  return return_value;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(
    const_reference key) const {
  iterator return_value;
  auto cur = this->begin();
  while (cur != this->end() && key != *cur) ++cur;
  return_value = iterator(cur);
  return return_value;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(
    const_reference key) const {
  iterator return_value;
  auto cur = this->begin();
  while (cur != this->end() && key >= *cur) ++cur;
  return_value = iterator(cur);
  return return_value;
}

template <class Key>
template <class... Args>
vector<std::pair<typename multiset<Key>::iterator, bool>>
multiset<Key>::insert_many(Args &&...args) {
  vector<std::pair<iterator, bool>> insert_results{};
  for (const auto &arg : {args...}) insert_results.push_back(insert(arg));
  return insert_results;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_SORTED_CONTAINERS_S21_MULTISET_H_
