#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

#include "binary_tree.h"

namespace s21 {
// class SetContainer {}; // общий класс для множеств
// class Multiset: public SetContainer {}; // допка - заглушка

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

  set() : BTree<Key, Key>() {};
  set(std::initializer_list<value_type> const &items);
  set(const set &s) : BTree<Key, Key>(s) {};           // copy constructor
  set(set &&s) = default;                                   // move constructor
  ~set() = default;
  set& operator=(set &&s);

  // iterator find(const Key key);
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
  return BTree<Key, Key>::Insert(value, value);
}
} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
