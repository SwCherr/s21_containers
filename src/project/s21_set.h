#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

#include "binary_tree.h"

namespace s21 {
// class SetContainer {}; // общий класс для множеств
// class Multiset: public SetContainer {}; // допка - заглушка

template<class Key>
class set: public BinaryTree<Key, Key> {
public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<Key, Key>::iterator;
  using const_iterator = typename BinaryTree<Key, Key>::const_iterator;
  using size_type = size_t;

  set() : BinaryTree<Key, Key>() {};
  set(std::initializer_list<value_type> const &items);
  set(const set &s) : BinaryTree<Key, Key>(s) {};           // copy constructor
  set(set &&s) : BinaryTree<Key, Key>(s) {};                // move constructor
  ~set() = default;
  set& operator=(set &&s);

  std::pair<iterator, bool> insert(const value_type& value);
private:
};

template<class Key>
set<Key>::set(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BinaryTree<Key, Key>::Insert(*i, *i);
}

template <class Key>
set<Key>& set<Key>::operator=(set &&s) {
  if (this != &s)
    BinaryTree<Key, Key>::operator=(std::move(s));
  return *this;
}

template <class Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(const value_type& value) {
  return BinaryTree<Key, Key>::Insert(value, value);
}
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
