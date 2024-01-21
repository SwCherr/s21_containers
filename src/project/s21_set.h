#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

#include "binary_tree.h"

namespace s21 {
template<class Key>
class set: public BTree<Key, Key> {
public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BTree<Key, Key>::iterator;
  using const_iterator = typename BTree<Key, Key>::const_iterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Key>::Node;

  set() : BTree<Key, Key>() {};
  set(std::initializer_list<value_type> const &items);
  set(const set &s) : BTree<Key, Key>(s) {};
  set(set &&s) = default;
  ~set() = default;
  set& operator=(set &&s);
  std::pair<iterator, bool> insert(const value_type& value);
};

template<class Key>
set<Key>::set(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BTree<Key, Key>::Insert(*i, *i);
}

template <class Key>
set<Key>& set<Key>::operator=(set &&s) {
  if (this != &s)
    BTree<Key, Key>::operator=(std::move(s));
  return *this;
}

template <class Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(const value_type& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = BTree<Key, Key>::Insert(value, value);
  if (insert_node) {
    return_value.first = iterator(insert_node);
    return_value.second = true;
  } else {
    return_value.first = iterator(nullptr);
    return_value.second = false;
  }
  return return_value;
}

} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
